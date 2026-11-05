// from server: 100% by nuck16
// roc 2009-12 00977f60  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977f60
//
// 00977f60  33c9                 xor ecx, ecx
// 00977f62  51                   push ecx
// 00977f63  6a0f                 push 0xf
// 00977f65  51                   push ecx
// 00977f66  b8b0e36f00           mov eax, 0x6fe3b0
// 00977f6b  50                   push eax
// 00977f6c  68a8000000           push 0xa8
// 00977f71  68dc1f9d00           push 0x9d1fdc
// 00977f76  68f0db9d00           push 0x9ddbf0
// 00977f7b  b98c4db900           mov ecx, 0xb94d8c
// 00977f80  e82b6cd8ff           call 0x6febb0
// 00977f85  6800779800           push 0x987700
// 00977f8a  e89ac9e7ff           call 0x7f4929
// 00977f8f  59                   pop ecx
// 00977f90  c3                   ret 

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

static Desc desc("LeftLegColor", "Appearance", 168, &Owner::m0, 15, 0);
