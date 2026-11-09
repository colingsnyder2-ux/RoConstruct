// from server: 100% by nuck16
// roc 2009-12 00979230  unit: seg_00970000  size: 57 bytes
//
// 00979230  56                   push esi
// 00979231  33f6                 xor esi, esi
// 00979233  56                   push esi
// 00979234  6a0f                 push 0xf
// 00979236  33c9                 xor ecx, ecx
// 00979238  51                   push ecx
// 00979239  b840357300           mov eax, 0x733540
// 0097923e  50                   push eax
// 0097923f  56                   push esi
// 00979240  ba80d26300           mov edx, 0x63d280
// 00979245  52                   push edx
// 00979246  6884b09b00           push 0x9bb084
// 0097924b  68040a9e00           push 0x9e0a04
// 00979250  b9e85cb900           mov ecx, 0xb95ce8
// 00979255  e8c654dbff           call 0x72e720
// 0097925a  68b0809800           push 0x9880b0
// 0097925f  e8c5b6e7ff           call 0x7f4929
// 00979264  83c404               add esp, 4
// 00979267  5e                   pop esi
// 00979268  c3                   ret 

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

static Desc desc("ConstrainedValue", "Data", &Owner::m0, &Owner::m1, 15, 0);
