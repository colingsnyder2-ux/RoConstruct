// from server: 97% by EspClaude
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
    unsigned char reserved0[0x34];
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
