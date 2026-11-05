// from server: 100% by nuck16
// roc 2009-12 009795c0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009795c0
//
// 009795c0  6a00                 push 0
// 009795c2  6a0f                 push 0xf
// 009795c4  6894010000           push 0x194
// 009795c9  68741c9e00           push 0x9e1c74
// 009795ce  686c1c9e00           push 0x9e1c6c
// 009795d3  b95866b900           mov ecx, 0xb96658
// 009795d8  e863f0dbff           call 0x738640
// 009795dd  68f0859800           push 0x9885f0
// 009795e2  e842b3e7ff           call 0x7f4929
// 009795e7  59                   pop ecx
// 009795e8  c3                   ret 

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

static Desc desc("TurnP", "Turn", 404, 15, 0);
