// from server: 100% by Yeetserama
// roc 2010-06 0062c130  unit: RBX::VProtectedString::?$sp_counted_impl_p  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0062c130
//
// 0062c130  6aff                 push -1
// 0062c132  68dcb69900           push 0x99b6dc
// 0062c137  64a100000000         mov eax, dword ptr fs:[0]
// 0062c13d  50                   push eax
// 0062c13e  64892500000000       mov dword ptr fs:[0], esp
// 0062c145  83ec3c               sub esp, 0x3c
// 0062c148  8d442420             lea eax, [esp + 0x20]
// 0062c14c  56                   push esi
// 0062c14d  50                   push eax
// 0062c14e  c744240800000000     mov dword ptr [esp + 8], 0
// 0062c156  e855fbffff           call 0x62bcb0
// 0062c15b  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0062c15f  51                   push ecx
// 0062c160  50                   push eax
// 0062c161  8d542414             lea edx, [esp + 0x14]
// 0062c165  52                   push edx
// 0062c166  c744245801000000     mov dword ptr [esp + 0x58], 1
// 0062c16e  ff1588a49e00         call dword ptr [0x9ea488]
// 0062c174  83c410               add esp, 0x10
// 0062c177  8b742450             mov esi, dword ptr [esp + 0x50]
// 0062c17b  50                   push eax
// 0062c17c  8bce                 mov ecx, esi
// 0062c17e  c644244c02           mov byte ptr [esp + 0x4c], 2
// 0062c183  ff150ca49e00         call dword ptr [0x9ea40c]
// 0062c189  8d4c2408             lea ecx, [esp + 8]
// 0062c18d  c744240401000000     mov dword ptr [esp + 4], 1
// 0062c195  c644244801           mov byte ptr [esp + 0x48], 1
// 0062c19a  ff1500a49e00         call dword ptr [0x9ea400]
// 0062c1a0  8d4c2424             lea ecx, [esp + 0x24]
// 0062c1a4  c644244800           mov byte ptr [esp + 0x48], 0
// 0062c1a9  ff1500a49e00         call dword ptr [0x9ea400]
// 0062c1af  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0062c1b3  8bc6                 mov eax, esi
// 0062c1b5  5e                   pop esi
// 0062c1b6  64890d00000000       mov dword ptr fs:[0], ecx
// 0062c1bd  83c448               add esp, 0x48
// 0062c1c0  c3                   ret 
// copied from an identical function in another client (function ?sub_55D0B0@ns_ROCX000001@@YA?AUS@1@PBD@Z)

namespace ns_ROCX000001 {
// from server: 100% by king_originala
struct S
{
    char storage[28];

    S(const S &);
    ~S();
};

typedef S *(__thiscall *CopyFunction)(S *, const S &);
typedef void (__thiscall *DestroyFunction)(S *);
typedef S (__cdecl *ConcatFunction)(const S &, const char *);

extern CopyFunction copyFunction;
extern DestroyFunction destroyFunction;
extern ConcatFunction concatenate;
extern S __cdecl construct();

__forceinline S::S(const S &other)
{
    copyFunction(this, other);
}

__forceinline S::~S()
{
    destroyFunction(this);
}

S __cdecl sub_55D0B0(const char *text)
{
    return static_cast<const S &>(concatenate(construct(), text));
}
}
