// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00810618[];

// INFERRED: the mangled target name (?attach@EventHandler@@QAEPAU1@UTriple@@I@Z) names a struct EventHandler
// and a struct Triple, and the real EventHandler header has no attach() member. So both types are declared
// locally, mirroring the verified analog, to produce the exact __thiscall member symbol.
struct Triple {
    unsigned int a, b, c;
};

// 0060a2f0: RBX::StringConverter<G3D::CoordinateFrame>::convertToValue
// INFERRED: takes one stack pointer argument and returns bool.
extern "C" bool __cdecl fn_0060a2f0(Triple* value);

struct EventHandler {
    void* state;
    unsigned int reserved;
    Triple payload;

    EventHandler* attach(Triple value, unsigned int unused);
};

EventHandler* EventHandler::attach(Triple value, unsigned int unused)
{
    Triple local = value;
    state = 0;

    if (!fn_0060a2f0(&local)) {
        Triple* destination = &payload;
        if (destination)
            *destination = local;
        state = reinterpret_cast<void*>(g_00810618);
        return this;
    }

    state = 0;
    return this;
}
