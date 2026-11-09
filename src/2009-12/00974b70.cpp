// from server: 100% by nuck16
// roc 2009-12 00974b70  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974b70
//
// 00974b70  6a00                 push 0
// 00974b72  6a0f                 push 0xf
// 00974b74  689c000000           push 0x9c
// 00974b79  68dc739d00           push 0x9d73dc
// 00974b7e  68e4739d00           push 0x9d73e4
// 00974b83  b90825b900           mov ecx, 0xb92508
// 00974b88  e8431ad5ff           call 0x6c65d0
// 00974b8d  68a05b9800           push 0x985ba0
// 00974b92  e892fde7ff           call 0x7f4929
// 00974b97  59                   pop ecx
// 00974b98  c3                   ret 

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

static Desc desc("ChatScrollLength", "Online", 156, 15, 0);
