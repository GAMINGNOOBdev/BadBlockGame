cmake_minimum_required(VERSION 3.0)

project(BadBlockGame)

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only")
set(ALSOFT_INSTALL OFF CACHE BOOL  "Do not install this")   
set(BUILD_UTILS OFF)

include_directories(${OPENGL_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/glew/include ${PROJECT_SOURCE_DIR}/openal/include ${GLEW_INCLUDE_DIRS} inc libinc)

add_subdirectory(glfw)
add_subdirectory(${PROJECT_SOURCE_DIR}/glew/build/cmake)
add_subdirectory(openal)

set(BadBlockGameSources
    src/main.cpp
    )

add_executable( BadBlockGame ${BadBlockGameSources} )

if( MSVC )

target_link_libraries(BadBlockGame ${OPENGL_LIBRARIES} glew_s common ex-common OpenAL glfw ${GLEW_LIBRARIES})

else()

target_link_libraries(BadBlockGame ${OPENGL_LIBRARIES} glew32s openal glfw ${GLEW_LIBRARIES})

endif()

if( MSVC )
if(${CMAKE_VERSION} VERSION_LESS "3.6.0")
    message("\nYou are running a cmake version lower than 3.6.0, you have to set 'BadBlockGame' as the Startup project manually.\n")
else()
set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT BadBlockGame )
endif()
endif()
