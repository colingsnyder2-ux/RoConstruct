// from server: 100% by Xemicl
// roc 2012-06 005248b0  unit: RBX::Camera::W4CameraMode::?$EnumDesc  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005248b0
//
// 005248b0  6aff                 push -1
// 005248b2  68c8b3aa00           push 0xaab3c8
// 005248b7  64a100000000         mov eax, dword ptr fs:[0]
// 005248bd  50                   push eax
// 005248be  64892500000000       mov dword ptr fs:[0], esp
// 005248c5  51                   push ecx
// 005248c6  56                   push esi
// 005248c7  8bf1                 mov esi, ecx
// 005248c9  8d4608               lea eax, [esi + 8]
// 005248cc  50                   push eax
// 005248cd  83ec30               sub esp, 0x30
// 005248d0  8d54244c             lea edx, [esp + 0x4c]
// 005248d4  8bcc                 mov ecx, esp
// 005248d6  89642438             mov dword ptr [esp + 0x38], esp
// 005248da  52                   push edx
// 005248db  c744244800000000     mov dword ptr [esp + 0x48], 0
// 005248e3  e8c8cfffff           call 0x5218b0
// 005248e8  b92cc4d700           mov ecx, 0xd7c42c
// 005248ed  e83eeeffff           call 0x523730
// 005248f2  0fb6c0               movzx eax, al
// 005248f5  f7d8                 neg eax
// 005248f7  1bc0                 sbb eax, eax
// 005248f9  252cc4d700           and eax, 0xd7c42c
// 005248fe  8d4c241c             lea ecx, [esp + 0x1c]
// 00524902  8906                 mov dword ptr [esi], eax
// 00524904  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0052490c  e83f92ffff           call 0x51db50
// 00524911  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00524915  64890d00000000       mov dword ptr fs:[0], ecx
// 0052491c  5e                   pop esi
// 0052491d  83c410               add esp, 0x10
// 00524920  c23000               ret 0x30
// copied from an identical function in another client (function ?init@Holder@RBX@@QAEXUItem@2@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct Inner {
    char d[0x2c];
    ~Inner();
};
struct Item {
    int key;
    Inner inner;
    Item(const Item&);
};
class Registry {
public:
    bool add(Item item, void* slot);
};
extern Registry registry;
struct Holder {
    Registry* reg;
    int x;
    int slot;
    void init(Item item);
};
void Holder::init(Item item)
{
    reg = registry.add(item, &slot) ? &registry : 0;
}
}