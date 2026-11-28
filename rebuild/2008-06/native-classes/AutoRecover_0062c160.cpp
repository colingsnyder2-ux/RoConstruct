// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

struct Local_0062c160Value {
    unsigned int words[6];
};

// INFERRED: callee is StringConverter<G3D::CoordinateFrame>::convertToValue, one stack arg (cdecl).
extern "C" bool __cdecl fn_0060a2f0(const Local_0062c160Value&);

struct Local_0062c160Obj {
    unsigned int tag;
    unsigned int reserved;
    Local_0062c160Value value;
};

extern "C" void __fastcall fn_0062c160(Local_0062c160Obj* self, int unusedEdx, const Local_0062c160Value& source) {
    if (!fn_0060a2f0(source)) {
        new (&self->value) Local_0062c160Value(source);
        self->tag = 0x00846160;
    } else {
        self->tag = 0;
    }
}
