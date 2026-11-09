// from server: 100% by nuck16
// roc 2009-12 009795f0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009795f0
//
// 009795f0  6a00                 push 0
// 009795f2  6a0f                 push 0xf
// 009795f4  6898010000           push 0x198
// 009795f9  68741c9e00           push 0x9e1c74
// 009795fe  687c1c9e00           push 0x9e1c7c
// 00979603  b98063b900           mov ecx, 0xb96380
// 00979608  e833f0dbff           call 0x738640
// 0097960d  6810869800           push 0x988610
// 00979612  e812b3e7ff           call 0x7f4929
// 00979617  59                   pop ecx
// 00979618  c3                   ret 

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

static Desc desc("TurnD", "Turn", 408, 15, 0);
