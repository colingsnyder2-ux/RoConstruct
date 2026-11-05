// from server: 100% by nuck16
// roc 2009-12 009797e0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009797e0
//
// 009797e0  6a00                 push 0
// 009797e2  6a0f                 push 0xf
// 009797e4  6858010000           push 0x158
// 009797e9  68141c9e00           push 0x9e1c14
// 009797ee  68c01c9e00           push 0x9e1cc0
// 009797f3  b9f862b900           mov ecx, 0xb962f8
// 009797f8  e853f2dbff           call 0x738a50
// 009797fd  68f0869800           push 0x9886f0
// 00979802  e822b1e7ff           call 0x7f4929
// 00979807  59                   pop ecx
// 00979808  c3                   ret 

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

static Desc desc("P", "Goals", 344, 15, 0);
