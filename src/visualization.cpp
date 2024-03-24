#include "visualization.h"

const int CIRCLE_SEGMENTS = 360;  // Number of segments used to draw each circle

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
    glOrtho(0.0, 800, 600, 0.0, -1, 1);  // Left 0, Right 800, Bottom 600, Top 0
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= CIRCLE_SEGMENTS; i++) {
        GLfloat angle = 2.0f * M_PI * float(i) / float(CIRCLE_SEGMENTS);
        GLfloat dx = radius * cosf(angle);
        GLfloat dy = radius * sinf(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius, GLfloat lineWidth) {
    GLfloat outerRadius = radius + lineWidth / 2;
    GLfloat innerRadius = radius - lineWidth / 2;

    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= CIRCLE_SEGMENTS; ++i) {
        GLfloat angle = 2.0f * M_PI * i / CIRCLE_SEGMENTS;

        GLfloat outerX = x + outerRadius * cosf(angle);
        GLfloat outerY = y + outerRadius * sinf(angle);
        glVertex2f(outerX, outerY);

        GLfloat innerX = x + innerRadius * cosf(angle);
        GLfloat innerY = y + innerRadius * sinf(angle);
        glVertex2f(innerX, innerY);
    }
    glEnd();
}

void colorSetter(LineColor lineColor) {
    float red = 0;
    float green = 0;
    float blue = 0;

    switch (lineColor) {
        case LineColor::red:
            red = 1;
            break;
        case LineColor::orange:
            red = 1;
            green = 0.5;
            break;
        case LineColor::green:
            green = 1;
            break;
        case LineColor::blue:
            blue = 1;
            break;
        case LineColor::silver:
            red = 0.75;
            green = 0.75;
            blue = 0.75;
            break;
        case LineColor::unknown:
            break;
    }

    glColor3f(red, green, blue);
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
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Background white
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0f, 0.0f, 0.0f);

        drawHollowCircle(400, 500, 100, 10);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
