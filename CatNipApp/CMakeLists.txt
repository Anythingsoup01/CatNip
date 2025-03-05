set(SRCS
    src/CatNipLayer.cpp
    src/ImGui/ImGuiStart.cpp
    src/CatNipApp.cpp
    src/CatNipLayer.h
    src/ImGui/ImGuiStart.h
)
add_executable(CatNipApp ${SRCS})
set_property(TARGET CatNipApp PROPERTY CXX_STANDARD 17)

target_include_directories(CatNipApp PRIVATE
    ${CMAKE_SOURCE_DIR}/Ferret/src
    ${CMAKE_SOURCE_DIR}/CatNip/src
    ${CMAKE_SOURCE_DIR}/vendor/glfw/include
    ${CMAKE_SOURCE_DIR}/vendor/glad/include
    ${CMAKE_SOURCE_DIR}/vendor/glm
    ${CMAKE_SOURCE_DIR}/vendor/imgui
    ${CMAKE_SOURCE_DIR}/vendor/ImGuiFileDialog
)

target_link_libraries(CatNipApp
    Ferret
    CatNip
)

