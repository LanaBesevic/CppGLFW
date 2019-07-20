#include "cppglfw/GLFWManager.h"

namespace cppglfw {

std::vector<Monitor> GLFWManager::getMonitors() const {
  int32_t count = 0;
  GLFWmonitor** glfw_monitors = glfwGetMonitors(&count);

  std::vector<Monitor> monitors;
  monitors.reserve(count);
  for (int32_t i = 0; i < count; i++) {
    monitors.emplace_back(glfw_monitors[i]);
  }

  return monitors;
}

Monitor GLFWManager::getPrimaryMonitor() const {
  return Monitor(glfwGetPrimaryMonitor());
}

void GLFWManager::pollEvents() const {
  glfwPollEvents();
}

Window GLFWManager::createWindow(const std::string_view& title, int32_t width, int32_t height,
                                 const std::optional<Monitor>& monitor, const std::optional<Window>& window) {
  return Window(title, width, height, monitor, window);
}

bool GLFWManager::rawMouseMotionSupported() const {
  return false;
}

const char* GLFWManager::getKeyName(int key, int scancode) const {
  return glfwGetKeyName(key, scancode);
}

int GLFWManager::getKeyScancode(int key) const {
  return glfwGetKeyScancode(key);
}

bool GLFWManager::joystickPresent(int jid) const {
  return glfwJoystickPresent(jid);
}

const float* GLFWManager::getJoystickAxes(int jid, int* count) const {
  return glfwGetJoystickAxes(jid, count);
}

const unsigned char* GLFWManager::getJoystickButtons(int jid, int* count) const {
  return glfwGetJoystickButtons(jid, count);
}

const unsigned char* GLFWManager::getJoystickHats(int jid, int* count) const {
  return glfwGetJoystickHats(jid, count);
}

const char* GLFWManager::getJoystickName(int jid) const {
  return glfwGetJoystickName(jid);
}

const char* GLFWManager::getJoystickGUID(int jid) const {
  return glfwGetJoystickGUID(jid);
}

void GLFWManager::setJoystickUserPointer(int jid, void* pointer) const {
  glfwSetJoystickUserPointer(jid, pointer);
}

void* GLFWManager::getJoystickUserPointer(int jid) const {
  return glfwGetJoystickUserPointer(jid);
}

bool GLFWManager::joystickIsGamepad(int jid) const {
  return glfwJoystickIsGamepad(jid);
}

bool GLFWManager::updateGamepadMappings(const char* string) const {
  return glfwUpdateGamepadMappings(string);
}

const char* GLFWManager::getGamepadName(int jid) const {
  return glfwGetGamepadName(jid);
}

double GLFWManager::getTime() const {
  return glfwGetTime();
}

void GLFWManager::setTime(double time) const {
  glfwSetTime(time);
}

uint64_t GLFWManager::getTimerValue() const {
  return glfwGetTimerValue();
}

uint64_t GLFWManager::getTimerFrequency() const {
  return glfwGetTimerFrequency();
}

bool GLFWManager::vulkanSupported() const {
  return glfwVulkanSupported() != 0;
}

std::vector<const char*> GLFWManager::getRequiredInstanceExtensions() const {
  uint32_t count;
  const char** extensions = glfwGetRequiredInstanceExtensions(&count);
  return std::vector<const char*>(extensions, extensions + count);
}

} // namespace cppglfw
