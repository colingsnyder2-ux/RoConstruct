// from server: 100% by nuck16
// roc 2009-12 0097a500  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097a500
//
// 0097a500  6a00                 push 0
// 0097a502  6a02                 push 2
// 0097a504  681c010000           push 0x11c
// 0097a509  68801b9d00           push 0x9d1b80
// 0097a50e  68883e9e00           push 0x9e3e88
// 0097a513  b97870b900           mov ecx, 0xb97078
// 0097a518  e833eadcff           call 0x748f50
// 0097a51d  68308f9800           push 0x988f30
// 0097a522  e802a4e7ff           call 0x7f4929
// 0097a527  59                   pop ecx
// 0097a528  c3                   ret 

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

static Desc desc("MouseLeaveConnectionCount", "EventReplicator", 284, 2, 0);
