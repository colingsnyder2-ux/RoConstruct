// from server: 100% by nuck16
// roc 2009-12 0097c1b0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c1b0
//
// 0097c1b0  6a00                 push 0
// 0097c1b2  6a02                 push 2
// 0097c1b4  681c020000           push 0x21c
// 0097c1b9  68801b9d00           push 0x9d1b80
// 0097c1be  68c03e9e00           push 0x9e3ec0
// 0097c1c3  b9a082b900           mov ecx, 0xb982a0
// 0097c1c8  e8a329dfff           call 0x76eb70
// 0097c1cd  68509e9800           push 0x989e50
// 0097c1d2  e85287e7ff           call 0x7f4929
// 0097c1d7  59                   pop ecx
// 0097c1d8  c3                   ret 

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

static Desc desc("MouseButton1DownConnectionCount", "EventReplicator", 540, 2, 0);
