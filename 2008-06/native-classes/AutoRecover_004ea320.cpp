// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00826f74[];   // INFERRED: unnamed global at 0x00826f74 in the original
// INFERRED: the convertToValue callee takes a pointer to a local 8-byte buffer (the first two args are stored there); its real signature is StringConverter<CoordinateFrame>::convertToValue(const std::string&, CoordinateFrame&), but only the stack layout matters here.
extern "C" bool __cdecl fn_0060a2f0(int* p);

struct Local_004ea320 {
    int f(int a, int b, int c);
};

extern "C" int __fastcall fn_004ea320(Local_004ea320* self, int unusedEdx, int a, int b, int c);

extern "C" int __fastcall fn_004ea320(Local_004ea320* self, int unusedEdx, int a, int b, int c)
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
        *(int*)self = ((int)&g_00826f74);
        return (int)self;
    }
    *(int*)self = 0;
    return (int)self;
}
