// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00826eb0[];   // INFERRED: unnamed global at 0x00826eb0 in the original
#include <string>

// INFERRED: the callee takes the std::string by const reference plus the output
// pointer; the disassembly pushes one stack arg (&local) with the string
// reference carried in the stack slot as the 3rd argument.
struct Local_004e9ee0 {
    int vtbl;
    int pad;
    int val[2];
};

extern "C" bool __cdecl fn_0060a2f0(int* out);

extern "C" Local_004e9ee0* __fastcall fn_004e9ee0(Local_004e9ee0* self, int unusedEdx, int a, int b, int c)
{
    int local[2];
    local[0] = a;
    local[1] = b;
    self->vtbl = 0;
    if (!fn_0060a2f0(local)) {
        int* p = (int*)((char*)self + 8);
        if (p) {
            p[0] = local[0];
            p[1] = local[1];
        }
        self->vtbl = ((int)&g_00826eb0);
        return self;
    }
    self->vtbl = 0;
    return self;
}
