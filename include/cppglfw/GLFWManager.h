#ifndef GLFW_MANAGER_H
#define GLFW_MANAGER_H

#ifdef GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.hpp>
#endif

#include <GLFW/glfw3.h>
#include <string_view>
#include <vector>
#include <stdexcept>
#include "Monitor.h"
#include "Window.h"

namespace cppglfw {

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
                      const std::map<int32_t, std::variant<int32_t, std::string>>& hints = {},
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

  void swapInterval(int32_t interval) const;

  bool isExtensionSupported(const std::string_view& extension) const;

  GLFWglproc getProcAddress(const std::string_view& extension) const;

  bool vulkanSupported() const;

  std::vector<const char*> getRequiredInstanceExtensions() const;

#ifdef VK_VERSION_1_0

  inline bool getPhysicalDevicePresentationSupport(vk::Instance instance, vk::PhysicalDevice device,
                                                   uint32_t queueFamily) const {
    return glfwGetPhysicalDevicePresentationSupport(static_cast<VkInstance>(instance),
                                                    static_cast<VkPhysicalDevice>(device), queueFamily) == GLFW_TRUE;
  }

  inline GLFWvkproc getInstanceProcAddress(vk::Instance instance, const std::string_view& procName) const {
    return glfwGetInstanceProcAddress(static_cast<VkInstance>(instance), procName.data());
  }

#endif

  ~GLFWManager();

 private:
  GLFWManager();
};

} // namespace cppglfw

#endif // GLFW_MANAGER_H
