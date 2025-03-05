project "CatNip"
    language "C++"
    dialect "17"
    kind "StaticLib"

    files
    {
        "src/*.cpp",
        "src/*.h",
    }

    includedirs
    {
        "src",
        "$(ROOTDIR)/vendor/imgui",
        "$(ROOTDIR)/vendor/ImGuiFileDialog",
        "$(ROOTDIR)/vendor/stb",
    }

    links
    {
        "ImGui",
        "ImGuiFileDialog"
    }
