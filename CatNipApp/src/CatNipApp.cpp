#include "Ferret/Core/Application.h"
#include "Ferret/Core/Core.h"
#include "Ferret/Core/Entrypoint.h"
#include "CatNipLayer.h"
#include "imgui.h"



Ferret::Application* Ferret::CreateApplication(int argc, char** argv)
{
    Ferret::ApplicationSpecifications spec;
    spec.Title = "CatNip Application";

    Ferret::Application* app = new Ferret::Application();

    CatNip::CatNipLayer* applicationLayer = new CatNip::CatNipLayer;
    app->PushLayer(applicationLayer);
    app->SetMenubarCallback([app, applicationLayer]()
    {
        if (ImGui::BeginMenu("File"))
        {
            if(ImGui::MenuItem("Open File"))
            {
                applicationLayer->OpenFile();
            }
            if(ImGui::MenuItem("Save File"))
            {
                applicationLayer->SaveFile();
            }
            if(ImGui::MenuItem("Exit"))
            {
                app->Close();
            }

            ImGui::EndMenu();
        }
    });

    return app;
}
