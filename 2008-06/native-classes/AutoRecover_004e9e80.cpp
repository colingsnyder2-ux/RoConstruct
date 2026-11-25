// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00826ea8[];   // INFERRED: unnamed global at 0x00826ea8 in the original

// INFERRED: object layout is a vptr at +0 and a two-dword payload at +8.
struct Local_004e9e80 {
    int dummy;
};

// INFERRED: callee is RBX::StringConverter<G3D::CoordinateFrame>::convertToValue; its real signature is unknown, so it is declared as taking one pointer.
extern "C" bool __cdecl fn_0060a2f0(int* p);

extern "C" Local_004e9e80* __fastcall fn_004e9e80(Local_004e9e80* self, int unusedEdx, int a, int b, int c)
{
    int local[2];
    local[0] = a;
    local[1] = b;
    *(int*)self = 0;
    if (!fn_0060a2f0(local)) {
        int* p = (int*)((char*)self + 8);
        if (p) {
            p[0] = local[0];
            p[1] = local[1];
        }
        *(int*)self = ((int)&g_00826ea8);
        return self;
    }
    *(int*)self = 0;
    return self;
}
