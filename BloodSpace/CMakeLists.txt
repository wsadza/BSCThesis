project(BloodSpace)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lglfw -ldl -lfreetype")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET (DEPENDENCIES
    ./dependencies/glad.h    
    ./dependencies/glad.c

    ./dependencies/stb_image.h
    ./dependencies/stb_image.cpp

    ./sources/main.cpp
)

SET (UTILS
    ./sources/utils/CommonIncludes.hpp

    ./sources/utils/Settings.hpp
    ./sources/utils/Settings.cpp

    ./sources/utils/SharedResources.hpp
    ./sources/utils/SharedResources.cpp
)

SET (WIDGETS
    ./sources/widgets/BaseWidget.hpp
    ./sources/widgets/BaseWidget.cpp

    ./sources/widgets/ButtonWidget.hpp
    ./sources/widgets/ButtonWidget.cpp

    ./sources/widgets/LabelWidget.hpp
    ./sources/widgets/LabelWidget.cpp
)

SET (STATES
    ./sources/states/BaseState.hpp
    ./sources/states/BaseState.cpp

    ./sources/states/StateExit.hpp
    ./sources/states/StateExit.cpp

    ./sources/states/StateLogo.hpp
    ./sources/states/StateLogo.cpp

    ./sources/states/StateMenu.hpp
    ./sources/states/StateMenu.cpp

    ./sources/states/StatePlay.hpp
    ./sources/states/StatePlay.cpp

    ./sources/states/StatePlayground.hpp
    ./sources/states/StatePlayground.cpp

    ./sources/states/StateSwitcher.hpp
    ./sources/states/StateSwitcher.cpp
)

SET (RENDERERS
    ./sources/renderers/PrimitiveRenderer.hpp
    ./sources/renderers/PrimitiveRenderer.cpp

    ./sources/renderers/TextRenderer.hpp
    ./sources/renderers/TextRenderer.cpp
)

SET (PIECES
    ./sources/pieces/Font.hpp
    ./sources/pieces/Font.cpp

    ./sources/pieces/Image.hpp
    ./sources/pieces/Image.cpp

    ./sources/pieces/Primitive.hpp
    ./sources/pieces/Primitive.cpp

    ./sources/pieces/Shader.hpp
    ./sources/pieces/Shader.cpp

    ./sources/pieces/Text.hpp
    ./sources/pieces/Text.cpp
) 

SET (PARSERS
    ./sources/parsers/FileParser.hpp
    ./sources/parsers/FileParser.cpp
)

SET (OBJECTS

    ./sources/objects/BaseObject.hpp
    ./sources/objects/BaseObject.cpp

    ./sources/objects/CursorObject.hpp
    ./sources/objects/CursorObject.cpp

    ./sources/objects/CreatureObject.hpp
    ./sources/objects/CreatureObject.cpp

    ./sources/objects/PlayerObject.hpp
    ./sources/objects/PlayerObject.cpp

    ./sources/objects/objectsUtils/ObjectMotion.hpp
    ./sources/objects/objectsUtils/ObjectShot.hpp
    ./sources/objects/objectsUtils/ObjectShot.cpp

    ./sources/objects/ObjectLogo.hpp
    ./sources/objects/ObjectLogo.cpp
)

SET (MANAGERS 
    ./sources/managers/InputManager.hpp
    ./sources/managers/InputManager.cpp

    ./sources/managers/ResourceManager.hpp 
)

SET (GENERATORS
    ./sources/generators/ParticleGenerator.hpp
    ./sources/generators/ParticleGenerator.cpp

    ./sources/generators/ObjectGenerator.hpp
)

SET (ANIMATION 
    ./sources/animation/Animation.hpp
    ./sources/animation/Animation.cpp
)

SET (EFFECTS
    ./sources/effects/Dash.hpp
    ./sources/effects/Dash.cpp
)

Add_Executable (BloodSpace 

    ${DEPENDENCIES} 
    
    ${UTILS}

    ${WIDGETS}
    
    ${STATES}

    ${RENDERERS}

    ${PIECES}

    ${PARSERS}

    ${OBJECTS}

    ${MANAGERS}

    ${GENERATORS}

    ${ANIMATION}

    ${EFFECTS}
)
