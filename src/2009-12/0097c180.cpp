// from server: 100% by nuck16
// roc 2009-12 0097c180  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c180
//
// 0097c180  6a00                 push 0
// 0097c182  6a02                 push 2
// 0097c184  68f4010000           push 0x1f4
// 0097c189  68801b9d00           push 0x9d1b80
// 0097c18e  684c8a9e00           push 0x9e8a4c
// 0097c193  b93c85b900           mov ecx, 0xb9853c
// 0097c198  e8d329dfff           call 0x76eb70
// 0097c19d  68309e9800           push 0x989e30
// 0097c1a2  e88287e7ff           call 0x7f4929
// 0097c1a7  59                   pop ecx
// 0097c1a8  c3                   ret 

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

static Desc desc("MouseButton2ClickConnectionCount", "EventReplicator", 500, 2, 0);
