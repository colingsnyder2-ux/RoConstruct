// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header excerpt was available, so this file declares local
// stand-ins. It is not compile-verified and will not reproduce the vtable stores
// at +0x10..+0xc4 until the real headers are used. Swap in the native-header
// definitions of FactoryProduct and DescribedCreatable when they exist.
namespace Reflection { struct DescribedBase; }

namespace RBX {

class Instance;
class Script;
extern char* sScript;

template<class T, class Base, char** Name>
struct FactoryProduct {
    FactoryProduct();
};

template<class T> struct DescribedHelper {
    // INFERRED: classDescriptor() is a static member of Described<Instance, sInstance>.
    static const Reflection::DescribedBase& classDescriptor();
};

template<class T, class Base, char** Name>
class DescribedCreatable : public FactoryProduct<T, Base, Name> {
protected:
    // INFERRED: field at +0x1c holds the descriptor returned by classDescriptor().
    char pad[0x18];
    const Reflection::DescribedBase* descriptor;
    DescribedCreatable()
        : FactoryProduct<T, Base, Name>()
        , descriptor(&DescribedHelper<Base>::classDescriptor())
    {
    }
};

// Explicit instantiation emits the constructor at 0x005c9ed0.
template class DescribedCreatable<Script, Instance, &sScript>;

}
