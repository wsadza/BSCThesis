/**
    @File:      FileParser.cpp
    @Purpose:   Parse file to section based on their header.
                Analyze given section and create key = variable structure.    

    @Author:    Igor Sadza
    @Version:   1.0 - 30/01/19
                2.0 - 13/02/19
                3.0 - 17/02/19
                4.0 - 18/02/19
*/

#include "../parsers/FileParser.hpp"

#include <sstream>
#include <fstream>

FileParser::FileParser(const std::string &t_pathToTextFile) {

    std::ifstream fileStream;
    fileStream.open(t_pathToTextFile);

    if (!fileStream) {
     std::cout << "The file cannot be opened: " + t_pathToTextFile  << std::endl;
     exit (EXIT_FAILURE);       
    }
    paraseToSource(fileStream);
}

GLvoid FileParser::paraseToSource(std::ifstream &t_fileStram) {

  HeadSource headSection;

  std::string line;
  std::string section;
  std::string header;

  while (getline(t_fileStram, line)) {

    if (line.length() == 0 || !line.find("//")) {
      continue;
    }
    
    if (line.at(0) == '[') {

      if(section.size() > 0) {
        headSection.m_header = header;
        headSection.m_source = section;
        m_sections.push_back(headSection);

        section.clear();
        header.clear();
      }

      header = getParsedName(line);
      continue;
    }

    section += line + '\n';
  }

  // Check last 
  if (header.size() > 0) {
    headSection.m_header = header;
    headSection.m_source = section;
    m_sections.push_back(headSection);
  }

  t_fileStram.close();  
}

FileParser::Variables FileParser::getParasedVariables(const std::string &t_source) {
    
    std::istringstream stringStream;
    stringStream.str(t_source); 
       
    std::string line;
    Variables keyVarVec;

    while (getline(stringStream, line)) {

      KeyVariable keyVar;
      std::size_t quotSignPos = line.find_first_of('"');

      if (quotSignPos != std::string::npos) {

        for (int i = 0; i < quotSignPos; i++) {
          if (line[i] == ' ') {
            line.erase(line.begin() + i);
          }
        }

        for (int i = 0; i < 2; i++) {
          line.erase(line.begin() + line.find('"'));
        } 

      }
      else {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
              line.erase(line.begin() + i);
            }
        }        
      }

      size_t equalSignPos = line.find_first_of('=');

      if (equalSignPos != std::string::npos) {

        keyVar.m_key = line.substr(0, equalSignPos);
        keyVar.m_variable = line.substr(equalSignPos + 1, line.size());
      }

      keyVarVec.push_back(keyVar);
    }

    return keyVarVec;
}

FileParser::Sections FileParser::getSections() {
  return m_sections;
}

std::string FileParser::getSection(const std::string &t_sectionName) {
  for (auto& ite: m_sections) {
    if (ite.m_header == t_sectionName) {
      return ite.m_source;
    }
  }
  return std::string();
}

std::string FileParser::getParsedName(const std::string &t_textLine) {
  std::string name = t_textLine;
  for (auto &cha : {'[', '/', ']'}) {
    size_t signPos = name.find_last_of(cha);
    if (signPos != std::string::npos) {
      (cha == '/')
      ? name.erase(name.begin(), name.begin() + signPos + 1)
      : name.erase(name.begin() + signPos);
    }
  }
  return name;
}