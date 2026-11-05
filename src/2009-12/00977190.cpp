// from server: 100% by nuck16
// roc 2009-12 00977190  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977190
//
// 00977190  6a0f                 push 0xf
// 00977192  6820d37100           push 0x71d320
// 00977197  68e0d17100           push 0x71d1e0
// 0097719c  6830a79b00           push 0x9ba730
// 009771a1  6800c59d00           push 0x9dc500
// 009771a6  b93844b900           mov ecx, 0xb94438
// 009771ab  e860bfd7ff           call 0x6f3110
// 009771b0  68a06e9800           push 0x986ea0
// 009771b5  e86fd7e7ff           call 0x7f4929
// 009771ba  59                   pop ecx
// 009771bb  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};

extern "C" void func_0071d1e0();
extern "C" void func_0071d320();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (*)(), int);
    ~Desc();
};

static Desc desc("LeftSurface", "Surface", func_0071d1e0, func_0071d320, 15);
