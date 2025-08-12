cmake_minimum_required(VERSION 3.10)
project(BadBlockGame)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenGL REQUIRED)

# GLFW Options
set(GLFW_BUILD_EXAMPLES off)
set(GLFW_BUILD_TESTS off)
set(GLFW_BUILD_DOCS off)
set(GLFW_INSTALL off)

# GLEW Options
set(ONLY_LIBS on)
set(BUILD_UTILS off)

# OpenAL Options
set(ALSOFT_UTILS off)
set(ALSOFT_INSTALL off)
set(ALSOFT_EXAMPLES off)
set(ALSOFT_INSTALL_UTILS off)
set(ALSOFT_INSTALL_CONFIG off)
set(ALSOFT_INSTALL_EXAMPLES off)
set(ALSOFT_INSTALL_HRTF_DATA off)
set(ALSOFT_INSTALL_AMBDEC_PRESETS off)

# Assimp Options
set(ASSIMP_INSTALL off)
set(ASSIMP_BUILD_TESTS off)

# Box2d Options
set(BOX2D_SAMPLES off)
set(BOX2D_UNIT_TESTS off)

# Jolt Options
set(TARGET_UNIT_TESTS off)
set(TARGET_HELLO_WORLD off)
set(TARGET_PERFORMANCE_TEST off)
set(TARGET_SAMPLES off)
set(TARGET_VIEWER off)

# include_directories(${OPENGL_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/openal/include assimp/include box2d/include bullet3/src ${PROJECT_SOURCE_DIR}/glew/include ${GLEW_INCLUDE_DIRS} imgui inc lib/includes)
include_directories(
    assimp/include
    box2d/include
    imgui
    inc
    JoltPhysics
    ${OPENGL_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/openal/include
    ${PROJECT_SOURCE_DIR}/glew/include
    ${GLEW_INCLUDE_DIRS}
    stb
)

add_subdirectory(assimp)
add_subdirectory(box2d)
add_subdirectory(glew/build/cmake)
add_subdirectory(glfw)
add_subdirectory(JoltPhysics/Build)
add_subdirectory(openal)

set(imgui_sources
    imgui/backends/imgui_impl_opengl3.cpp
    imgui/backends/imgui_impl_glfw.cpp
    imgui/misc/cpp/imgui_stdlib.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui.cpp
)

set(project_sources
    src/ImGuiSubsystem.cpp
    src/main.cpp
)

add_executable( ${PROJECT_NAME} ${imgui_sources} ${project_sources} )
add_compile_definitions(NOMINMAX GLEW_STATIC)

target_link_libraries(${PROJECT_NAME}
    assimp
    box2d
    glew_s
    glfw
    Jolt
    ${OPENGL_LIBRARIES}
    OpenAL
    alsoft.common
)

if( MSVC )
    # target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glew_s common ex-common OpenAL glfw ${GLEW_LIBRARIES})
    set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME} )
else()
    # target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glew_s openal glfw ${GLEW_LIBRARIES})
endif()
