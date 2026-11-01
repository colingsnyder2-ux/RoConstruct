// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004597f0  unit: CRobloxView  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004597f0
//
// 004597f0  83b9d801000000       cmp dword ptr [ecx + 0x20c], 0
// 004597f7  6a01                 push 1
// 004597f9  0f94c0               sete al
// 004597fc  0fb6d0               movzx edx, al
// 004597ff  52                   push edx
// 00459800  e89bfeffff           call 0x4596a0
// 00459805  c3                   ret 

struct CRobloxView {
    char padding[0x20c];
    int state;

    void setState(bool enabled, int notify);
    void toggleState();
};

void CRobloxView::toggleState()
{
    setState(state == 0, 1);
}
