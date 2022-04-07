/**
    @File:      FileParser.cpp
    @Purpose:   Parse file to section based on their header.
                Analyze given section and create key = variable structure.

    @Author:    Igor Sadza
    @Version:   1.0 - 30/01/19
                2.0 - 13/02/19
                3.0 - 17/02/19
                4.0 - 18/02/19

    @TODO: parseGlobals
*/
#ifndef FILE_PARSER_HPP
#define FILE_PARSER_HPP

#include "../utils/CommonIncludes.hpp"

class FileParser {
private:
  struct HeadSource {
    std::string m_header;
    std::string m_source;
  };

  struct KeyVariable {
    std::string m_key;
    std::string m_variable;
  };

  // For sources from file.
  typedef std::vector<HeadSource> Sections;

  // For variable from sources.
  typedef std::vector<KeyVariable> Variables;
  typedef std::multimap<std::string, Variables> Registry;

  // Variables.
  Sections m_sections;
  std::string m_fileName;

  // Parase file to header and source.
  GLvoid paraseToSource(std::ifstream &t_fileStram);

  // TODO
  // Add global variables to individual section.  
  GLvoid parseGlobals(Variables t_variables);

public:
  FileParser(const std::string &t_pathToTextFile);
  std::string getFileName();

  static Variables getParasedVariables(const std::string &t_source);
  Sections getSections();
  std::string getSection(const std::string &t_sectionName);

  static std::string getParsedName(const std::string &t_textLine);

  template <class Type> 
  static Type parseVariable(std::string t_Variable) {
    Type variable;
    for (int i = 0; i < sizeof(Type) / sizeof(1.0f); i++) {
      size_t commaSiqnPos = t_Variable.find_first_of(',');
      std::string value = t_Variable.substr(0, commaSiqnPos);
      t_Variable = t_Variable.substr(commaSiqnPos + 1, t_Variable.size());
      std::stringstream(value) >> variable[i];
    }
    return variable;
  } 
};

#endif // TEXT_FILE_ARSER_HPP