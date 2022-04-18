#include "aetherstats.h"
#include <imgui/imgui.h>

void
AetherStats::
main()
{
    ImGui::Begin("Connect");
    ImGui::Text("Where would you like to manually connect?");
    ImGui::InputText("Host", destination, sizeof(destination));
    if (ImGui::Button("Connect now")) {
        connect(destination);
    }
    ImGui::Spacing();
    ImGui::Checkbox("Connect automatically?", &autoconnect);
    ImGui::End();
}

void
AetherStats::
connect(const char* host)
{

}