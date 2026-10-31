// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005872a0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005872a0
//
// 005872a0  8b4104               mov eax, dword ptr [ecx + 4]
// 005872a3  85c0                 test eax, eax
// 005872a5  7405                 je 0x5872ac
// 005872a7  83c014               add eax, 0x14
// 005872aa  eb02                 jmp 0x5872ae
// 005872ac  33c0                 xor eax, eax
// 005872ae  8b542404             mov edx, dword ptr [esp + 4]
// 005872b2  8b0a                 mov ecx, dword ptr [edx]
// 005872b4  56                   push esi
// 005872b5  8b31                 mov esi, dword ptr [ecx]
// 005872b7  83c204               add edx, 4
// 005872ba  52                   push edx
// 005872bb  50                   push eax
// 005872bc  8b4614               mov eax, dword ptr [esi + 0x14]
// 005872bf  ffd0                 call eax
// 005872c1  5e                   pop esi
// 005872c2  c20400               ret 4

struct Callback {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void invoke(void *, void *);
};

struct Argument {
    Callback *callback;
    unsigned char data[1];
};

struct S {
    void *reserved;
    unsigned char *object;
    void f(Argument *);
};

void S::f(Argument *arg)
{
    void *p = object ? object + 20 : 0;
    arg->callback->invoke(p, arg->data);
}
