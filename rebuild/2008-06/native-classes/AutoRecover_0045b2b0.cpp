// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: function-local static index (guard 0x96de84, value 0x96de80) from ServiceProvider::newIndex(); minimal local declaration of the class.
namespace RBX {
class ServiceProvider {
public:
    static unsigned int newIndex();
};
}

extern "C" unsigned int fn_0045b2b0()
{
    static unsigned int index = RBX::ServiceProvider::newIndex();
    return index;
}
