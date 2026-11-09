// from server: 100% by nuck16
// roc 2009-12 0097a4d0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097a4d0
//
// 0097a4d0  6a00                 push 0
// 0097a4d2  6a02                 push 2
// 0097a4d4  68f4000000           push 0xf4
// 0097a4d9  68801b9d00           push 0x9d1b80
// 0097a4de  686c3e9e00           push 0x9e3e6c
// 0097a4e3  b91c6fb900           mov ecx, 0xb96f1c
// 0097a4e8  e863eadcff           call 0x748f50
// 0097a4ed  68d08f9800           push 0x988fd0
// 0097a4f2  e832a4e7ff           call 0x7f4929
// 0097a4f7  59                   pop ecx
// 0097a4f8  c3                   ret 

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

static Desc desc("MouseEnterConnectionCount", "EventReplicator", 244, 2, 0);
