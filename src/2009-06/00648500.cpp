// from server: 90% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005bd330  unit: VStockSound::?$FactoryProduct  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bd330
//
// 005bd330  8b442404             mov eax, dword ptr [esp + 4]
// 005bd334  8b00                 mov eax, dword ptr [eax]
// 005bd336  56                   push esi
// 005bd337  8bf1                 mov esi, ecx
// 005bd339  3b8670010000         cmp eax, dword ptr [esi + 0x170]
// 005bd33f  7417                 je 0x5bd358
// 005bd341  6894719700           push 0x977194
// 005bd346  898670010000         mov dword ptr [esi + 0x170], eax
// 005bd34c  e8af07e5ff           call 0x40db00
// 005bd351  8bce                 mov ecx, esi
// 005bd353  e828b5ffff           call 0x5b8880
// 005bd358  5e                   pop esi
// 005bd359  c20400               ret 4

extern int property;

struct S {
    char padding[0x170];
    int value;

    void setValue(const int& v);
    void notify(const int* p);
    void changed();
};

void S::setValue(const int& v)
{
    if (v != value) {
        value = v;
        notify(&property);
        changed();
    }
}
