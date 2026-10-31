// from server: 90% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006423e0  unit: RBX::VerbWidget  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006423e0
//
// 006423e0  56                   push esi
// 006423e1  8bf1                 mov esi, ecx
// 006423e3  8b06                 mov eax, dword ptr [esi]
// 006423e5  8b5054               mov edx, dword ptr [eax + 0x54]
// 006423e8  ffd2                 call edx
// 006423ea  84c0                 test al, al
// 006423ec  7421                 je 0x64240f
// 006423ee  83be4801000000       cmp dword ptr [esi + 0x148], 0
// 006423f5  7418                 je 0x64240f
// 006423f7  8b8e48010000         mov ecx, dword ptr [esi + 0x148]
// 006423fd  8b01                 mov eax, dword ptr [ecx]
// 006423ff  8b5008               mov edx, dword ptr [eax + 8]
// 00642402  ffd2                 call edx
// 00642404  84c0                 test al, al
// 00642406  7407                 je 0x64240f
// 00642408  b801000000           mov eax, 1
// 0064240d  5e                   pop esi
// 0064240e  c3                   ret 
// 0064240f  33c0                 xor eax, eax
// 00642411  5e                   pop esi
// 00642412  c3                   ret 

struct Action {
    virtual void slot0();
    virtual void slot1();
    virtual bool enabled();
};

struct Widget {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual bool enabled();

    char padding[0x144];
    Action* action;

    int check();
};

int Widget::check()
{
    if (enabled() && action && action->enabled())
        return 1;
    return 0;
}
