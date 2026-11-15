#include "v8tree/Instance.h"
namespace RBX {
Reflection::BoundProp<bool, 1> Instance::propArchivable("archivable", "Behavior", &Instance::archivable, Reflection::PropertyDescriptor::STANDARD);
}
