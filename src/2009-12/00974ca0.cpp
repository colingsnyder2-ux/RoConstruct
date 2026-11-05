// from server: 100% by nuck16
// roc 2009-12 00974ca0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974ca0
//
// 00974ca0  6a00                 push 0
// 00974ca2  6a0f                 push 0xf
// 00974ca4  68c4000000           push 0xc4
// 00974ca9  6884b09b00           push 0x9bb084
// 00974cae  68d4769d00           push 0x9d76d4
// 00974cb3  b9e825b900           mov ecx, 0xb925e8
// 00974cb8  e87333d5ff           call 0x6c8030
// 00974cbd  68705c9800           push 0x985c70
// 00974cc2  e862fce7ff           call 0x7f4929
// 00974cc7  59                   pop ecx
// 00974cc8  c3                   ret 

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

static Desc desc("BlastPressure", "Data", 196, 15, 0);
