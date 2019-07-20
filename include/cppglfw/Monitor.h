#ifndef GLFW_MONITOR_H
#define GLFW_MONITOR_H

#ifdef GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.hpp>
#endif

#include <GLFW/glfw3.h>
#include <string_view>
#include <utility>
#include <vector>

namespace cppglfw {

class Monitor {
 public:
  explicit Monitor(GLFWmonitor* monitor);

  std::pair<int32_t, int32_t> getPosition() const;

  std::pair<int32_t, int32_t> getPhysicalSize() const;

  std::string_view getName() const;

  bool isPrimary() const;

  GLFWmonitor* glfwHandle() const;

 private:
  GLFWmonitor* monitor_;
};

} // namespace cppglfw

#endif // GLFW_MONITOR_H
