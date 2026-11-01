// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00642f80  unit: RBX::VWidget::?$NonFactoryProduct  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00642f80
//
// 00642f80  51                   push ecx
// 00642f81  56                   push esi
// 00642f82  57                   push edi
// 00642f83  8bf1                 mov esi, ecx
// 00642f85  c744240800000000     mov dword ptr [esp + 8], 0
// 00642f8d  e87effffff           call 0x642f10
// 00642f92  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00642f96  81c644010000         add esi, 0xa0
// 00642f9c  56                   push esi
// 00642f9d  8bcf                 mov ecx, edi
// 00642f9f  ff155c248000         call dword ptr [0x80245c]
// 00642fa5  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00642fa8  89471c               mov dword ptr [edi + 0x1c], eax
// 00642fab  8bc7                 mov eax, edi
// 00642fad  5f                   pop edi
// 00642fae  5e                   pop esi
// 00642faf  59                   pop ecx
// 00642fb0  c20400               ret 4

struct String {
    char data[28];
};

struct Result {
    String text;
    int value;
};

extern void (__thiscall *copyString)(String *, const String *);

struct S {
    char padding[0xa0];
    Result member;

    void update();
    Result f();
};

Result S::f()
{
    volatile int state = 0;
    update();

    Result *source = &member;
    Result result;
    copyString(&result.text, &source->text);
    result.value = source->value;
    return result;
}
