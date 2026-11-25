// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdarg.h>

// Vendor getset<> helper (PropDescriptor<FlagStand,BrickColor>): builds a GetSet object, returns it via auto_ptr.
// INFERRED: original is cdecl (ret 0) taking the out-pointer plus 6 dwords on the stack.
// A variadic function drops __fastcall, so the named params stay on the stack:
// self = out pointer, unusedEdx = first stack dword (stored at +8), rest via va_list.
extern "C" int fn_006a0920(int a1, int a2);
extern "C" char g_0083d308[]; // INFERRED: GetSet vtable at 0x83d308

struct Local_005d8170 {
    void* vtable;
    int pad4; // INFERRED: untouched by this code
    int a, b, c;
    int pad14; // INFERRED: untouched by this code
    int d, e;
    int f;
    int pad24; // INFERRED: size 0x28 requires it
};

extern "C" void** __fastcall fn_005d8170(void** self, int unusedEdx, ...)
{
    va_list ap;
    va_start(ap, unusedEdx);
    Local_005d8170* tmp = 0;
    Local_005d8170* p = (Local_005d8170*)fn_006a0920(sizeof(Local_005d8170), 0);
    if (p) {
        p->vtable = g_0083d308;
        p->a = unusedEdx;
        p->b = va_arg(ap, int);
        p->c = va_arg(ap, int);
        p->d = va_arg(ap, int);
        p->e = va_arg(ap, int);
        p->f = va_arg(ap, int);
        tmp = p;
    }
    *self = tmp;
    va_end(ap);
    return self;
}
