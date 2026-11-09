// from server: 100% by nuck16
// roc 2009-12 0097a7d0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097a7d0
//
// 0097a7d0  6a00                 push 0
// 0097a7d2  6a02                 push 2
// 0097a7d4  686c010000           push 0x16c
// 0097a7d9  68801b9d00           push 0x9d1b80
// 0097a7de  68c03e9e00           push 0x9e3ec0
// 0097a7e3  b9a071b900           mov ecx, 0xb971a0
// 0097a7e8  e86325ddff           call 0x74cd50
// 0097a7ed  6870919800           push 0x989170
// 0097a7f2  e832a1e7ff           call 0x7f4929
// 0097a7f7  59                   pop ecx
// 0097a7f8  c3                   ret 

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

static Desc desc("MouseButton1DownConnectionCount", "EventReplicator", 364, 2, 0);
