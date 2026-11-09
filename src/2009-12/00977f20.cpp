// from server: 100% by nuck16
// roc 2009-12 00977f20  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977f20
//
// 00977f20  33c9                 xor ecx, ecx
// 00977f22  51                   push ecx
// 00977f23  6a0f                 push 0xf
// 00977f25  51                   push ecx
// 00977f26  b8b0e36f00           mov eax, 0x6fe3b0
// 00977f2b  50                   push eax
// 00977f2c  68a4000000           push 0xa4
// 00977f31  68dc1f9d00           push 0x9d1fdc
// 00977f36  68e4db9d00           push 0x9ddbe4
// 00977f3b  b9b04db900           mov ecx, 0xb94db0
// 00977f40  e86b6cd8ff           call 0x6febb0
// 00977f45  68e0769800           push 0x9876e0
// 00977f4a  e8dac9e7ff           call 0x7f4929
// 00977f4f  59                   pop ecx
// 00977f50  c3                   ret 

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

static Desc desc("TorsoColor", "Appearance", 164, &Owner::m0, 15, 0);
