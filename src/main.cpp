#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <ImGuiSubSystem.h>

static bool game_is_running;

static bool is_running(GLFWwindow* window)
{
    return game_is_running && !glfwWindowShouldClose(window);
}

int main(const int argc, const char** argv)
{
    if (!glfwInit())
    {
        printf("Error while initializing glfw\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "test", NULL, NULL);
    glfwMakeContextCurrent(window);

    int status = glewInit();
    if (status != GLEW_OK)
    {
        printf("Error while initializing glew: %s", glewGetErrorString(status));
        return -1;
    }

    ImGuiSubsystem::Initialize(window);

    while (is_running(window))
    {
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGuiSubsystem::Begin();
        ImGuiSubsystem::End();
        ImGuiSubsystem::Draw();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    ImGuiSubsystem::Terminate();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}