// from server: 100% by EspClaude
// roc 2007-08 005b39f0  unit: RBX::Assembly  size: 109 bytes
// Iterate a checked std::set of pointers at this+0xc (_Myhead at +0x10, node value
// at +0xc, out-of-line ++ at 0x627240) and call a no-arg thiscall method on each.
#include <set>

namespace RBX {

class Primitive
{
public:
    void onAssemblyChanged();   // 0x60ba10, thiscall, no stack args
};

class Assembly
{
    char pad00[0xc];
    std::set<Primitive*> primitives;   // +0xc
public:
    void notifyPrimitives();
};

void Assembly::notifyPrimitives()
{
    for (std::set<Primitive*>::const_iterator it = primitives.begin(); it != primitives.end(); ++it)
        (*it)->onAssemblyChanged();
}

}
