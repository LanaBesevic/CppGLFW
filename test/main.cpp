#include "cppglfw/cpp_glfw.h"
#include <GLFW/glfw3.h>

int main() {
  GLFWManager& instance = GLFWManager::instance();

  Window window;
  window = instance.createWindow("LanaPoop", 800, 600);

  while (!window.shouldClose()) {

    instance.pollEvents();
  }

  return 0;
}