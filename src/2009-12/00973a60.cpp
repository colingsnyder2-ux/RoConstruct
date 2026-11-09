// from server: 100% by nuck16
// roc 2009-12 00973a60  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973a60
//
// 00973a60  6a00                 push 0
// 00973a62  6a0f                 push 0xf
// 00973a64  686c010000           push 0x16c
// 00973a69  6818209d00           push 0x9d2018
// 00973a6e  6810209d00           push 0x9d2010
// 00973a73  b93014b900           mov ecx, 0xb91430
// 00973a78  e853ffd1ff           call 0x6939d0
// 00973a7d  6800529800           push 0x985200
// 00973a82  e8a20ee8ff           call 0x7f4929
// 00973a87  59                   pop ecx
// 00973a88  c3                   ret 

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

static Desc desc("Enabled", "State", 364, 15, 0);
