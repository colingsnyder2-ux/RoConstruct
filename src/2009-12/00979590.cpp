// from server: 100% by nuck16
// roc 2009-12 00979590  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979590
//
// 00979590  6a00                 push 0
// 00979592  6a0f                 push 0xf
// 00979594  688c010000           push 0x18c
// 00979599  68481c9e00           push 0x9e1c48
// 0097959e  68641c9e00           push 0x9e1c64
// 009795a3  b91865b900           mov ecx, 0xb96518
// 009795a8  e893f0dbff           call 0x738640
// 009795ad  68d0859800           push 0x9885d0
// 009795b2  e872b3e7ff           call 0x7f4929
// 009795b7  59                   pop ecx
// 009795b8  c3                   ret 

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

static Desc desc("ThrustD", "Thrust", 396, 15, 0);
