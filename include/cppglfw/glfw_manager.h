#ifndef GLFW_MANAGER_H
#define GLFW_MANAGER_H

#include <GLFW/glfw3.h>
#include <vector>
#include "monitor.h"
#include "window.h"

class GLFWManager {
 public:
  GLFWManager(const GLFWManager&) = delete;
  GLFWManager& operator=(const GLFWManager&) = delete;
  GLFWManager(GLFWManager&&) = delete;
  GLFWManager& operator=(GLFWManager&&) = delete;

  static GLFWManager& instance() {
    static GLFWManager instance;

    return instance;
  }

  std::vector<Monitor> getMonitors() const;

  Monitor getPrimaryMonitor() const;

  void pollEvents() const;

  template <typename... Args>
  Window createWindow(Args... args) {
    return Window(args...);
  }

#ifdef GLFW_INCLUDE_VULKAN
  bool vulkanSupported() const;

  std::vector<const char*> getRequiredInstanceExtensions() const;
#endif

 private:
  GLFWManager() {
    if (!glfwInit()) {
      throw std::runtime_error("Failed to initialize GLFW.");
    }
  }
};

#endif // GLFW_MANAGER_H
