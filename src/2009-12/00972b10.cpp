// from server: 100% by nuck16
// roc 2009-12 00972b10  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972b10
//
// 00972b10  33c9                 xor ecx, ecx
// 00972b12  51                   push ecx
// 00972b13  6a0f                 push 0xf
// 00972b15  51                   push ecx
// 00972b16  51                   push ecx
// 00972b17  b8e0526600           mov eax, 0x6652e0
// 00972b1c  50                   push eax
// 00972b1d  6824f49c00           push 0x9cf424
// 00972b22  681cf49c00           push 0x9cf41c
// 00972b27  b94007b900           mov ecx, 0xb90740
// 00972b2c  e8df83cfff           call 0x66af10
// 00972b31  68f0489800           push 0x9848f0
// 00972b36  e8ee1de8ff           call 0x7f4929
// 00972b3b  59                   pop ecx
// 00972b3c  c3                   ret 

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
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("JobId", "JobInfo", &Owner::m0, 0, 15, 0);
