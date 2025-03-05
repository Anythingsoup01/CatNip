set(SRCS
    src/Core/FileManager.cpp
    src/Core/Utils.cpp
    src/Core/Utils.h
    src/Core/FileManager.h
)
add_library(CatNip STATIC ${SRCS})
set_property(TARGET CatNip PROPERTY CXX_STANDARD 17)

target_include_directories(CatNip PRIVATE
    src
    ${CMAKE_SOURCE_DIR}/vendor/imgui
    ${CMAKE_SOURCE_DIR}/vendor/ImGuiFileDialog
    ${CMAKE_SOURCE_DIR}/vendor/stb
)

target_link_libraries(CatNip
    ImGui
    ImGuiFileDialog
)

