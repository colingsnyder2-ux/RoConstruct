// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005ff8d0  unit: RBX::Mouse  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ff8d0
//
// 005ff8d0  8b442404             mov eax, dword ptr [esp + 4]
// 005ff8d4  56                   push esi
// 005ff8d5  8bf1                 mov esi, ecx
// 005ff8d7  3b86c4010000         cmp eax, dword ptr [esi + 0x1c4]
// 005ff8dd  7412                 je 0x5ff8f1
// 005ff8df  50                   push eax
// 005ff8e0  e86bfeffff           call 0x5ff750
// 005ff8e5  68e0b79700           push 0x97b7e0
// 005ff8ea  8bce                 mov ecx, esi
// 005ff8ec  e80fe2e0ff           call 0x40db00
// 005ff8f1  5e                   pop esi
// 005ff8f2  c20400               ret 4

extern char propertyDescriptor;

struct S
{
    char storage[0x1c4];
    int value;

    void applyValue(int newValue);
    void notify(const void *descriptor);
    void setValue(int newValue);
};

void S::setValue(int newValue)
{
    if (newValue != value)
    {
        applyValue(newValue);
        notify(&propertyDescriptor);
    }
}
