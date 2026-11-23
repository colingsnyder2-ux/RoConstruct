// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: function-local static guard (bit 0 of 0x96de84) caching ServiceProvider::newIndex().
// The SEH frame needs newIndex to be a C++ function that may throw, since extern "C" is assumed nothrow under /EHsc.
namespace RBX {
class ServiceProvider {
public:
    static unsigned int newIndex();
};
}

extern "C" unsigned int fn_0045b2b0() {
    static unsigned int value = RBX::ServiceProvider::newIndex();
    return value;
}
