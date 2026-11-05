// from server: 100% by nuck16
// roc 2009-12 0097c210  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c210
//
// 0097c210  6a00                 push 0
// 0097c212  6a02                 push 2
// 0097c214  686c020000           push 0x26c
// 0097c219  68801b9d00           push 0x9d1b80
// 0097c21e  68708a9e00           push 0x9e8a70
// 0097c223  b9e484b900           mov ecx, 0xb984e4
// 0097c228  e84329dfff           call 0x76eb70
// 0097c22d  68909e9800           push 0x989e90
// 0097c232  e8f286e7ff           call 0x7f4929
// 0097c237  59                   pop ecx
// 0097c238  c3                   ret 

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

static Desc desc("MouseButton2DownConnectionCount", "EventReplicator", 620, 2, 0);
