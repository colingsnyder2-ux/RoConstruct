// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: headers unavailable, so the types are declared locally.
// The constructor at 0x559b10 is declared as an extern "C" __fastcall helper.
// The atexit destructor stub is at 0x7fcb00.

namespace boost { template<class T> class shared_ptr; }

namespace RBX {
class Instance;
namespace Reflection {
template<class C, class Sig> class SignalDesc {
public:
    char data[64]; // INFERRED: size unknown
};
}
}

extern "C" void fn_007fcb00(void);
extern "C" void __fastcall fn_00559b10(void* self, int unusedEdx, const char* name, const char* arg);
extern "C" int __cdecl atexit(void (__cdecl *)(void));

namespace RBX {
class Instance {
public:
    static Reflection::SignalDesc<Instance, void (boost::shared_ptr<Instance>)> event_ancestryChanged;
};
}

// Not a named function in source; this is the dynamic initializer.
// INFERRED: the target symbol is compiler-generated; the original name is used by linker only.
void __cdecl dynamic_initializer_event_ancestryChanged()
{
    fn_00559b10(&RBX::Instance::event_ancestryChanged, 0, "AncestryChanged", "child");
    atexit(fn_007fcb00);
}
