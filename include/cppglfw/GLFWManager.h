#ifndef GLFW_MANAGER_H
#define GLFW_MANAGER_H

#include <GLFW/glfw3.h>
#include <vector>
#include "Monitor.h"
#include "Window.h"

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

  Window createWindow(const std::string_view& title, int32_t width, int32_t height,
                      const std::optional<Monitor>& monitor = {}, const std::optional<Window>& window = {});

  bool rawMouseMotionSupported() const;

  const char* getKeyName(int key, int scancode) const;

  int getKeyScancode(int key) const;

  bool joystickPresent(int jid) const;

  const float* getJoystickAxes(int jid, int* count) const;

  const unsigned char* getJoystickButtons(int jid, int* count) const;

  const unsigned char* getJoystickHats(int jid, int* count) const;

  const char* getJoystickName(int jid) const;

  const char* getJoystickGUID(int jid) const;

  void setJoystickUserPointer(int jid, void* pointer) const;

  void* getJoystickUserPointer(int jid) const;

  bool joystickIsGamepad(int jid) const;

  bool updateGamepadMappings(const char* string) const;

  const char* getGamepadName(int jid) const;

  double getTime() const;

  void setTime(double time) const;

  uint64_t getTimerValue() const;

  uint64_t getTimerFrequency() const;

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
