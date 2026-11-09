// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0042ef10  unit: CMainFrame  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042ef10
//
// 0042ef10  56                   push esi
// 0042ef11  8bf1                 mov esi, ecx
// 0042ef13  e8501d2700           call 0x6a0c68
// 0042ef18  80bef800000000       cmp byte ptr [esi + 0xf8], 0
// 0042ef1f  7411                 je 0x42ef32
// 0042ef21  80befa00000000       cmp byte ptr [esi + 0xfa], 0
// 0042ef28  7508                 jne 0x42ef32
// 0042ef2a  8b442408             mov eax, dword ptr [esp + 8]
// 0042ef2e  83481803             or dword ptr [eax + 0x18], 3
// 0042ef32  5e                   pop esi
// 0042ef33  c20400               ret 4

struct Message {
    char padding[0x18];
    unsigned int flags;
};

struct CMainFrame {
    char padding[0xFC];
    unsigned char enabled;
    unsigned char reserved;
    unsigned char blocked;

    void helper();
    void f(Message* message);
};

void CMainFrame::f(Message* message)
{
    helper();
    if (enabled && !blocked)
        message->flags |= 3;
}
