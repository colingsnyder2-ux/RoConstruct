// from server: 100% by nuck16
// roc 2009-12 0097bfa0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097bfa0
//
// 0097bfa0  6a00                 push 0
// 0097bfa2  6a02                 push 2
// 0097bfa4  6820010000           push 0x120
// 0097bfa9  68801b9d00           push 0x9d1b80
// 0097bfae  68c0899e00           push 0x9e89c0
// 0097bfb3  b90c86b900           mov ecx, 0xb9860c
// 0097bfb8  e8e32adfff           call 0x76eaa0
// 0097bfbd  68f09d9800           push 0x989df0
// 0097bfc2  e86289e7ff           call 0x7f4929
// 0097bfc7  59                   pop ecx
// 0097bfc8  c3                   ret 

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

static Desc desc("MouseMovedConnectionCount", "EventReplicator", 288, 2, 0);
