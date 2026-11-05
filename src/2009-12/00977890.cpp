// from server: 100% by nuck16
// roc 2009-12 00977890  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977890
//
// 00977890  6a00                 push 0
// 00977892  6a02                 push 2
// 00977894  6814030000           push 0x314
// 00977899  68801b9d00           push 0x9d1b80
// 0097789e  6838cd9d00           push 0x9dcd38
// 009778a3  b92848b900           mov ecx, 0xb94828
// 009778a8  e8d305d8ff           call 0x6f7e80
// 009778ad  6840719800           push 0x987140
// 009778b2  e872d0e7ff           call 0x7f4929
// 009778b7  59                   pop ecx
// 009778b8  c3                   ret 

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

static Desc desc("WheelForwardConnectionCount", "EventReplicator", 788, 2, 0);
