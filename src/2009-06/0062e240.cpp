// from server: 79% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005a3390  unit: RBX::VFlag::?$FactoryProduct::Creator  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a3390
//
// 005a3390  56                   push esi
// 005a3391  57                   push edi
// 005a3392  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005a3396  57                   push edi
// 005a3397  e8b4eaeeff           call 0x491e50
// 005a339c  8bf0                 mov esi, eax
// 005a339e  83c404               add esp, 4
// 005a33a1  85f6                 test esi, esi
// 005a33a3  7419                 je 0x5a33be
// 005a33a5  3bfe                 cmp edi, esi
// 005a33a7  740c                 je 0x5a33b5
// 005a33a9  56                   push esi
// 005a33aa  8bcf                 mov ecx, edi
// 005a33ac  e82ff7e7ff           call 0x422ae0
// 005a33b1  84c0                 test al, al
// 005a33b3  7409                 je 0x5a33be
// 005a33b5  8b86e4020000         mov eax, dword ptr [esi + 0x2e4]
// 005a33bb  5f                   pop edi
// 005a33bc  5e                   pop esi
// 005a33bd  c3                   ret 
// 005a33be  5f                   pop edi
// 005a33bf  33c0                 xor eax, eax
// 005a33c1  5e                   pop esi
// 005a33c2  c3                   ret 

struct S {
    char padding[0x2e4];
    void* value;
    bool f(S* node);
};

extern S* func_00491e50(S* p);

void* func_005a3390(S* p)
{
    S* q = func_00491e50(p);
    if (q && (p == q || p->f(q)))
        return q->value;
    return 0;
}
