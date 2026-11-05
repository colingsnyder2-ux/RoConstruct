// from server: 100% by nuck16
// roc 2009-12 009738a0  unit: seg_00970000  size: 57 bytes
//
// 009738a0  56                   push esi
// 009738a1  33f6                 xor esi, esi
// 009738a3  56                   push esi
// 009738a4  6a06                 push 6
// 009738a6  33c9                 xor ecx, ecx
// 009738a8  51                   push ecx
// 009738a9  b870406900           mov eax, 0x694070
// 009738ae  50                   push eax
// 009738af  56                   push esi
// 009738b0  bad0216900           mov edx, 0x6921d0
// 009738b5  52                   push edx
// 009738b6  68dc1f9d00           push 0x9d1fdc
// 009738bb  68d41f9d00           push 0x9d1fd4
// 009738c0  b97813b900           mov ecx, 0xb91378
// 009738c5  e8f6fed1ff           call 0x6937c0
// 009738ca  68a0519800           push 0x9851a0
// 009738cf  e85510e8ff           call 0x7f4929
// 009738d4  83c404               add esp, 4
// 009738d7  5e                   pop esi
// 009738d8  c3                   ret 

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

static Desc desc("Grip", "Appearance", &Owner::m0, &Owner::m1, 6, 0);
