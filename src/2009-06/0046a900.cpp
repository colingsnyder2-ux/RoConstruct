// from server: 100% by EspClaude
// from server: 97% by EspClaude
// roc 2009-06 0046a900  unit: DxUserInput  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046a900
//
// 0046a900  6aff                 push -1
// 0046a902  6888328500           push 0x853288
// 0046a907  64a100000000         mov eax, dword ptr fs:[0]
// 0046a90d  50                   push eax
// 0046a90e  64892500000000       mov dword ptr fs:[0], esp
// 0046a915  83ec08               sub esp, 8
// 0046a918  56                   push esi
// 0046a919  57                   push edi
// 0046a91a  8bf1                 mov esi, ecx
// 0046a91c  8d7e2c               lea edi, [esi + 0x2c]
// 0046a91f  57                   push edi
// 0046a920  897c240c             mov dword ptr [esp + 0xc], edi
// 0046a924  ff15a8e18900         call dword ptr [0x89e1a8]
// 0046a92a  c644240c01           mov byte ptr [esp + 0xc], 1
// 0046a92f  8a442420             mov al, byte ptr [esp + 0x20]
// 0046a933  8bce                 mov ecx, esi
// 0046a935  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0046a93d  888689010000         mov byte ptr [esi + 0x189], al
// 0046a943  e858f3ffff           call 0x469ca0
// 0046a948  57                   push edi
// 0046a949  ff15ace18900         call dword ptr [0x89e1ac]
// 0046a94f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0046a953  5f                   pop edi
// 0046a954  5e                   pop esi
// 0046a955  64890d00000000       mov dword ptr fs:[0], ecx
// 0046a95c  83c414               add esp, 0x14
// 0046a95f  c20400               ret 4

// from server: 100% by colin
// roc 2008-06 00468050  unit: DxUserInput  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00468050
//
// 00468050  6aff                 push -1
// 00468052  6868367c00           push 0x7c3668
// 00468057  64a100000000         mov eax, dword ptr fs:[0]
// 0046805d  50                   push eax
// 0046805e  64892500000000       mov dword ptr fs:[0], esp
// 00468065  83ec08               sub esp, 8
// 00468068  56                   push esi
// 00468069  57                   push edi
// 0046806a  8bf1                 mov esi, ecx
// 0046806c  8d7e34               lea edi, [esi + 0x34]
// 0046806f  57                   push edi
// 00468070  897c240c             mov dword ptr [esp + 0xc], edi
// 00468074  ff15d4228000         call dword ptr [0x8022d4]
// 0046807a  c644240c01           mov byte ptr [esp + 0xc], 1
// 0046807f  8a442420             mov al, byte ptr [esp + 0x20]
// 00468083  8bce                 mov ecx, esi
// 00468085  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0046808d  888691010000         mov byte ptr [esi + 0x191], al
// 00468093  e858f7ffff           call 0x4677f0
// 00468098  57                   push edi
// 00468099  ff15f4218000         call dword ptr [0x8021f4]
// 0046809f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004680a3  5f                   pop edi
// 004680a4  5e                   pop esi
// 004680a5  64890d00000000       mov dword ptr fs:[0], ecx
// 004680ac  83c414               add esp, 0x14
// 004680af  c20400               ret 4

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct Guard {
    void* section;
    bool locked;

    explicit Guard(void* p) : section(p)
    {
        EnterCriticalSection(section);
        locked = true;
    }

    ~Guard()
    {
        if (locked)
            LeaveCriticalSection(section);
    }
};

struct S {
    unsigned char reserved0[0x2c];
    unsigned char criticalSection[0x18];
    unsigned char reserved1[0x145];
    bool enabled;

    void update();
    void f(bool value);
};

void S::f(bool value)
{
    Guard guard(criticalSection);
    enabled = value;
    update();
}
