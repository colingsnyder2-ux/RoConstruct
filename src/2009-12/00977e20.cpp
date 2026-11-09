// from server: 100% by nuck16
// roc 2009-12 00977e20  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977e20
//
// 00977e20  33c9                 xor ecx, ecx
// 00977e22  51                   push ecx
// 00977e23  6a0f                 push 0xf
// 00977e25  51                   push ecx
// 00977e26  b8b0e36f00           mov eax, 0x6fe3b0
// 00977e2b  50                   push eax
// 00977e2c  6898000000           push 0x98
// 00977e31  68dc1f9d00           push 0x9d1fdc
// 00977e36  68acdb9d00           push 0x9ddbac
// 00977e3b  b9d04db900           mov ecx, 0xb94dd0
// 00977e40  e88b6cd8ff           call 0x6fead0
// 00977e45  68a0779800           push 0x9877a0
// 00977e4a  e8dacae7ff           call 0x7f4929
// 00977e4f  59                   pop ecx
// 00977e50  c3                   ret 

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

static Desc desc("SkinColor", "Appearance", 152, &Owner::m0, 15, 0);
