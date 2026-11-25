// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the constructor is a plain thiscall member with no EH, so declare it
// as a non-throwing, trivially-destructible-free type and avoid a placement new.
namespace RBX {
class RunService;
namespace Reflection {
template<class C, class Sig>
struct SignalDesc {
    SignalDesc(const char* name, const char* arg);
};
}
}

typedef RBX::Reflection::SignalDesc<RBX::RunService, void(float)> Desc;

extern Desc g_00970c7c;
extern "C" void fn_007fbae0(void);
extern "C" int atexit(void (__cdecl *)(void));

extern "C" void fn_007f1c00()
{
    // INFERRED: constructs the global in place
    g_00970c7c.Desc::SignalDesc("ConnectionRejected", "peer");
    atexit(fn_007fbae0);
}
