// from server: 100% by EspClaude
// roc 2009-06 00525c40  unit: RBX::ViewRbxGfx  size: 250 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00525c40
//
// 00525c40  6aff                 push -1
// 00525c42  68eee78500           push 0x85e7ee
// 00525c47  64a100000000         mov eax, dword ptr fs:[0]
// 00525c4d  50                   push eax
// 00525c4e  64892500000000       mov dword ptr fs:[0], esp
// 00525c55  51                   push ecx
// 00525c56  53                   push ebx
// 00525c57  56                   push esi
// 00525c58  8bf1                 mov esi, ecx
// 00525c5a  57                   push edi
// 00525c5b  8974240c             mov dword ptr [esp + 0xc], esi
// 00525c5f  8b460c               mov eax, dword ptr [esi + 0xc]
// 00525c62  8b3da4e18900         mov edi, dword ptr [0x89e1a4]
// 00525c68  33db                 xor ebx, ebx
// 00525c6a  c744241802000000     mov dword ptr [esp + 0x18], 2
// 00525c72  3bc3                 cmp eax, ebx
// 00525c74  7424                 je 0x525c9a
// 00525c76  83c004               add eax, 4
// 00525c79  50                   push eax
// 00525c7a  ffd7                 call edi
// 00525c7c  85c0                 test eax, eax
// 00525c7e  7517                 jne 0x525c97
// 00525c80  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00525c83  e8f8f0f1ff           call 0x444d80
// 00525c88  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00525c8b  3bcb                 cmp ecx, ebx
// 00525c8d  7408                 je 0x525c97
// 00525c8f  8b01                 mov eax, dword ptr [ecx]
// 00525c91  8b10                 mov edx, dword ptr [eax]
// 00525c93  6a01                 push 1
// 00525c95  ffd2                 call edx
// 00525c97  895e0c               mov dword ptr [esi + 0xc], ebx
// 00525c9a  8b4608               mov eax, dword ptr [esi + 8]
// 00525c9d  c644241801           mov byte ptr [esp + 0x18], 1
// 00525ca2  3bc3                 cmp eax, ebx
// 00525ca4  7424                 je 0x525cca
// 00525ca6  83c004               add eax, 4
// 00525ca9  50                   push eax
// 00525caa  ffd7                 call edi
// 00525cac  85c0                 test eax, eax
// 00525cae  7517                 jne 0x525cc7
// 00525cb0  8b4e08               mov ecx, dword ptr [esi + 8]
// 00525cb3  e8c8f0f1ff           call 0x444d80
// 00525cb8  8b4e08               mov ecx, dword ptr [esi + 8]
// 00525cbb  3bcb                 cmp ecx, ebx
// 00525cbd  7408                 je 0x525cc7
// 00525cbf  8b01                 mov eax, dword ptr [ecx]
// 00525cc1  8b10                 mov edx, dword ptr [eax]
// 00525cc3  6a01                 push 1
// 00525cc5  ffd2                 call edx
// 00525cc7  895e08               mov dword ptr [esi + 8], ebx
// 00525cca  8b4604               mov eax, dword ptr [esi + 4]
// 00525ccd  885c2418             mov byte ptr [esp + 0x18], bl
// 00525cd1  3bc3                 cmp eax, ebx
// 00525cd3  7424                 je 0x525cf9
// 00525cd5  83c004               add eax, 4
// 00525cd8  50                   push eax
// 00525cd9  ffd7                 call edi
// 00525cdb  85c0                 test eax, eax
// 00525cdd  7517                 jne 0x525cf6
// 00525cdf  8b4e04               mov ecx, dword ptr [esi + 4]
// 00525ce2  e899f0f1ff           call 0x444d80
// 00525ce7  8b4e04               mov ecx, dword ptr [esi + 4]
// 00525cea  3bcb                 cmp ecx, ebx
// 00525cec  7408                 je 0x525cf6
// 00525cee  8b01                 mov eax, dword ptr [ecx]
// 00525cf0  8b10                 mov edx, dword ptr [eax]
// 00525cf2  6a01                 push 1
// 00525cf4  ffd2                 call edx
// 00525cf6  895e04               mov dword ptr [esi + 4], ebx
// 00525cf9  8b06                 mov eax, dword ptr [esi]
// 00525cfb  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00525d03  3bc3                 cmp eax, ebx
// 00525d05  7421                 je 0x525d28
// 00525d07  83c004               add eax, 4
// 00525d0a  50                   push eax
// 00525d0b  ffd7                 call edi
// 00525d0d  85c0                 test eax, eax
// 00525d0f  7515                 jne 0x525d26
// 00525d11  8b0e                 mov ecx, dword ptr [esi]
// 00525d13  e868f0f1ff           call 0x444d80
// 00525d18  8b0e                 mov ecx, dword ptr [esi]
// 00525d1a  3bcb                 cmp ecx, ebx
// 00525d1c  7408                 je 0x525d26
// 00525d1e  8b01                 mov eax, dword ptr [ecx]
// 00525d20  8b10                 mov edx, dword ptr [eax]
// 00525d22  6a01                 push 1
// 00525d24  ffd2                 call edx
// 00525d26  891e                 mov dword ptr [esi], ebx
// 00525d28  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00525d2c  5f                   pop edi
// 00525d2d  5e                   pop esi
// 00525d2e  5b                   pop ebx
// 00525d2f  64890d00000000       mov dword ptr fs:[0], ecx
// 00525d36  83c410               add esp, 0x10
// 00525d39  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX00001c@@QAE@XZ)

namespace ns_ROCX00001c {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long *);

struct Control
{
    virtual ~Control();
    volatile long references;
    void dispose();
};

struct Shared
{
    Control *control;
    ~Shared();
};

struct S
{
    Shared a;
    Shared b;
    Shared c;
    Shared d;
    ~S();
};

__forceinline Shared::~Shared()
{
    if (control)
    {
        if (InterlockedDecrement(&control->references) == 0)
        {
            control->dispose();
            delete control;
        }
        control = 0;
    }
}

S::~S()
{
}
}
