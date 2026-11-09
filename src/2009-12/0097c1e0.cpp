// from server: 100% by nuck16
// roc 2009-12 0097c1e0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c1e0
//
// 0097c1e0  6a00                 push 0
// 0097c1e2  6a02                 push 2
// 0097c1e4  6844020000           push 0x244
// 0097c1e9  68801b9d00           push 0x9d1b80
// 0097c1ee  68e03e9e00           push 0x9e3ee0
// 0097c1f3  b93084b900           mov ecx, 0xb98430
// 0097c1f8  e87329dfff           call 0x76eb70
// 0097c1fd  68709e9800           push 0x989e70
// 0097c202  e82287e7ff           call 0x7f4929
// 0097c207  59                   pop ecx
// 0097c208  c3                   ret 

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

static Desc desc("MouseButton1UpConnectionCount", "EventReplicator", 580, 2, 0);
