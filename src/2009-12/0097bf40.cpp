// from server: 100% by nuck16
// roc 2009-12 0097bf40  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097bf40
//
// 0097bf40  6a00                 push 0
// 0097bf42  6a02                 push 2
// 0097bf44  68d0000000           push 0xd0
// 0097bf49  68801b9d00           push 0x9d1b80
// 0097bf4e  686c3e9e00           push 0x9e3e6c
// 0097bf53  b9c082b900           mov ecx, 0xb982c0
// 0097bf58  e8432bdfff           call 0x76eaa0
// 0097bf5d  68309f9800           push 0x989f30
// 0097bf62  e8c289e7ff           call 0x7f4929
// 0097bf67  59                   pop ecx
// 0097bf68  c3                   ret 

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

static Desc desc("MouseEnterConnectionCount", "EventReplicator", 208, 2, 0);
