#include "v8tree/Instance.h"
namespace RBX {
const Reflection::PropDescriptor<Instance, std::string> Instance::desc_Name("Name", "Data", &Instance::getName, &Instance::setName, Reflection::PropertyDescriptor::STANDARD);
}
