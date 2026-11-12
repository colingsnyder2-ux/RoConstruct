// from server: 100% by EspClaude
// roc 2007-08 005e9e00  unit: RBX::VFlagStand::?$FactoryProduct  size: 127 bytes
// Shape: vector of 8-byte {px,pn} handles held by pointer at this+0xc0 (VS2005
// vector: _Myfirst +4, _Mylast +8); return the first child that dynamic_casts
// from RBX::Instance to RBX::Flag (RTTI names read from the exe type descriptors).
#include <vector>

namespace RBX {
class Instance { public: virtual ~Instance(); };
class Flag : public Instance { };
}

struct Handle {
    RBX::Instance* px;
    void* pn;
};

struct FactoryProduct {
    char pad[0xc0];
    std::vector<Handle>* children;
    RBX::Flag* findFlag();
};

RBX::Flag* FactoryProduct::findFlag()
{
    if (children) {
        std::vector<Handle>::iterator end = children->end();
        for (std::vector<Handle>::iterator it = children->begin(); it != end; ++it) {
            if (RBX::Flag* f = dynamic_cast<RBX::Flag*>(it->px))
                return f;
        }
    }
    return 0;
}
