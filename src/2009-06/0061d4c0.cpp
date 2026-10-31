// from server: 88% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0058c5e0  unit: RBX::ChangeHistoryService  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058c5e0
//
// 0058c5e0  56                   push esi
// 0058c5e1  8bf1                 mov esi, ecx
// 0058c5e3  80be6501000000       cmp byte ptr [esi + 0x165], 0
// 0058c5ea  7424                 je 0x58c610
// 0058c5ec  6848198300           push 0x831948
// 0058c5f1  e8cafcffff           call 0x58c2c0
// 0058c5f6  83be5001000001       cmp dword ptr [esi + 0x150], 1
// 0058c5fd  7611                 jbe 0x58c610
// 0058c5ff  90                   nop 
// 0058c600  8bce                 mov ecx, esi
// 0058c602  e879f9ffff           call 0x58bf80
// 0058c607  83be5001000001       cmp dword ptr [esi + 0x150], 1
// 0058c60e  77f0                 ja 0x58c600
// 0058c610  5e                   pop esi
// 0058c611  c3                   ret 

struct S {
    char padding0[0x150];
    unsigned int count;
    char padding1[0x11];
    bool enabled;

    void prepare(const char*);
    void step();
    void f();
};

void S::f()
{
    if (enabled) {
        prepare("base");
        while (count > 1)
            step();
    }
}
