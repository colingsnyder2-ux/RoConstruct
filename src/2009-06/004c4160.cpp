// from server: 100% by EspClaude
// roc 2009-06 004c4160  unit: RBX::Network::Players  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c4160
//
// 004c4160  64a100000000         mov eax, dword ptr fs:[0]
// 004c4166  6aff                 push -1
// 004c4168  68f9788600           push 0x8678f9
// 004c416d  50                   push eax
// 004c416e  64892500000000       mov dword ptr fs:[0], esp
// 004c4175  56                   push esi
// 004c4176  57                   push edi
// 004c4177  8bf1                 mov esi, ecx
// 004c4179  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004c417d  8d44241c             lea eax, [esp + 0x1c]
// 004c4181  33ff                 xor edi, edi
// 004c4183  50                   push eax
// 004c4184  893e                 mov dword ptr [esi], edi
// 004c4186  51                   push ecx
// 004c4187  8d4e10               lea ecx, [esi + 0x10]
// 004c418a  897c2418             mov dword ptr [esp + 0x18], edi
// 004c418e  897e04               mov dword ptr [esi + 4], edi
// 004c4191  897e08               mov dword ptr [esi + 8], edi
// 004c4194  e897fcffff           call 0x4c3e30
// 004c4199  8d4c241c             lea ecx, [esp + 0x1c]
// 004c419d  897e20               mov dword ptr [esi + 0x20], edi
// 004c41a0  897e24               mov dword ptr [esi + 0x24], edi
// 004c41a3  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004c41ab  ff15c4e48900         call dword ptr [0x89e4c4]
// 004c41b1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004c41b5  5f                   pop edi
// 004c41b6  8bc6                 mov eax, esi
// 004c41b8  64890d00000000       mov dword ptr fs:[0], ecx
// 004c41bf  5e                   pop esi
// 004c41c0  83c40c               add esp, 0xc
// 004c41c3  c22000               ret 0x20
// copied from an identical function in another client (function ??0S@ns_ROCX000001@@QAE@HUString@1@@Z)

namespace ns_ROCX000001 {
// from server: 98% by king_originala
// roc 2008-06 004960a0  unit: RBX::Network::Players  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004960a0
//
// 004960a0  64a100000000         mov eax, dword ptr fs:[0]
// 004960a6  6aff                 push -1
// 004960a8  68793f7c00           push 0x7c3f79
// 004960ad  50                   push eax
// 004960ae  64892500000000       mov dword ptr fs:[0], esp
// 004960b5  56                   push esi
// 004960b6  57                   push edi
// 004960b7  8bf1                 mov esi, ecx
// 004960b9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004960bd  8d44241c             lea eax, [esp + 0x1c]
// 004960c1  33ff                 xor edi, edi
// 004960c3  50                   push eax
// 004960c4  893e                 mov dword ptr [esi], edi
// 004960c6  51                   push ecx
// 004960c7  8d4e10               lea ecx, [esi + 0x10]
// 004960ca  897c2418             mov dword ptr [esp + 0x18], edi
// 004960ce  897e04               mov dword ptr [esi + 4], edi
// 004960d1  897e08               mov dword ptr [esi + 8], edi
// 004960d4  e887fcffff           call 0x495d60
// 004960d9  8d4c241c             lea ecx, [esp + 0x1c]
// 004960dd  897e20               mov dword ptr [esi + 0x20], edi
// 004960e0  897e24               mov dword ptr [esi + 0x24], edi
// 004960e3  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004960eb  ff1568248000         call dword ptr [0x802468]
// 004960f1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004960f5  5f                   pop edi
// 004960f6  8bc6                 mov eax, esi
// 004960f8  64890d00000000       mov dword ptr fs:[0], ecx
// 004960ff  5e                   pop esi
// 00496100  83c40c               add esp, 0xc
// 00496103  c22000               ret 0x20

struct String;
typedef void (__thiscall *StringDestructor)(String*);
extern StringDestructor destroyString;

struct String {
    unsigned int allocator;
    char storage[16];
    unsigned int length;
    unsigned int capacity;
    ~String();
};

inline String::~String()
{
    destroyString(this);
}

struct Member {
    unsigned int data[4];
    Member(int, const String&);
};

struct Pair2 {
    unsigned int a;
    unsigned int b;
    Pair2() : a(0), b(0) {}
};

struct S {
    unsigned int first;
    Pair2 pair;
    unsigned int padding;
    Member member;
    unsigned int fourth;
    unsigned int fifth;

    S(int, String);
};

S::S(int value, String text)
    : first(0), pair(), member(value, text),
      fourth(0), fifth(0)
{
}
}
