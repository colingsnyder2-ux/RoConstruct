// from server: 100% by nuck16
// roc 2009-12 009688f0  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009688f0
//
// 009688f0  6a00                 push 0
// 009688f2  6a0f                 push 0xf
// 009688f4  6896000000           push 0x96
// 009688f9  6834a09a00           push 0x9aa034
// 009688fe  684ca09a00           push 0x9aa04c
// 00968903  b90ca5b700           mov ecx, 0xb7a50c
// 00968908  e833a4adff           call 0x442d40
// 0096890d  68e0e09700           push 0x97e0e0
// 00968912  e812c0e8ff           call 0x7f4929
// 00968917  59                   pop ecx
// 00968918  c3                   ret 

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

static Desc desc("Preliminary", "Reflection", 150, 15, 0);
