// from server: 100% by nuck16
// roc 2009-12 00974c30  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974c30
//
// 00974c30  6a00                 push 0
// 00974c32  6a0f                 push 0xf
// 00974c34  68ac000000           push 0xac
// 00974c39  68dc739d00           push 0x9d73dc
// 00974c3e  6830749d00           push 0x9d7430
// 00974c43  b92825b900           mov ecx, 0xb92528
// 00974c48  e8231bd5ff           call 0x6c6770
// 00974c4d  68205c9800           push 0x985c20
// 00974c52  e8d2fce7ff           call 0x7f4929
// 00974c57  59                   pop ecx
// 00974c58  c3                   ret 

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

static Desc desc("BubbleChatLifetime", "Online", 172, 15, 0);
