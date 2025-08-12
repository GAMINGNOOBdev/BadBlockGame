#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <imgui.h>

namespace ImGuiSubsystem
{

    ImGuiIO* mImGuiIO = nullptr;
    ImGuiStyle* mImGuiStyle = nullptr;
    ImGuiContext* mImGuiContext = nullptr;

    void Initialize(GLFWwindow* window)
    {
        IMGUI_CHECKVERSION();
        mImGuiContext = ImGui::CreateContext();
        ImGui::StyleColorsDark();

        mImGuiIO = &ImGui::GetIO();
        mImGuiStyle = &ImGui::GetStyle();

        mImGuiIO->ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(nullptr);
    }

    ImGuiContext* GetContext()
    {
        return mImGuiContext;
    }

    void SetDocking(bool value)
    {
        if (value)
            mImGuiIO->ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        else
            mImGuiIO->ConfigFlags &= ~ImGuiConfigFlags_DockingEnable;
    }

    void Draw()
    {
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void Begin()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void End()
    {
        ImGui::Render();
    }

    void Terminate()
    {
        if (mImGuiContext == nullptr)
            return;

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

}
