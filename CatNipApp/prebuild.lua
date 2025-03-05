project "CatNipApp"
    language "C++"
    dialect "17"
    kind "ConsoleApp"

    files
    {
        "src/*.cpp",
        "src/*.h",
    }

    includedirs
    {
        "$(ROOTDIR)/Ferret/src",
        "$(ROOTDIR)/CatNip/src",
        "$(ROOTDIR)/vendor/glfw/include",
        "$(ROOTDIR)/vendor/glad/include",
        "$(ROOTDIR)/vendor/glm",
        "$(ROOTDIR)/vendor/imgui",
        "$(ROOTDIR)/vendor/ImGuiFileDialog",
    }

    links
    {
        "Ferret",
        "CatNip"
    }
