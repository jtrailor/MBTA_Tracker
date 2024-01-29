#include "visualization.h"

const int CIRCLE_SEGMENTS = 360; // Number of segments used to draw each circle

int initializeGLFW() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW." << std::endl;

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

        return -1;
    }
    return 0;
}

int createWindow(int width, int height, const char* windowTitle,
                 GLFWwindow** window) {
    *window = glfwCreateWindow(width, height, windowTitle, NULL, NULL);

    if (!(*window)) {
        std::cerr << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }
    return 0;
}

int initializeGLAD() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD." << std::endl;
        return -1;
    }
    return 0;
}

void set2DRendering() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 800, 600, 0.0, -1, 1); // Left 0, Right 800, Bottom 600, Top 0
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of circle
    for (int i = 0; i <= CIRCLE_SEGMENTS; i++) {
        GLfloat angle = 2.0f * M_PI * float(i) / float(CIRCLE_SEGMENTS);
        GLfloat dx = radius * cosf(angle);
        GLfloat dy = radius * sinf(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

int runProgram() {
    GLFWwindow* window;

    initializeGLFW();

    createWindow(800, 600, "MBTA Tracker", &window);

    glfwMakeContextCurrent(window);

    initializeGLAD();

    set2DRendering();

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Background white
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0f, 0.0f, 0.0f);
        drawCircle(200, 300, 100);

        glColor3f(0.0f, 1.0f, 0.0f);
        drawCircle(400, 300, 100);

        glColor3f(0.0f, 0.0f, 1.0f);
        drawCircle(600, 300, 100);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
