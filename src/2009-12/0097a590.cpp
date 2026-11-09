// from server: 100% by nuck16
// roc 2009-12 0097a590  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097a590
//
// 0097a590  6a00                 push 0
// 0097a592  6a02                 push 2
// 0097a594  6894010000           push 0x194
// 0097a599  68801b9d00           push 0x9d1b80
// 0097a59e  68e03e9e00           push 0x9e3ee0
// 0097a5a3  b94c70b900           mov ecx, 0xb9704c
// 0097a5a8  e8a3e9dcff           call 0x748f50
// 0097a5ad  68908f9800           push 0x988f90
// 0097a5b2  e872a3e7ff           call 0x7f4929
// 0097a5b7  59                   pop ecx
// 0097a5b8  c3                   ret 

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

static Desc desc("MouseButton1UpConnectionCount", "EventReplicator", 404, 2, 0);
