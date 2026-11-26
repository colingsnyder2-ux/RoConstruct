// from server: 100% by Xemicl
// roc 2012-06 00540740  unit: RBX::VObjectValue::?$FactoryProduct::Creator  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00540740
//
// 00540740  64a100000000         mov eax, dword ptr fs:[0]
// 00540746  6aff                 push -1
// 00540748  6889a0ac00           push 0xaca089
// 0054074d  50                   push eax
// 0054074e  64892500000000       mov dword ptr fs:[0], esp
// 00540755  56                   push esi
// 00540756  57                   push edi
// 00540757  8bf1                 mov esi, ecx
// 00540759  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0054075d  8d44241c             lea eax, [esp + 0x1c]
// 00540761  33ff                 xor edi, edi
// 00540763  50                   push eax
// 00540764  893e                 mov dword ptr [esi], edi
// 00540766  51                   push ecx
// 00540767  8d4e10               lea ecx, [esi + 0x10]
// 0054076a  897c2418             mov dword ptr [esp + 0x18], edi
// 0054076e  897e04               mov dword ptr [esi + 4], edi
// 00540771  897e08               mov dword ptr [esi + 8], edi
// 00540774  e807f6ffff           call 0x53fd80
// 00540779  8d4c241c             lea ecx, [esp + 0x1c]
// 0054077d  897e20               mov dword ptr [esi + 0x20], edi
// 00540780  897e24               mov dword ptr [esi + 0x24], edi
// 00540783  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0054078b  ff153c26b200         call dword ptr [0xb2263c]
// 00540791  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00540795  5f                   pop edi
// 00540796  8bc6                 mov eax, esi
// 00540798  64890d00000000       mov dword ptr fs:[0], ecx
// 0054079f  5e                   pop esi
// 005407a0  83c40c               add esp, 0xc
// 005407a3  c22000               ret 0x20
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