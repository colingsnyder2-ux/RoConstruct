// from server: 100% by Xemicl
// roc 2012-06 00436720  unit: CPatchedControlComboBox  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00436720
//
// 00436720  53                   push ebx
// 00436721  56                   push esi
// 00436722  57                   push edi
// 00436723  33f6                 xor esi, esi
// 00436725  56                   push esi
// 00436726  83ec10               sub esp, 0x10
// 00436729  8bc4                 mov eax, esp
// 0043672b  33d2                 xor edx, edx
// 0043672d  8910                 mov dword ptr [eax], edx
// 0043672f  bf18010000           mov edi, 0x118
// 00436734  897004               mov dword ptr [eax + 4], esi
// 00436737  8d5f78               lea ebx, [edi + 0x78]
// 0043673a  897808               mov dword ptr [eax + 8], edi
// 0043673d  68bf000000           push 0xbf
// 00436742  89580c               mov dword ptr [eax + 0xc], ebx
// 00436745  e806e8ffff           call 0x434f50
// 0043674a  5f                   pop edi
// 0043674b  5e                   pop esi
// 0043674c  5b                   pop ebx
// 0043674d  c3                   ret 
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