// from server: 100% by nuck16
// roc 2009-12 0097a740  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097a740
//
// 0097a740  6a00                 push 0
// 0097a742  6a02                 push 2
// 0097a744  68f4000000           push 0xf4
// 0097a749  68801b9d00           push 0x9d1b80
// 0097a74e  686c3e9e00           push 0x9e3e6c
// 0097a753  b92871b900           mov ecx, 0xb97128
// 0097a758  e8f325ddff           call 0x74cd50
// 0097a75d  68d0919800           push 0x9891d0
// 0097a762  e8c2a1e7ff           call 0x7f4929
// 0097a767  59                   pop ecx
// 0097a768  c3                   ret 

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
