// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: minimal local declaration; the real header was not shown.
namespace RBX {
class ServiceProvider {
public:
    static unsigned int newIndex();
};
}

// INFERRED: function-local static index, the usual per-service-type slot
// pattern (guard bit 0x97145c, value 0x971458). The target is unnamed, so it
// uses the fn_ convention.
extern "C" unsigned int fn_004ab470()
{
    static unsigned int index = RBX::ServiceProvider::newIndex();
    return index;
}
