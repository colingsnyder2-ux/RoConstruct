// from server: 100% by Xemicl
// roc 2012-06 00436750  unit: CPatchedControlComboBox  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00436750
//
// 00436750  53                   push ebx
// 00436751  56                   push esi
// 00436752  57                   push edi
// 00436753  6a03                 push 3
// 00436755  83ec10               sub esp, 0x10
// 00436758  8bc4                 mov eax, esp
// 0043675a  33d2                 xor edx, edx
// 0043675c  8910                 mov dword ptr [eax], edx
// 0043675e  33f6                 xor esi, esi
// 00436760  897004               mov dword ptr [eax + 4], esi
// 00436763  bf80020000           mov edi, 0x280
// 00436768  bbc8000000           mov ebx, 0xc8
// 0043676d  897808               mov dword ptr [eax + 8], edi
// 00436770  68c0000000           push 0xc0
// 00436775  89580c               mov dword ptr [eax + 0xc], ebx
// 00436778  e8d3e7ffff           call 0x434f50
// 0043677d  5f                   pop edi
// 0043677e  5e                   pop esi
// 0043677f  5b                   pop ebx
// 00436780  c3                   ret 
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