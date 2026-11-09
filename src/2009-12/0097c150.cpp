// from server: 100% by nuck16
// roc 2009-12 0097c150  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c150
//
// 0097c150  6a00                 push 0
// 0097c152  6a02                 push 2
// 0097c154  68cc010000           push 0x1cc
// 0097c159  68801b9d00           push 0x9d1b80
// 0097c15e  68288a9e00           push 0x9e8a28
// 0097c163  b99086b900           mov ecx, 0xb98690
// 0097c168  e8032adfff           call 0x76eb70
// 0097c16d  68109e9800           push 0x989e10
// 0097c172  e8b287e7ff           call 0x7f4929
// 0097c177  59                   pop ecx
// 0097c178  c3                   ret 

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

static Desc desc("MouseButton1ClickConnectionCount", "EventReplicator", 460, 2, 0);
