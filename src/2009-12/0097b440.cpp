// from server: 100% by nuck16
// roc 2009-12 0097b440  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b440
//
// 0097b440  33c9                 xor ecx, ecx
// 0097b442  51                   push ecx
// 0097b443  6a09                 push 9
// 0097b445  51                   push ecx
// 0097b446  51                   push ecx
// 0097b447  b8f0ff7500           mov eax, 0x75fff0
// 0097b44c  50                   push eax
// 0097b44d  6884b09b00           push 0x9bb084
// 0097b452  68e0779e00           push 0x9e77e0
// 0097b457  b9c07ab900           mov ecx, 0xb97ac0
// 0097b45c  e88f50deff           call 0x7604f0
// 0097b461  6820999800           push 0x989920
// 0097b466  e8be94e7ff           call 0x7f4929
// 0097b46b  59                   pop ecx
// 0097b46c  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("AbsoluteSize", "Data", &Owner::m0, 0, 9, 0);
