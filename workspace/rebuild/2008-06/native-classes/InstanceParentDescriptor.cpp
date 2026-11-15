#include "v8tree/Instance.h"
namespace RBX {
const Reflection::RefPropDescriptor<Instance, Instance> Instance::propParent("Parent", "Data", &Instance::getParent, &Instance::setParent, Reflection::PropertyDescriptor::UI);
}
