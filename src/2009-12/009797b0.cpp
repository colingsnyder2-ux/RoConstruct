// from server: 100% by nuck16
// roc 2009-12 009797b0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009797b0
//
// 009797b0  6a00                 push 0
// 009797b2  6a0f                 push 0xf
// 009797b4  686c010000           push 0x16c
// 009797b9  68141c9e00           push 0x9e1c14
// 009797be  68d01c9e00           push 0x9e1cd0
// 009797c3  b9bc66b900           mov ecx, 0xb966bc
// 009797c8  e8b3f1dbff           call 0x738980
// 009797cd  68d0889800           push 0x9888d0
// 009797d2  e852b1e7ff           call 0x7f4929
// 009797d7  59                   pop ecx
// 009797d8  c3                   ret 

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

static Desc desc("cframe", "Goals", 364, 15, 0);
