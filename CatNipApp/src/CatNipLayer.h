#pragma once
#include "Ferret/Layer/Layer.h"
#include "Ferret/Event/Event.h"
#include "Ferret/Event/KeyEvent.h"
#include "Ferret/Core/Input.h"
#include "Core/FileManager.h"
#include <unordered_map>
#include <filesystem>

namespace CatNip
{
    class CatNipLayer : public Ferret::Layer
    {
    public:
        virtual void OnAttach() override;
        virtual void OnDetach() override;

        virtual void OnUpdate(float ts) override {}
        virtual void OnUIRender() override;
        virtual void OnEvent(Ferret::Event& e) override;

        bool OnKeyPressed(Ferret::KeyPressedEvent& e);

        void RenderWorkspace();
        void RenderFileTree();

        void OpenFile();
        void SaveFile();

        static CatNipLayer& Get() { return *s_Instance; }
    private:
        static CatNipLayer* s_Instance;
        FileManager m_FileManager;
        bool m_FileDialogOpen = false;

        std::string m_OpenedFileKey;
        std::unordered_map<std::string, char*> m_OpenedFiles;
    };
}
