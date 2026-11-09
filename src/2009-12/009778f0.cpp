// from server: 100% by nuck16
// roc 2009-12 009778f0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009778f0
//
// 009778f0  6a00                 push 0
// 009778f2  6a02                 push 2
// 009778f4  6864030000           push 0x364
// 009778f9  68801b9d00           push 0x9d1b80
// 009778fe  6874cd9d00           push 0x9dcd74
// 00977903  b9844ab900           mov ecx, 0xb94a84
// 00977908  e87305d8ff           call 0x6f7e80
// 0097790d  6880719800           push 0x987180
// 00977912  e812d0e7ff           call 0x7f4929
// 00977917  59                   pop ecx
// 00977918  c3                   ret 

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

static Desc desc("KeyDownConnectionCount", "EventReplicator", 868, 2, 0);
