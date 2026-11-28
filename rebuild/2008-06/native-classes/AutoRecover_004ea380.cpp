// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00826f7c[];   // INFERRED: unnamed global at 0x00826f7c in the original
// INFERRED: callee is StringConverter<CoordinateFrame>::convertToValue(const std::string&, CoordinateFrame&) per the mangled comment; the real signature is unknown here, so it is declared as an extern "C" fn_ taking the output pointer (the std::string argument is passed by the caller frame).
extern "C" bool __cdecl fn_0060a2f0(int* out);

// INFERRED: unnamed target, class unknown; declared as a fastcall member helper.
struct Local_004ea380 {
    int vtbl;
};

extern "C" Local_004ea380* __fastcall fn_004ea380(Local_004ea380* self, int unusedEdx, int a, int b, int c)
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
        *(int*)self = ((int)&g_00826f7c);
        return self;
    }
    *(int*)self = 0;
    return self;
}
