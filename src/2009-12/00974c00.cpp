// from server: 100% by nuck16
// roc 2009-12 00974c00  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974c00
//
// 00974c00  6a00                 push 0
// 00974c02  6a0f                 push 0xf
// 00974c04  68a8000000           push 0xa8
// 00974c09  68dc739d00           push 0x9d73dc
// 00974c0e  6818749d00           push 0x9d7418
// 00974c13  b9c424b900           mov ecx, 0xb924c4
// 00974c18  e8b319d5ff           call 0x6c65d0
// 00974c1d  68805b9800           push 0x985b80
// 00974c22  e802fde7ff           call 0x7f4929
// 00974c27  59                   pop ecx
// 00974c28  c3                   ret 

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

static Desc desc("BubbleChatMaxBubbles", "Online", 168, 15, 0);
