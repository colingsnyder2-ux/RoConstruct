// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

namespace RBX {
class Instance {
public:
    Instance* findFirstChildByName(const std::string& name) const;
};
}

// INFERRED: owner class is unknown; only the Instance* at offset 0x104 matters.
struct Fn5d7a90Owner {
    char pad[0x104];
    RBX::Instance* instance;
};

extern "C" RBX::Instance* __fastcall fn_005d7a90(Fn5d7a90Owner* self, int unusedEdx)
{
    // INFERRED: the original loads the pointer into a register for the null test and
    // reloads it from the member after the string temporary is built. A local copy used
    // only for the test reproduces that load pattern.
    RBX::Instance* p = self->instance;
    return p
        ? self->instance->findFirstChildByName(std::string("Right Arm"))
        : 0;
}
