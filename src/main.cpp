#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Engine.h"
#include "Renderer.h"
#include "exprtk.hpp"
#include <iostream>
#include <string>

GLFWwindow *window;

void setupUI()
{
    const char *glsl_version = "#version 130";
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1280, 720, "APCF-MathEngine", NULL, NULL);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Habilitar VSync

    // Inicializar ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    // Habilitar Docking
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Habilitar Docking

    ImGui::StyleColorsDark(); // Estilo básico

    // Inicialización de backends de ImGui
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void renderUI()
{
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents(); // Manejo de eventos

        // Iniciar frame de ImGui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Obtener el viewport principal
        ImGuiViewport *viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowViewport(viewport->ID);

        // Crear una ventana sin bordes que se utilice como DockSpace
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::Begin("DockSpace Demo", nullptr, window_flags);
        ImGui::PopStyleVar(2);

        // Crear el DockSpace
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);

        // Barra de navegación superior
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Open", "Ctrl+O"))
                { /* Abrir archivo */
                }
                if (ImGui::MenuItem("Save", "Ctrl+S"))
                { /* Guardar archivo */
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Edit"))
            {
                if (ImGui::MenuItem("Undo", "Ctrl+Z"))
                { /* Deshacer */
                }
                if (ImGui::MenuItem("Redo", "Ctrl+Y"))
                { /* Rehacer */
                }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        // Panel principal - Viewport (Área de renderizado)
        ImGui::SetNextWindowSize(ImVec2(1024, 600), ImGuiCond_FirstUseEver); // Tamaño inicial
        if (ImGui::Begin("Viewport"))
        {
            renderScene(); // Llama a la lógica de renderizado
        }
        ImGui::End();

        // Panel lateral derecho (para funciones futuras)
        if (ImGui::Begin("Tools", NULL))
        {
            ImGui::Text("Herramientas futuras");
            // Aquí puedes agregar botones y opciones para herramientas futuras
        }
        ImGui::End();

        // Barra inferior para entrada de comandos
        if (ImGui::Begin("Command Input"))
        {
            static char command[256] = "";
            ImGui::InputText("Command", command, IM_ARRAYSIZE(command));

            if (ImGui::Button("Execute"))
            {
                std::cout << "Command executed: " << command << std::endl;
                processCommands(command); // Procesar el comando ingresado
            }
        }
        ImGui::End();

        // Finalizar ventana DockSpace
        ImGui::End();

        // Renderizar frame
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }
}

int main(int argc, char **argv)
{
    init();     // Inicializa el motor
    setupUI();  // Inicializa la interfaz de usuario
    renderUI(); // Renderizar la interfaz de usuario

    // Limpiar recursos
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
