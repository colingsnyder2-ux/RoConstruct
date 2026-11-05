// from server: 100% by nuck16
// roc 2009-12 00977100  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977100
//
// 00977100  6a0f                 push 0xf
// 00977102  6870d37100           push 0x71d370
// 00977107  6800d27100           push 0x71d200
// 0097710c  6894c49d00           push 0x9dc494
// 00977111  68ccc49d00           push 0x9dc4cc
// 00977116  b9fc44b900           mov ecx, 0xb944fc
// 0097711b  e840bfd7ff           call 0x6f3060
// 00977120  68006e9800           push 0x986e00
// 00977125  e8ffd7e7ff           call 0x7f4929
// 0097712a  59                   pop ecx
// 0097712b  c3                   ret 

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

static Desc desc("BottomSurfaceInput", "Surface Inputs", func_0071d200, func_0071d370, 15);
