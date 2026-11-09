// from server: 100% by nuck16
// roc 2009-12 0097c240  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c240
//
// 0097c240  6a00                 push 0
// 0097c242  6a02                 push 2
// 0097c244  6894020000           push 0x294
// 0097c249  68801b9d00           push 0x9d1b80
// 0097c24e  68908a9e00           push 0x9e8a90
// 0097c253  b96082b900           mov ecx, 0xb98260
// 0097c258  e81329dfff           call 0x76eb70
// 0097c25d  68b09e9800           push 0x989eb0
// 0097c262  e8c286e7ff           call 0x7f4929
// 0097c267  59                   pop ecx
// 0097c268  c3                   ret 

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

static Desc desc("MouseButton2UpConnectionCount", "EventReplicator", 660, 2, 0);
