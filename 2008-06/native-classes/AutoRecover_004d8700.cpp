// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00826be0[];   // INFERRED: unnamed global at 0x00826be0 in the original
struct Local_004d8700 {
    int f(int a, int b, int c);
};

// INFERRED: convertToValue(const std::string&, CoordinateFrame&) takes a single stack arg here (pointer to the 2-dword local)
extern "C" bool __cdecl fn_0060a2f0(int* p);

extern "C" Local_004d8700* __fastcall fn_004d8700(Local_004d8700* self, int unusedEdx, int a, int b, int c)
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
        *(int*)self = ((int)&g_00826be0);
        return self;
    }
    *(int*)self = 0;
    return self;
}
