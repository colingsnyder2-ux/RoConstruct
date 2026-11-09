// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00411be0  unit: ChatEnter  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00411be0
//
// 00411be0  56                   push esi
// 00411be1  8bf1                 mov esi, ecx
// 00411be3  e89ef02800           call 0x6a0c86
// 00411be8  33c0                 xor eax, eax
// 00411bea  898688000000         mov dword ptr [esi + 0x88], eax
// 00411bf0  c706ace18000         mov dword ptr [esi], 0x80e1ac
// 00411bf6  89868c000000         mov dword ptr [esi + 0x8c], eax
// 00411bfc  898690000000         mov dword ptr [esi + 0x90], eax
// 00411c02  898698000000         mov dword ptr [esi + 0x98], eax
// 00411c08  c7869400000068e08000 mov dword ptr [esi + 0x94], 0x80e068
// 00411c12  89869c000000         mov dword ptr [esi + 0x9c], eax
// 00411c18  8986a0000000         mov dword ptr [esi + 0xa0], eax
// 00411c1e  8986a4000000         mov dword ptr [esi + 0xa4], eax
// 00411c24  8bc6                 mov eax, esi
// 00411c26  5e                   pop esi
// 00411c27  c3                   ret 

struct ChatEnter {
    volatile unsigned long table;
    unsigned char padding[0x84];
    volatile unsigned long field88;
    volatile unsigned long field8c;
    volatile unsigned long field90;
    volatile unsigned long table94;
    volatile unsigned long field98;
    volatile unsigned long field9c;
    volatile unsigned long fielda0;
    volatile unsigned long fielda4;

    void initializeBase();
    ChatEnter* initialize();
};

ChatEnter* ChatEnter::initialize()
{
    initializeBase();
    field88 = 0;
    table = 0x80e1ac;
    field8c = 0;
    field90 = 0;
    field98 = 0;
    table94 = 0x80e068;
    field9c = 0;
    fielda0 = 0;
    fielda4 = 0;
    return this;
}
