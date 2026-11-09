// from server: 100% by nuck16
// roc 2009-12 009792a0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009792a0
//
// 009792a0  6a00                 push 0
// 009792a2  6a0f                 push 0xf
// 009792a4  689c000000           push 0x9c
// 009792a9  6884b09b00           push 0x9bb084
// 009792ae  68240a9e00           push 0x9e0a24
// 009792b3  b9805eb900           mov ecx, 0xb95e80
// 009792b8  e81355dbff           call 0x72e7d0
// 009792bd  6870809800           push 0x988070
// 009792c2  e862b6e7ff           call 0x7f4929
// 009792c7  59                   pop ecx
// 009792c8  c3                   ret 

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

static Desc desc("MaxValue", "Data", 156, 15, 0);
