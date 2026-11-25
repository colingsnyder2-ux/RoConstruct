// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00826be8[];   // INFERRED: unnamed global at 0x00826be8 in the original
// INFERRED: the callee takes (const std::string&, CoordinateFrame&) style args; modeled as the analog's
// pointer-to-local with the two string-ish dwords stored in the local, matching the verified analog.
struct Local_004d8760 {
    int f(int a, int b, int c);
};

extern "C" bool __cdecl fn_0060a2f0(int* p);

extern "C" Local_004d8760* __fastcall fn_004d8760(Local_004d8760* self, int unusedEdx, int a, int b, int c)
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
        *(int*)self = ((int)&g_00826be8);
        return self;
    }
    *(int*)self = 0;
    return self;
}
