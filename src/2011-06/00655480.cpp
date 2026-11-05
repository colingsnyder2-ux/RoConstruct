// from server: 100% by Yeetserama
// roc 2011-06 00655480  unit: std::D::DU?$char_traits::V?$basic_string::?$sp_counted_impl_p  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00655480
//
// 00655480  6aff                 push -1
// 00655482  686cca9e00           push 0x9eca6c
// 00655487  64a100000000         mov eax, dword ptr fs:[0]
// 0065548d  50                   push eax
// 0065548e  64892500000000       mov dword ptr fs:[0], esp
// 00655495  83ec3c               sub esp, 0x3c
// 00655498  8d442420             lea eax, [esp + 0x20]
// 0065549c  56                   push esi
// 0065549d  50                   push eax
// 0065549e  c744240800000000     mov dword ptr [esp + 8], 0
// 006554a6  e815f8ffff           call 0x654cc0
// 006554ab  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 006554af  51                   push ecx
// 006554b0  50                   push eax
// 006554b1  8d542414             lea edx, [esp + 0x14]
// 006554b5  52                   push edx
// 006554b6  c744245801000000     mov dword ptr [esp + 0x58], 1
// 006554be  ff155004a400         call dword ptr [0xa40450]
// 006554c4  83c410               add esp, 0x10
// 006554c7  8b742450             mov esi, dword ptr [esp + 0x50]
// 006554cb  50                   push eax
// 006554cc  8bce                 mov ecx, esi
// 006554ce  c644244c02           mov byte ptr [esp + 0x4c], 2
// 006554d3  ff15c804a400         call dword ptr [0xa404c8]
// 006554d9  8d4c2408             lea ecx, [esp + 8]
// 006554dd  c744240401000000     mov dword ptr [esp + 4], 1
// 006554e5  c644244801           mov byte ptr [esp + 0x48], 1
// 006554ea  ff15d004a400         call dword ptr [0xa404d0]
// 006554f0  8d4c2424             lea ecx, [esp + 0x24]
// 006554f4  c644244800           mov byte ptr [esp + 0x48], 0
// 006554f9  ff15d004a400         call dword ptr [0xa404d0]
// 006554ff  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00655503  8bc6                 mov eax, esi
// 00655505  5e                   pop esi
// 00655506  64890d00000000       mov dword ptr fs:[0], ecx
// 0065550d  83c448               add esp, 0x48
// 00655510  c3                   ret 
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
