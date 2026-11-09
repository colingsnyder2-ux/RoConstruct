// from server: 100% by nuck16
// roc 2009-12 00979960  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979960
//
// 00979960  6a00                 push 0
// 00979962  6a0f                 push 0xf
// 00979964  6868010000           push 0x168
// 00979969  68141c9e00           push 0x9e1c14
// 0097996e  68001d9e00           push 0x9e1d00
// 00979973  b97865b900           mov ecx, 0xb96578
// 00979978  e843f3dbff           call 0x738cc0
// 0097997d  6850879800           push 0x988750
// 00979982  e8a2afe7ff           call 0x7f4929
// 00979987  59                   pop ecx
// 00979988  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};


struct Desc
{
    Desc(const char *, const char *, int, int, int);
    ~Desc();
};

static Desc desc("velocity", "Goals", 360, 15, 0);
