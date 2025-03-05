#include "ImGuiStart.h"
#include <imgui.h>

namespace CatNip
{
    void ImGuiStart::SetDefaultTheme()
    {
        auto& colors = ImGui::GetStyle().Colors;
        colors[ImGuiCol_WindowBg] = ImVec4{ 0.13f, 0.13f, 0.13f, 1.0f };

        // Headers
        colors[ImGuiCol_Header] = ImVec4{ 0.143f, 0.143f, 0.143f, 1.0f };
        colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.2f, 0.2f, 0.2f, 1.0f };
        colors[ImGuiCol_HeaderActive] = ImVec4{ 0.173f, 0.173f, 0.173f, 1.0f };

        // Buttons
        colors[ImGuiCol_Button] = ImVec4{ 0.155f, 0.155f, 0.155f, 1.0f };
        colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.25f, 0.25f, 0.25f, 1.0f };
        colors[ImGuiCol_ButtonActive] = ImVec4{ 0.175f, 0.175f, 0.175f, 1.0f };

        // Frame BG
        colors[ImGuiCol_FrameBg] = ImVec4{ 0.157f, 0.157f, 0.157f, 1.0f };
        colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.3f, 0.3f, 0.3f, 1.0f };
        colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.257f, 0.257f, 0.257f, 1.0f };

        // Tabs
        colors[ImGuiCol_Tab] = ImVec4{ 0.235f, 0.235f, 0.235f, 1.0f };
        colors[ImGuiCol_TabHovered] = ImVec4{ 0.235f, 0.235f, 0.235f, 1.0f };
        colors[ImGuiCol_TabActive] = ImVec4{ 0.335f, 0.335f, 0.335f, 1.0f };
        colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.235f, 0.235f, 0.235f, 1.0f };
        colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.235f, 0.235f, 0.235f, 1.0f };

        // Title
        colors[ImGuiCol_TitleBg] = ImVec4{ 0.175f, 0.175f, 0.175f, 1.0f };
        colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.175f, 0.175f, 0.175f, 1.0f };
        colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.175f, 0.175f, 0.175f, 1.0f };

        // Buttons
        colors[ImGuiCol_Button] = ImVec4{ 0.0f, 0.0f, 0.0f, 0.0f };
        colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.15f, 0.15f, 0.15f, 1.0f };
        colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.176f, 0.176f, 0.176f, 1.0f };
    }
    void ImGuiStart::SetDefaultStyle()
    {
        auto& style = ImGui::GetStyle();

        style.WindowPadding = { 5, 5 };
        style.WindowBorderSize = 0;
        style.WindowRounding = 2;

        style.ChildBorderSize = 0;
        style.ChildRounding = 2;

        style.PopupBorderSize = 0;
        style.PopupRounding = 1;

        style.FramePadding = { 1, 2 };
        style.FrameBorderSize = 0;
        style.FrameRounding = 2;

        style.TabBorderSize = 0;
        style.TabBarBorderSize = 1;
        style.TabRounding = 6;

        style.ScrollbarSize = 10;
        style.ScrollbarRounding = 0;

        style.GrabMinSize = 5;
        style.GrabRounding = 0;

        style.WindowTitleAlign = { 0.5, 0.75f };
        style.WindowMenuButtonPosition = ImGuiDir_Right;

        style.ButtonTextAlign = { 0.5f, 0.5f };

        style.SeparatorTextBorderSize = 1;
        style.SeparatorTextAlign = { 0, 0 };
        style.SeparatorTextPadding = { 20, 0 };

        style.DockingSeparatorSize = 2;

        style.ItemSpacing = { 5, 5 };
        style.ItemInnerSpacing = { 5, 0 };
        style.TouchExtraPadding = { 0, 0 };
        style.IndentSpacing = 10;
    }
}
