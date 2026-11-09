// from server: 100% by EspClaude
// from server: 93% by king_originala
// roc 2008-06 0045eaa0  unit: CRobloxWnd  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045eaa0
//
// 0045eaa0  56                   push esi
// 0045eaa1  8bf1                 mov esi, ecx
// 0045eaa3  837e5c02             cmp dword ptr [esi + 0x5c], 2
// 0045eaa7  7507                 jne 0x45eab0
// 0045eaa9  e862feffff           call 0x45e910
// 0045eaae  eb05                 jmp 0x45eab5
// 0045eab0  e8ebfcffff           call 0x45e7a0
// 0045eab5  84c0                 test al, al
// 0045eab7  7510                 jne 0x45eac9
// 0045eab9  8b4e78               mov ecx, dword ptr [esi + 0x78]
// 0045eabc  85c9                 test ecx, ecx
// 0045eabe  7409                 je 0x45eac9
// 0045eac0  8d4654               lea eax, [esi + 0x54]
// 0045eac3  50                   push eax
// 0045eac4  e8176b0f00           call 0x5555e0
// 0045eac9  5e                   pop esi
// 0045eaca  c3                   ret 

struct Data { int data[2]; };
struct Pad { char padding0[0x54]; };
struct Receiver {
    void notify(Data&);
};

struct S : Pad, Data {
    int mode;
    char padding1[0x18];
    Receiver* receiver;

    bool first();
    bool second();
    void f();
};

void S::f()
{
    bool handled;
    if (mode == 2)
        handled = first();
    else
        handled = second();

    if (!handled && receiver)
        receiver->notify(*this);
}
