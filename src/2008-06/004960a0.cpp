// from server: 100% by EspClaude
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
