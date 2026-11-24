// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: minimal local declaration; the real header was not shown.
namespace RBX {
class ServiceProvider {
public:
    static unsigned int newIndex();
};
}

// INFERRED: this looks like a function-local static holding a per-service index
// (the disassembly shows a guard bit at 0x96dd94 and the value at 0x96dd90).
extern "C" unsigned int fn_00455ea0()
{
    static unsigned int index = RBX::ServiceProvider::newIndex();
    return index;
}
