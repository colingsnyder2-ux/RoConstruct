// from server: 100% by EspClaude
// roc 2009-06 0042f470  unit: COutputView  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042f470
//
// 0042f470  56                   push esi
// 0042f471  8bf1                 mov esi, ecx
// 0042f473  e8109a2e00           call 0x718e88
// 0042f478  6886000000           push 0x86
// 0042f47d  8bce                 mov ecx, esi
// 0042f47f  e800a12e00           call 0x719584
// 0042f484  5e                   pop esi
// 0042f485  c3                   ret 
// copied from an identical function in another client (function ?Prepare@COutputView@ns_ROCX000012@@QAEXXZ)

namespace ns_ROCX000012 {
struct COutputView
{
    void Prepare();
    void SetMode(int);
};

void COutputView::Prepare()
{
    Prepare();
    SetMode(134);
}
}
