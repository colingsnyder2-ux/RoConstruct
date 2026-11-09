// from server: 100% by Yeetserama
// roc 2011-06 004c7140  unit: RBX::MeshAdapter  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004c7140
//
// 004c7140  64a100000000         mov eax, dword ptr fs:[0]
// 004c7146  6aff                 push -1
// 004c7148  68c912a000           push 0xa012c9
// 004c714d  50                   push eax
// 004c714e  64892500000000       mov dword ptr fs:[0], esp
// 004c7155  56                   push esi
// 004c7156  57                   push edi
// 004c7157  8bf1                 mov esi, ecx
// 004c7159  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004c715d  8d44241c             lea eax, [esp + 0x1c]
// 004c7161  33ff                 xor edi, edi
// 004c7163  50                   push eax
// 004c7164  893e                 mov dword ptr [esi], edi
// 004c7166  51                   push ecx
// 004c7167  8d4e10               lea ecx, [esi + 0x10]
// 004c716a  897c2418             mov dword ptr [esp + 0x18], edi
// 004c716e  897e04               mov dword ptr [esi + 4], edi
// 004c7171  897e08               mov dword ptr [esi + 8], edi
// 004c7174  e827f7ffff           call 0x4c68a0
// 004c7179  8d4c241c             lea ecx, [esp + 0x1c]
// 004c717d  897e20               mov dword ptr [esi + 0x20], edi
// 004c7180  897e24               mov dword ptr [esi + 0x24], edi
// 004c7183  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004c718b  ff15d004a400         call dword ptr [0xa404d0]
// 004c7191  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004c7195  5f                   pop edi
// 004c7196  8bc6                 mov eax, esi
// 004c7198  64890d00000000       mov dword ptr fs:[0], ecx
// 004c719f  5e                   pop esi
// 004c71a0  83c40c               add esp, 0xc
// 004c71a3  c22000               ret 0x20
// copied from an identical function in another client (function ??0S@ns_ROCX000016@@QAE@HUString@1@@Z)

namespace ns_ROCX000016 {
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
