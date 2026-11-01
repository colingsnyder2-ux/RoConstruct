// from server: 100% by EspClaude
// roc 2009-06 006743d0  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006743d0
//
// 006743d0  56                   push esi
// 006743d1  8bf1                 mov esi, ecx
// 006743d3  e838f8ffff           call 0x673c10
// 006743d8  85c0                 test eax, eax
// 006743da  7407                 je 0x6743e3
// 006743dc  8bc8                 mov ecx, eax
// 006743de  e87dbefeff           call 0x660260
// 006743e3  8bce                 mov ecx, esi
// 006743e5  e856f9ffff           call 0x673d40
// 006743ea  85c0                 test eax, eax
// 006743ec  7407                 je 0x6743f5
// 006743ee  8bc8                 mov ecx, eax
// 006743f0  e86bbefeff           call 0x660260
// 006743f5  8bce                 mov ecx, esi
// 006743f7  e8e4f6ffff           call 0x673ae0
// 006743fc  85c0                 test eax, eax
// 006743fe  7407                 je 0x674407
// 00674400  8bc8                 mov ecx, eax
// 00674402  e859befeff           call 0x660260
// 00674407  8bce                 mov ecx, esi
// 00674409  e862faffff           call 0x673e70
// 0067440e  85c0                 test eax, eax
// 00674410  7407                 je 0x674419
// 00674412  8bc8                 mov ecx, eax
// 00674414  e847befeff           call 0x660260
// 00674419  8bce                 mov ecx, esi
// 0067441b  e880fbffff           call 0x673fa0
// 00674420  5e                   pop esi
// 00674421  85c0                 test eax, eax
// 00674423  7407                 je 0x67442c
// 00674425  8bc8                 mov ecx, eax
// 00674427  e934befeff           jmp 0x660260
// 0067442c  c3                   ret 
// copied from an identical function in another client (function ?update@S@ns_ROCX000019@@QAEXXZ)

namespace ns_ROCX000019 {
struct Item {
    void update();
};

struct S {
    Item* first();
    Item* second();
    Item* third();
    Item* fourth();
    Item* fifth();
    void update();
};

void S::update()
{
    Item* p = first();
    if (p)
        p->update();

    p = second();
    if (p)
        p->update();

    p = third();
    if (p)
        p->update();

    p = fourth();
    if (p)
        p->update();

    p = fifth();
    if (p)
        p->update();
}
}
