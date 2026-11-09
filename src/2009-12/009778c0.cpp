// from server: 100% by nuck16
// roc 2009-12 009778c0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009778c0
//
// 009778c0  6a00                 push 0
// 009778c2  6a02                 push 2
// 009778c4  683c030000           push 0x33c
// 009778c9  68801b9d00           push 0x9d1b80
// 009778ce  6854cd9d00           push 0x9dcd54
// 009778d3  b94848b900           mov ecx, 0xb94848
// 009778d8  e8a305d8ff           call 0x6f7e80
// 009778dd  6860719800           push 0x987160
// 009778e2  e842d0e7ff           call 0x7f4929
// 009778e7  59                   pop ecx
// 009778e8  c3                   ret 

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

static Desc desc("WheelBackwardConnectionCount", "EventReplicator", 828, 2, 0);
