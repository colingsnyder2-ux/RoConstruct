// from server: 100% by nuck16
// roc 2009-12 0097ad70  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097ad70
//
// 0097ad70  33c9                 xor ecx, ecx
// 0097ad72  51                   push ecx
// 0097ad73  6a0f                 push 0xf
// 0097ad75  51                   push ecx
// 0097ad76  b8308e7500           mov eax, 0x758e30
// 0097ad7b  50                   push eax
// 0097ad7c  68f0337700           push 0x7733f0
// 0097ad81  6884b09b00           push 0x9bb084
// 0097ad86  681c5f9e00           push 0x9e5f1c
// 0097ad8b  b9c875b900           mov ecx, 0xb975c8
// 0097ad90  e8ebe4ddff           call 0x759280
// 0097ad95  68f0949800           push 0x9894f0
// 0097ad9a  e88a9be7ff           call 0x7f4929
// 0097ad9f  59                   pop ecx
// 0097ada0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_007733f0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextXAlignment", "Data", func_007733f0, &Owner::m0, 15, 0);
