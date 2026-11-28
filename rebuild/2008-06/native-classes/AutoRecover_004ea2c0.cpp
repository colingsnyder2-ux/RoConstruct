// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00826f6c[];   // INFERRED: unnamed global at 0x00826f6c in the original
struct Local_004ea2c0 {
    int f(int a, int b, int c);
};

// INFERRED: callee takes a pointer to an 8-byte output and (by stack) the string reference pair
extern "C" bool __cdecl fn_0060a2f0(int* p);

extern "C" Local_004ea2c0* __fastcall fn_004ea2c0(Local_004ea2c0* self, int unusedEdx, int a, int b, int c)
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
        *(int*)self = ((int)&g_00826f6c);
        return self;
    }
    *(int*)self = 0;
    return self;
}
