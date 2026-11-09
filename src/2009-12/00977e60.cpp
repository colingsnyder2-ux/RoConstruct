// from server: 100% by nuck16
// roc 2009-12 00977e60  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977e60
//
// 00977e60  33c9                 xor ecx, ecx
// 00977e62  51                   push ecx
// 00977e63  6a0f                 push 0xf
// 00977e65  51                   push ecx
// 00977e66  b8b0e36f00           mov eax, 0x6fe3b0
// 00977e6b  50                   push eax
// 00977e6c  6898000000           push 0x98
// 00977e71  68dc1f9d00           push 0x9d1fdc
// 00977e76  68b8db9d00           push 0x9ddbb8
// 00977e7b  b9c84cb900           mov ecx, 0xb94cc8
// 00977e80  e82b6dd8ff           call 0x6febb0
// 00977e85  68a0769800           push 0x9876a0
// 00977e8a  e89acae7ff           call 0x7f4929
// 00977e8f  59                   pop ecx
// 00977e90  c3                   ret 

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

static Desc desc("HeadColor", "Appearance", 152, &Owner::m0, 15, 0);
