// from server: 100% by nuck16
// roc 2009-12 00977ee0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977ee0
//
// 00977ee0  33c9                 xor ecx, ecx
// 00977ee2  51                   push ecx
// 00977ee3  6a0f                 push 0xf
// 00977ee5  51                   push ecx
// 00977ee6  b8b0e36f00           mov eax, 0x6fe3b0
// 00977eeb  50                   push eax
// 00977eec  68a0000000           push 0xa0
// 00977ef1  68dc1f9d00           push 0x9d1fdc
// 00977ef6  68d4db9d00           push 0x9ddbd4
// 00977efb  b9f04db900           mov ecx, 0xb94df0
// 00977f00  e8ab6cd8ff           call 0x6febb0
// 00977f05  68c0769800           push 0x9876c0
// 00977f0a  e81acae7ff           call 0x7f4929
// 00977f0f  59                   pop ecx
// 00977f10  c3                   ret 

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
    Desc(const char *, const char *, int, void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("RightArmColor", "Appearance", 160, &Owner::m0, 15, 0);
