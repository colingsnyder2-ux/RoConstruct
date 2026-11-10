#include "tool/DragUtilities.h"
#include "v8tree/Instance.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
__declspec(noinline) void collectPrimitives(const Instance* object, std::vector<Primitive*>& output) {
    if (const PartInstance* part = dynamic_cast<const PartInstance*>(object)) {
        Primitive* primitive = reinterpret_cast<Primitive*>(const_cast<char*>(reinterpret_cast<const char*>(part)) + 0x228);
        output.push_back(primitive);
    }
    for (size_t i = 0; i < object->numChildren(); ++i)
        collectPrimitives(object->getChild(i), output);
}
void DragUtilities::getPrimitives(const Instance* object, std::vector<Primitive*>& output) { collectPrimitives(object, output); }
}
