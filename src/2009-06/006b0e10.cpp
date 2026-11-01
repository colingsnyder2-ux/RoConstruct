// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0060cc00  unit: RBX::BallBlockContact  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060cc00
//
// 0060cc00  8b442408             mov eax, dword ptr [esp + 8]
// 0060cc04  56                   push esi
// 0060cc05  8bf1                 mov esi, ecx
// 0060cc07  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0060cc0b  50                   push eax
// 0060cc0c  51                   push ecx
// 0060cc0d  e81eb1fdff           call 0x5e7d30
// 0060cc12  83c408               add esp, 8
// 0060cc15  85c0                 test eax, eax
// 0060cc17  7409                 je 0x60cc22
// 0060cc19  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060cc1c  50                   push eax
// 0060cc1d  e85ec6fdff           call 0x5e9280
// 0060cc22  5e                   pop esi
// 0060cc23  c20800               ret 8

struct Receiver {
    void apply(void* value);
};

extern "C" void* __cdecl lookup(void* first, void* second);

struct S {
    int reserved;
    Receiver* receiver;

    void f(void* first, void* second);
};

void S::f(void* first, void* second)
{
    void* value = lookup(first, second);
    if (value)
        receiver->apply(value);
}
