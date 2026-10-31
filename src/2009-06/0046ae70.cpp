// from server: 96% by EspClaude
// from server: 100% by colin
// roc 2008-06 00468520  unit: DxUserInput  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00468520
//
// 00468520  6aff                 push -1
// 00468522  6868367c00           push 0x7c3668
// 00468527  64a100000000         mov eax, dword ptr fs:[0]
// 0046852d  50                   push eax
// 0046852e  64892500000000       mov dword ptr fs:[0], esp
// 00468535  83ec08               sub esp, 8
// 00468538  56                   push esi
// 00468539  57                   push edi
// 0046853a  8bf1                 mov esi, ecx
// 0046853c  8d7e34               lea edi, [esi + 0x34]
// 0046853f  57                   push edi
// 00468540  897c240c             mov dword ptr [esp + 0xc], edi
// 00468544  ff15d4228000         call dword ptr [0x8022d4]
// 0046854a  c644240c01           mov byte ptr [esp + 0xc], 1
// 0046854f  33c9                 xor ecx, ecx
// 00468551  894c2418             mov dword ptr [esp + 0x18], ecx
// 00468555  398e78010000         cmp dword ptr [esi + 0x178], ecx
// 0046855b  7508                 jne 0x468565
// 0046855d  888e92010000         mov byte ptr [esi + 0x192], cl
// 00468563  eb25                 jmp 0x46858a
// 00468565  8a8690010000         mov al, byte ptr [esi + 0x190]
// 0046856b  388692010000         cmp byte ptr [esi + 0x192], al
// 00468571  7417                 je 0x46858a
// 00468573  3ac1                 cmp al, cl
// 00468575  8bce                 mov ecx, esi
// 00468577  740c                 je 0x468585
// 00468579  8b442420             mov eax, dword ptr [esp + 0x20]
// 0046857d  50                   push eax
// 0046857e  e8edf0ffff           call 0x467670
// 00468583  eb05                 jmp 0x46858a
// 00468585  e836fbffff           call 0x4680c0
// 0046858a  57                   push edi
// 0046858b  ff15f4218000         call dword ptr [0x8021f4]
// 00468591  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00468595  5f                   pop edi
// 00468596  5e                   pop esi
// 00468597  64890d00000000       mov dword ptr fs:[0], ecx
// 0046859e  83c414               add esp, 0x14
// 004685a1  c20400               ret 4

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *);

struct LockGuard
{
    void *section;
    bool locked;

    LockGuard(void *);
    ~LockGuard();
};

inline LockGuard::LockGuard(void *p) : section(p)
{
    EnterCriticalSection(section);
    locked = true;
}

inline LockGuard::~LockGuard()
{
    if (locked)
        LeaveCriticalSection(section);
}

struct DxUserInput
{
    char padding0[0x34];
    char criticalSection[0x18];
    char padding1[0x12C];
    int state;
    char padding2[0x14];
    bool requested;
    char padding3;
    bool current;

    void enable(int);
    void disable();
    void update(int);
};

void DxUserInput::update(int argument)
{
    LockGuard lock(criticalSection);

    if (state == 0)
    {
        current = false;
    }
    else if (current != requested)
    {
        if (requested)
            enable(argument);
        else
            disable();
    }
}
