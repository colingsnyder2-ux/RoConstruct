// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace RBX {

class ModelInstance;

// INFERRED: minimal local declaration; the real header was not available.
// The mangled name of the static member matches the one in the disassembly.
class Accoutrement {
public:
    static void dropAllOthers(ModelInstance* model, Accoutrement* keep);
};

} // namespace RBX

// INFERRED: the symbol label "_str_match" does not match the code, so I used the
// fn_<address> naming. The body is a thin cdecl wrapper that passes (arg, NULL).
extern "C" void fn_005b17c0(RBX::ModelInstance* model)
{
    RBX::Accoutrement::dropAllOthers(model, 0);
}
