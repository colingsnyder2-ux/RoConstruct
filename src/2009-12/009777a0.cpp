// from server: 100% by nuck16
// roc 2009-12 009777a0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009777a0
//
// 009777a0  6a00                 push 0
// 009777a2  6a02                 push 2
// 009777a4  684c020000           push 0x24c
// 009777a9  68801b9d00           push 0x9d1b80
// 009777ae  68b4cc9d00           push 0x9dccb4
// 009777b3  b9cc48b900           mov ecx, 0xb948cc
// 009777b8  e8c306d8ff           call 0x6f7e80
// 009777bd  68a0709800           push 0x9870a0
// 009777c2  e862d1e7ff           call 0x7f4929
// 009777c7  59                   pop ecx
// 009777c8  c3                   ret 

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

static Desc desc("IdleConnectionCount", "EventReplicator", 588, 2, 0);
