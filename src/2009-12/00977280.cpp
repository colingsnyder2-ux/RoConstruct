// from server: 100% by nuck16
// roc 2009-12 00977280  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977280
//
// 00977280  6a0f                 push 0xf
// 00977282  6870d37100           push 0x71d370
// 00977287  6800d27100           push 0x71d200
// 0097728c  6894c49d00           push 0x9dc494
// 00977291  6848c59d00           push 0x9dc548
// 00977296  b98445b900           mov ecx, 0xb94584
// 0097729b  e810c1d7ff           call 0x6f33b0
// 009772a0  68006f9800           push 0x986f00
// 009772a5  e87fd6e7ff           call 0x7f4929
// 009772aa  59                   pop ecx
// 009772ab  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};

extern "C" void func_0071d200();
extern "C" void func_0071d370();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (*)(), int);
    ~Desc();
};

static Desc desc("RightSurfaceInput", "Surface Inputs", func_0071d200, func_0071d370, 15);
