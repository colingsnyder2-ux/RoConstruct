// from server: 100% by EspClaude
// from server: 58% by colin
// roc 2007-08 00461610  unit: CScriptEditor  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00461610
//
// 00461610  8b542408             mov edx, dword ptr [esp + 8]
// 00461614  81fa74128c00         cmp edx, 0x8c1274
// 0046161a  7408                 je 0x461624
// 0046161c  81fabc148c00         cmp edx, 0x8c14bc
// 00461622  7518                 jne 0x46163c
// 00461624  83ec08               sub esp, 8
// 00461627  8bc4                 mov eax, esp
// 00461629  8910                 mov dword ptr [eax], edx
// 0046162b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046162f  895004               mov dword ptr [eax + 4], edx
// 00461632  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00461636  50                   push eax
// 00461637  e8d4feffff           call 0x461510

// The two compared values are relocated data addresses (target shows sym), modeled as extern objects.
extern int g_obj_8c1274;
extern int g_obj_8c14bc;

struct Pair8 {
    const void* p;
    int c;
    Pair8(const void* p_, int c_) : p(p_), c(c_) {}
    Pair8(const Pair8& o) : p(o.p), c(o.c) {}
};

struct CScriptEditor {
    void sub_461510(int, Pair8);
    void f(int, const void*, int);
};

void CScriptEditor::f(int a, const void* b, int c)
{
    if (b == &g_obj_8c1274 || b == &g_obj_8c14bc) {
        sub_461510(a, Pair8(b, c));
    }
}
