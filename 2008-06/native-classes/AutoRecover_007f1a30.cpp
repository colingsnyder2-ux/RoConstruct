// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: minimal local declarations; the real headers are not shown.
namespace RBX {
class RunService;
namespace Reflection {
template<class C, class Sig>
class SignalDesc {
public:
    SignalDesc(const char* name, const char* arg);
    ~SignalDesc();
};
}
}

// INFERRED: the global's real type is SignalDesc<RunService, void(float)>, as the mangled ctor name shows.
typedef RBX::Reflection::SignalDesc<RBX::RunService, void (__cdecl*)(float)> PlayerRemovingDesc;

PlayerRemovingDesc event_PlayerRemoving("PlayerRemoving", "player");
