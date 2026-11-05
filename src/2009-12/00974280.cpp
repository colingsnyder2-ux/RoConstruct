// from server: 100% by nuck16
// roc 2009-12 00974280  unit: seg_00970000  size: 57 bytes
//
// 00974280  56                   push esi
// 00974281  33f6                 xor esi, esi
// 00974283  56                   push esi
// 00974284  6a0f                 push 0xf
// 00974286  33c9                 xor ecx, ecx
// 00974288  51                   push ecx
// 00974289  b880936b00           mov eax, 0x6b9380
// 0097428e  50                   push eax
// 0097428f  56                   push esi
// 00974290  bab0396b00           mov edx, 0x6b39b0
// 00974295  52                   push edx
// 00974296  6884b09b00           push 0x9bb084
// 0097429b  6838669d00           push 0x9d6638
// 009742a0  b9e81ab900           mov ecx, 0xb91ae8
// 009742a5  e8e626d4ff           call 0x6b6990
// 009742aa  68f0569800           push 0x9856f0
// 009742af  e87506e8ff           call 0x7f4929
// 009742b4  83c404               add esp, 4
// 009742b7  5e                   pop esi
// 009742b8  c3                   ret 

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

static Desc desc("SoundId", "Data", &Owner::m0, &Owner::m1, 15, 0);
