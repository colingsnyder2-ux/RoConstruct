// from server: 75% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0045ead0  unit: CRobloxWnd  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045ead0
//
// 0045ead0  56                   push esi
// 0045ead1  8bf1                 mov esi, ecx
// 0045ead3  57                   push edi
// 0045ead4  8bbea4000000         mov edi, dword ptr [esi + 0xa4]
// 0045eada  393df4ef9600         cmp dword ptr [0x96eff4], edi
// 0045eae0  7412                 je 0x45eaf4
// 0045eae2  8b07                 mov eax, dword ptr [edi]
// 0045eae4  8b9098000000         mov edx, dword ptr [eax + 0x98]
// 0045eaea  8bcf                 mov ecx, edi
// 0045eaec  ffd2                 call edx
// 0045eaee  893df4ef9600         mov dword ptr [0x96eff4], edi
// 0045eaf4  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0045eaf7  85c9                 test ecx, ecx
// 0045eaf9  7407                 je 0x45eb02
// 0045eafb  e8a003fcff           call 0x41eea0
// 0045eb00  eb02                 jmp 0x45eb04
// 0045eb02  33c0                 xor eax, eax
// 0045eb04  a3744d9700           mov dword ptr [0x974d74], eax
// 0045eb09  8b86b4000000         mov eax, dword ptr [esi + 0xb4]
// 0045eb0f  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0045eb12  50                   push eax
// 0045eb13  e8c86b1100           call 0x5756e0
// 0045eb18  5f                   pop edi
// 0045eb19  c705744d970000000000 mov dword ptr [0x974d74], 0
// 0045eb23  5e                   pop esi
// 0045eb24  c3                   ret 

struct Context;

struct ContextVTable {
    void *unused[38];
    void (__thiscall *activate)(Context *);
};

struct Context {
    ContextVTable *vtable;
};

struct Service {
    void *get();
    void perform(unsigned int);
};

extern Context *currentContext;
extern void *activeObject;

struct CRobloxWnd {
    char reserved0[0x70];
    Service *service;
    char reserved1[0x30];
    Context *context;
    char reserved2[0x0C];
    unsigned int argument;

    void f();
};

void CRobloxWnd::f()
{
    Context *selected = context;
    if (currentContext != selected) {
        selected->vtable->activate(selected);
        currentContext = selected;
    }

    void *result;
    if (service)
        result = service->get();
    else
        result = 0;

    activeObject = result;
    service->perform(argument);
    activeObject = 0;
}
