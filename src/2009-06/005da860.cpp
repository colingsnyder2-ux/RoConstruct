// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0055d0b0  unit: RBX::MD5HasherImpl  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055d0b0
//
// 0055d0b0  6aff                 push -1
// 0055d0b2  684ce87c00           push 0x7ce84c
// 0055d0b7  64a100000000         mov eax, dword ptr fs:[0]
// 0055d0bd  50                   push eax
// 0055d0be  64892500000000       mov dword ptr fs:[0], esp
// 0055d0c5  83ec3c               sub esp, 0x3c
// 0055d0c8  8d442420             lea eax, [esp + 0x20]
// 0055d0cc  56                   push esi
// 0055d0cd  50                   push eax
// 0055d0ce  c744240800000000     mov dword ptr [esp + 8], 0
// 0055d0d6  e8e5f3ffff           call 0x55c4c0
// 0055d0db  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0055d0df  51                   push ecx
// 0055d0e0  50                   push eax
// 0055d0e1  8d542414             lea edx, [esp + 0x14]
// 0055d0e5  52                   push edx
// 0055d0e6  c744245801000000     mov dword ptr [esp + 0x58], 1
// 0055d0ee  ff15e4238000         call dword ptr [0x8023e4]
// 0055d0f4  83c410               add esp, 0x10
// 0055d0f7  8b742450             mov esi, dword ptr [esp + 0x50]
// 0055d0fb  50                   push eax
// 0055d0fc  8bce                 mov ecx, esi
// 0055d0fe  c644244c02           mov byte ptr [esp + 0x4c], 2
// 0055d103  ff155c248000         call dword ptr [0x80245c]
// 0055d109  8d4c2408             lea ecx, [esp + 8]
// 0055d10d  c744240401000000     mov dword ptr [esp + 4], 1
// 0055d115  c644244801           mov byte ptr [esp + 0x48], 1
// 0055d11a  ff1568248000         call dword ptr [0x802468]
// 0055d120  8d4c2424             lea ecx, [esp + 0x24]
// 0055d124  c644244800           mov byte ptr [esp + 0x48], 0
// 0055d129  ff1568248000         call dword ptr [0x802468]
// 0055d12f  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0055d133  8bc6                 mov eax, esi
// 0055d135  5e                   pop esi
// 0055d136  64890d00000000       mov dword ptr fs:[0], ecx
// 0055d13d  83c448               add esp, 0x48
// 0055d140  c3                   ret 

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
