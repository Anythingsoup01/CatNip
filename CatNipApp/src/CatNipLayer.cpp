#include "CatNipLayer.h"
#include "Ferret/Core/Application.h"
#include "Ferret/Core/Core.h"
#include "Ferret/Core/KeyCodes.h"
#include "Ferret/Event/Event.h"
#include "Ferret/Event/KeyEvent.h"
#include "ImGui/ImGuiStart.h"
#include <imgui.h>
#include <imgui_internal.h>
#include <ImGuiFileDialog.h>

#include <filesystem>

#include <iostream>

using namespace Ferret;

namespace CatNip
{
    CatNipLayer* CatNipLayer::s_Instance = nullptr;

    void CatNipLayer::OnAttach()
    {
        ImGuiStart::SetDefaultTheme();
        ImGuiStart::SetDefaultStyle();

        s_Instance = this;

        std::filesystem::current_path("/home/");
    }

    void CatNipLayer::OnDetach()
    {
        s_Instance = nullptr;
    }

    void CatNipLayer::OnUIRender()
    {

        RenderWorkspace();
        RenderFileTree();

        if (m_FileDialogOpen)
        {
            if (ImGui::Begin("##OpenDialogCommand"))
            {
                IGFD::FileDialogConfig config;config.path = ".";
                ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".*", config);
            }
            ImGui::End();

            // display
            if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey"))
            { // => will show a dialog
                if (ImGuiFileDialog::Instance()->IsOk())
                { // action if OK
                    std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                    // action

                    std::string data = FileManager::GetFileData(filePathName);

                    m_FileManager.PushToFileManager(filePathName, data);
                    m_OpenedFiles.emplace(filePathName, data.data());
                }

                // close
                ImGuiFileDialog::Instance()->Close();
                m_FileDialogOpen = false;
            }
        }

    }

    void CatNipLayer::OnEvent(Ferret::Event& e)
    {
        Ferret::EventDispatcher dispatcher(e);

        dispatcher.Dispatch<Ferret::KeyPressedEvent>(BIND_EVENT_FN(CatNipLayer::OnKeyPressed));
    }

    void CatNipLayer::RenderWorkspace()
    {

        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.25,0.3,0.35,0.25));

        ImGui::Begin("##Workspace");
        {
            ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None | ImGuiTabBarFlags_AutoSelectNewTabs | ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_FittingPolicyResizeDown;
            if (ImGui::BeginTabBar("#TABBAR", tab_bar_flags))
            {
                ImVec2 size = ImGui::GetContentRegionAvail();
                for (auto& [key, fileData] : m_FileManager.m_Files)
                {
                    bool active = true;
                    std::string label = fileData.Title;
                    if (fileData.Buffer[0] == 0)
                        strcpy(fileData.Buffer, fileData.Content.c_str());

                    if(ImGui::BeginTabItem(label.c_str(), &active))
                    {
                        m_OpenedFileKey = key;
                        if(ImGui::InputTextMultiline("##", fileData.Buffer, IM_ARRAYSIZE(fileData.Buffer), size, ImGuiInputTextFlags_AllowTabInput))
                        {
                            m_OpenedFiles.at(key) = fileData.Buffer;
                        }
                        ImGui::EndTabItem();
                    }

                    if (!active)
                    {
                        Ferret::Application::Get().SubmitToMainThread([this]()
                        {
                            m_FileManager.RemoveFileFromIndex(m_OpenedFileKey);
                            m_OpenedFiles.erase(m_OpenedFileKey);
                        });
                    }

                }

                ImGui::EndTabBar();
            }
            ImGui::End();
            ImGui::PopStyleColor();
        }
    }

    void CatNipLayer::RenderFileTree()
    {
        ImGui::Begin("Files");
        {
            ImVec2 size = {ImGui::GetContentRegionAvail().x, 15};
            for(auto& [key, data] : m_OpenedFiles)
            {
                auto& fileData = m_FileManager.m_Files.at(key);
                if (ImGui::Button(fileData.Title.c_str(), size))
                {
                }
            }
            ImGui::End();
        }
    }

    void CatNipLayer::OpenFile()
    {
        m_FileDialogOpen = true;
    }

    void CatNipLayer::SaveFile()
    {
        if (!m_OpenedFileKey.empty() && !m_OpenedFiles.empty())
            m_FileManager.SaveFile(m_OpenedFileKey, m_OpenedFiles.at(m_OpenedFileKey));
    }

    bool CatNipLayer::OnKeyPressed(KeyPressedEvent& e)
    {
        bool ctrl = Input::IsKeyPressed(KeyCode::RightControl) || Input::IsKeyPressed(KeyCode::LeftControl);
        switch (e.GetKeyCode())
        {
            case KeyCode::S:
            {
                if (ctrl)
                    SaveFile();
                break;
            }
			case KeyCode::O:
			{
				if (ctrl)
					OpenFile();
			}
            default:
                break;
        }
        return false;
    }
}
