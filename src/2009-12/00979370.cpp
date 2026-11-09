// from server: 100% by nuck16
// roc 2009-12 00979370  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979370
//
// 00979370  6a00                 push 0
// 00979372  6a0f                 push 0xf
// 00979374  68a8000000           push 0xa8
// 00979379  6884b09b00           push 0x9bb084
// 0097937e  68240a9e00           push 0x9e0a24
// 00979383  b9e85fb900           mov ecx, 0xb95fe8
// 00979388  e8c355dbff           call 0x72e950
// 0097938d  68d0809800           push 0x9880d0
// 00979392  e892b5e7ff           call 0x7f4929
// 00979397  59                   pop ecx
// 00979398  c3                   ret 

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

static Desc desc("MaxValue", "Data", 168, 15, 0);
