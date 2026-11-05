// from server: 100% by nuck16
// roc 2009-12 0097ac70  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097ac70
//
// 0097ac70  33c9                 xor ecx, ecx
// 0097ac72  51                   push ecx
// 0097ac73  6a08                 push 8
// 0097ac75  51                   push ecx
// 0097ac76  b8d08e7500           mov eax, 0x758ed0
// 0097ac7b  50                   push eax
// 0097ac7c  68f0877500           push 0x7587f0
// 0097ac81  6884b09b00           push 0x9bb084
// 0097ac86  68e45e9e00           push 0x9e5ee4
// 0097ac8b  b9f474b900           mov ecx, 0xb974f4
// 0097ac90  e86be3ddff           call 0x759000
// 0097ac95  6870959800           push 0x989570
// 0097ac9a  e88a9ce7ff           call 0x7f4929
// 0097ac9f  59                   pop ecx
// 0097aca0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_007587f0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextColor", "Data", func_007587f0, &Owner::m0, 8, 0);
