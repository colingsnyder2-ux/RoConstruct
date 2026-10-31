// from server: 100% by EspClaude
// roc 2009-06 00428c10  unit: MyXTPCommandBars  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00428c10
//
// 00428c10  53                   push ebx
// 00428c11  56                   push esi
// 00428c12  57                   push edi
// 00428c13  6a03                 push 3
// 00428c15  83ec10               sub esp, 0x10
// 00428c18  8bc4                 mov eax, esp
// 00428c1a  33d2                 xor edx, edx
// 00428c1c  8910                 mov dword ptr [eax], edx
// 00428c1e  33f6                 xor esi, esi
// 00428c20  897004               mov dword ptr [eax + 4], esi
// 00428c23  bf80020000           mov edi, 0x280
// 00428c28  bbc8000000           mov ebx, 0xc8
// 00428c2d  897808               mov dword ptr [eax + 8], edi
// 00428c30  68c0000000           push 0xc0
// 00428c35  89580c               mov dword ptr [eax + 0xc], ebx
// 00428c38  e8a3e6ffff           call 0x4272e0
// 00428c3d  5f                   pop edi
// 00428c3e  5e                   pop esi
// 00428c3f  5b                   pop ebx
// 00428c40  c3                   ret 
// copied from an identical function in another client (function ?f@CMainFrame@ns_ROCX0000f6@@QAEXXZ)

namespace ns_ROCX0000f6 {
struct Rect {
    int left, top, right, bottom;

    Rect(int l, int t, int r, int b)
        : left(l), top(t), right(r), bottom(b) {}
};

struct CMainFrame {
    void f();
    void set(unsigned int, Rect, int);
};

void CMainFrame::f()
{
    set(0xc0, Rect(0, 0, 0x280, 0xc8), 3);
}
}
