// from server: 100% by nuck16
// roc 2009-12 00974a80  unit: seg_00970000  size: 57 bytes
//
// 00974a80  56                   push esi
// 00974a81  33f6                 xor esi, esi
// 00974a83  56                   push esi
// 00974a84  6a0f                 push 0xf
// 00974a86  33c9                 xor ecx, ecx
// 00974a88  51                   push ecx
// 00974a89  b8a0616c00           mov eax, 0x6c61a0
// 00974a8e  50                   push eax
// 00974a8f  56                   push esi
// 00974a90  bae05c6c00           mov edx, 0x6c5ce0
// 00974a95  52                   push edx
// 00974a96  6858aa9a00           push 0x9aaa58
// 00974a9b  68c8719d00           push 0x9d71c8
// 00974aa0  b93823b900           mov ecx, 0xb92338
// 00974aa5  e8f613d5ff           call 0x6c5ea0
// 00974aaa  68e05a9800           push 0x985ae0
// 00974aaf  e875fee7ff           call 0x7f4929
// 00974ab4  83c404               add esp, 4
// 00974ab7  5e                   pop esi
// 00974ab8  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
    void m1();
};


struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("ParallelPhysics", "Performance", &Owner::m0, &Owner::m1, 15, 0);
