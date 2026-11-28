// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00826df8[];   // INFERRED: unnamed global at 0x00826df8 in the original

// INFERRED: layout of the target object; only the first dword (vtable-like tag) and the pair at +8 are touched.
struct Local_004dba40 {
    int tag;
    int pad;
    int v[2];
};

// INFERRED: real callee is RBX::StringConverter<G3D::CoordinateFrame>::convertToValue; one stack arg per the disassembly.
extern "C" bool __cdecl fn_0060a2f0(int* p);

extern "C" Local_004dba40* __fastcall fn_004dba40(Local_004dba40* self, int unusedEdx, int a, int b, int c)
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
        *(int*)self = ((int)&g_00826df8);
        return self;
    }
    *(int*)self = 0;
    return self;
}
