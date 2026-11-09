// from server: 100% by nuck16
// roc 2009-12 00974d00  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974d00
//
// 00974d00  6a01                 push 1
// 00974d02  68f4769d00           push 0x9d76f4
// 00974d07  68d81d9b00           push 0x9b1dd8
// 00974d0c  68f0769d00           push 0x9d76f0
// 00974d11  68c8000000           push 0xc8
// 00974d16  b9ac25b900           mov ecx, 0xb925ac
// 00974d1b  e84042d5ff           call 0x6c8f60
// 00974d20  68b05c9800           push 0x985cb0
// 00974d25  e8fffbe7ff           call 0x7f4929
// 00974d2a  59                   pop ecx
// 00974d2b  c3                   ret 

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
    Desc(int, const char *, const char *, const char *, int);
    ~Desc();
};

static Desc desc(200, "Hit", "part", "distance", 1);
