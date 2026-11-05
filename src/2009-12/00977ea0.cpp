// from server: 100% by nuck16
// roc 2009-12 00977ea0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977ea0
//
// 00977ea0  33c9                 xor ecx, ecx
// 00977ea2  51                   push ecx
// 00977ea3  6a0f                 push 0xf
// 00977ea5  51                   push ecx
// 00977ea6  b8b0e36f00           mov eax, 0x6fe3b0
// 00977eab  50                   push eax
// 00977eac  689c000000           push 0x9c
// 00977eb1  68dc1f9d00           push 0x9d1fdc
// 00977eb6  68c4db9d00           push 0x9ddbc4
// 00977ebb  b96c4db900           mov ecx, 0xb94d6c
// 00977ec0  e8eb6cd8ff           call 0x6febb0
// 00977ec5  6880769800           push 0x987680
// 00977eca  e85acae7ff           call 0x7f4929
// 00977ecf  59                   pop ecx
// 00977ed0  c3                   ret 

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

static Desc desc("LeftArmColor", "Appearance", 156, &Owner::m0, 15, 0);
