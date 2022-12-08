#include <GLFW/glfw3.h>
#include <stdio.h>

int main(const int argc, const char** argv) {
    GLFWwindow* window;

    if (!glfwInit()) {
        printf("Error while initializing glfw\n");
        return -1;
    }
    window = glfwCreateWindow(800, 600, "test", NULL, NULL);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.0f,  0.5f);
        glEnd();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}