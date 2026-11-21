#include "v8tree/Instance.h"
namespace RBX {
// Verbatim from the authentic App/v8tree/Instance.cpp descriptor block (L22).
static Reflection::PropDescriptor<Instance, std::string> prop_className("className", "Data", &Instance::getClassNameStr, NULL, Reflection::PropertyDescriptor::UI);
}
