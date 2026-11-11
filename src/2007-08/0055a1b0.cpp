// from server: 78% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 75% by tajop
// roc 2007-08 0055a1b0  unit: RBX::VLocalBackpack::?$FactoryProduct::Creator  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055a1b0
//
// 0055a1b0  6aff                 push -1
// 0055a1b2  68bb6a7500           push 0x756abb
// 0055a1b7  64a100000000         mov eax, dword ptr fs:[0]
// 0055a1bd  50                   push eax
// 0055a1be  64892500000000       mov dword ptr fs:[0], esp
// 0055a1c5  83ec08               sub esp, 8
// 0055a1c8  c7042400000000       mov dword ptr [esp], 0
// 0055a1cf  6824020000           push 0x224
// 0055a1d4  c644240400           mov byte ptr [esp + 4], 0
// 0055a1d9  ff15d0e67700         call dword ptr [0x77e6d0]
// 0055a1df  83c404               add esp, 4
// 0055a1e2  89442404             mov dword ptr [esp + 4], eax
// 0055a1e6  85c0                 test eax, eax
// 0055a1e8  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0055a1f0  740b                 je 0x55a1fd
// 0055a1f2  6a01                 push 1
// 0055a1f4  8bc8                 mov ecx, eax
// 0055a1f6  e8d5a80700           call 0x5d4ad0
// 0055a1fb  eb02                 jmp 0x55a1ff
// 0055a1fd  33c0                 xor eax, eax
// 0055a1ff  8b0c24               mov ecx, dword ptr [esp]
// 0055a202  56                   push esi
// 0055a203  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0055a207  51                   push ecx
// 0055a208  50                   push eax
// 0055a209  8bce                 mov ecx, esi
// 0055a20b  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0055a213  e8e8feffff           call 0x55a100
// 0055a218  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0055a21c  8bc6                 mov eax, esi
// 0055a21e  5e                   pop esi
// 0055a21f  64890d00000000       mov dword ptr fs:[0], ecx
// 0055a226  83c414               add esp, 0x14
// 0055a229  c3                   ret 

extern "C" __declspec(dllimport) void* __cdecl malloc(unsigned int size);
extern "C" __declspec(dllimport) void __cdecl free(void* p);

struct VLocalBackpack
{
    char pad[0x224];
    VLocalBackpack(int arg);
    static void* operator new(unsigned int size) { return malloc(size); }
    static void operator delete(void* p) { free(p); }
};

struct Deleter
{
};

struct SharedPtr
{
    VLocalBackpack* px;
    void* pn;
    SharedPtr(VLocalBackpack* p, Deleter d);
};

struct Creator
{
    static SharedPtr create();
};

SharedPtr Creator::create()
{
    return SharedPtr(new VLocalBackpack(1), Deleter());
}
