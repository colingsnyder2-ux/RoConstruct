// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00826f64[];   // INFERRED: unnamed global at 0x00826f64 in the original
struct Local_004ea260 {
    int f(int a, int b, int c);
};

// INFERRED: convertToValue(const std::string&, CoordinateFrame&) analog; first stack arg is passed through a local 2-dword block
extern "C" bool __cdecl fn_0060a2f0(int* p);

extern "C" int __fastcall fn_004ea260(Local_004ea260* self, int unusedEdx, int a, int b, int c)
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
        *(int*)self = ((int)&g_00826f64);
        return (int)self;
    }
    *(int*)self = 0;
    return (int)self;
}
