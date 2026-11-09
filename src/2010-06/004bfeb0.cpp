// from server: 100% by Yeetserama
// roc 2010-06 004bfeb0  unit: RBX::Network::VPlayer::?$EventDesc  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004bfeb0
//
// 004bfeb0  64a100000000         mov eax, dword ptr fs:[0]
// 004bfeb6  6aff                 push -1
// 004bfeb8  68a97e9900           push 0x997ea9
// 004bfebd  50                   push eax
// 004bfebe  64892500000000       mov dword ptr fs:[0], esp
// 004bfec5  56                   push esi
// 004bfec6  57                   push edi
// 004bfec7  8bf1                 mov esi, ecx
// 004bfec9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004bfecd  8d44241c             lea eax, [esp + 0x1c]
// 004bfed1  33ff                 xor edi, edi
// 004bfed3  50                   push eax
// 004bfed4  893e                 mov dword ptr [esi], edi
// 004bfed6  51                   push ecx
// 004bfed7  8d4e10               lea ecx, [esi + 0x10]
// 004bfeda  897c2418             mov dword ptr [esp + 0x18], edi
// 004bfede  897e04               mov dword ptr [esi + 4], edi
// 004bfee1  897e08               mov dword ptr [esi + 8], edi
// 004bfee4  e817f9ffff           call 0x4bf800
// 004bfee9  8d4c241c             lea ecx, [esp + 0x1c]
// 004bfeed  897e20               mov dword ptr [esi + 0x20], edi
// 004bfef0  897e24               mov dword ptr [esi + 0x24], edi
// 004bfef3  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004bfefb  ff1500a49e00         call dword ptr [0x9ea400]
// 004bff01  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004bff05  5f                   pop edi
// 004bff06  8bc6                 mov eax, esi
// 004bff08  64890d00000000       mov dword ptr fs:[0], ecx
// 004bff0f  5e                   pop esi
// 004bff10  83c40c               add esp, 0xc
// 004bff13  c22000               ret 0x20
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
