// from server: 100% by EspClaude
// roc 2009-06 00428be0  unit: MyXTPCommandBars  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00428be0
//
// 00428be0  53                   push ebx
// 00428be1  56                   push esi
// 00428be2  57                   push edi
// 00428be3  33f6                 xor esi, esi
// 00428be5  56                   push esi
// 00428be6  83ec10               sub esp, 0x10
// 00428be9  8bc4                 mov eax, esp
// 00428beb  33d2                 xor edx, edx
// 00428bed  8910                 mov dword ptr [eax], edx
// 00428bef  bf18010000           mov edi, 0x118
// 00428bf4  897004               mov dword ptr [eax + 4], esi
// 00428bf7  8d5f78               lea ebx, [edi + 0x78]
// 00428bfa  897808               mov dword ptr [eax + 8], edi
// 00428bfd  68bf000000           push 0xbf
// 00428c02  89580c               mov dword ptr [eax + 0xc], ebx
// 00428c05  e8d6e6ffff           call 0x4272e0
// 00428c0a  5f                   pop edi
// 00428c0b  5e                   pop esi
// 00428c0c  5b                   pop ebx
// 00428c0d  c3                   ret 
// copied from an identical function in another client (function ?f@CMainFrame@ns_ROCX0000f5@@QAEXXZ)

namespace ns_ROCX0000f5 {
struct Rect
{
    int left, top, right, bottom;
    Rect(int l, int t, int r, int b);
};

__forceinline Rect::Rect(int l, int t, int r, int b)
    : left(l), top(t), right(r), bottom(b)
{
}

struct Pane;

struct CMainFrame
{
    Pane* FindPane(unsigned int id, Rect bounds, int flags);
    void f();
};

void CMainFrame::f()
{
    FindPane(191, Rect(0, 0, 280, 400), 0);
}
}
