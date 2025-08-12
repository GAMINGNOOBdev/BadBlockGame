#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>
#include <imgui.h>

namespace ImGuiSubsystem
{

    static ImGuiIO* mImGuiIO;
    static ImGuiStyle* mImGuiStyle;
    static ImGuiContext* mImGuiContext;

    /**
     * @brief Initialize the imgui subsystem
     * 
     * @param window GLFW window
     */
    void Initialize(GLFWwindow* window);

    /**
     * @brief Get the imgui context
     * 
     * @returns A pointer to the ImGuiContext
     */
    ImGuiContext* GetContext();

    /**
     * @brief Set whether docking is enabled or not
     */
    void SetDocking(bool value);

    /**
     * @brief Actually draws the frame data to the screen
     */
    void Draw();

    /**
     * @brief Begins drawing of the current frame
     */
    void Begin();

    /**
     * @brief Ends drawing the frame
     */
    void End();

    /**
     * @brief Terminates the imgui subsystem
     */
    void Terminate();

}
