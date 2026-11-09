// from server: 100% by nuck16
// roc 2009-12 00977fa0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977fa0
//
// 00977fa0  33c9                 xor ecx, ecx
// 00977fa2  51                   push ecx
// 00977fa3  6a0f                 push 0xf
// 00977fa5  51                   push ecx
// 00977fa6  b8b0e36f00           mov eax, 0x6fe3b0
// 00977fab  50                   push eax
// 00977fac  68ac000000           push 0xac
// 00977fb1  68dc1f9d00           push 0x9d1fdc
// 00977fb6  6800dc9d00           push 0x9ddc00
// 00977fbb  b9a84cb900           mov ecx, 0xb94ca8
// 00977fc0  e8eb6bd8ff           call 0x6febb0
// 00977fc5  6820779800           push 0x987720
// 00977fca  e85ac9e7ff           call 0x7f4929
// 00977fcf  59                   pop ecx
// 00977fd0  c3                   ret 

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

static Desc desc("RightLegColor", "Appearance", 172, &Owner::m0, 15, 0);
