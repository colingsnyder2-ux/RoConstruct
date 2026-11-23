// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: function-local static index cached from ServiceProvider::newIndex()
namespace RBX {
struct ServiceProvider {
    static unsigned int newIndex();
};
}

extern "C" unsigned int fn_00455ea0()
{
    static unsigned int index = RBX::ServiceProvider::newIndex();
    return index;
}
