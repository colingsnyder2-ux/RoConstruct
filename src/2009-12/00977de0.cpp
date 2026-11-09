// from server: 100% by nuck16
// roc 2009-12 00977de0  unit: seg_00970000  size: 57 bytes
//
// 00977de0  56                   push esi
// 00977de1  33f6                 xor esi, esi
// 00977de3  56                   push esi
// 00977de4  6a0f                 push 0xf
// 00977de6  33c9                 xor ecx, ecx
// 00977de8  51                   push ecx
// 00977de9  b850e66f00           mov eax, 0x6fe650
// 00977dee  50                   push eax
// 00977def  56                   push esi
// 00977df0  ba402a6800           mov edx, 0x682a40
// 00977df5  52                   push edx
// 00977df6  68dc1f9d00           push 0x9d1fdc
// 00977dfb  689cdb9d00           push 0x9ddb9c
// 00977e00  b9084db900           mov ecx, 0xb94d08
// 00977e05  e8e676d8ff           call 0x6ff4f0
// 00977e0a  6840769800           push 0x987640
// 00977e0f  e815cbe7ff           call 0x7f4929
// 00977e14  83c404               add esp, 4
// 00977e17  5e                   pop esi
// 00977e18  c3                   ret 

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

static Desc desc("PantsTemplate", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
