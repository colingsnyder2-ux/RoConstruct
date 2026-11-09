// from server: 100% by nuck16
// roc 2009-12 00979340  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979340
//
// 00979340  6a00                 push 0
// 00979342  6a0f                 push 0xf
// 00979344  68a0000000           push 0xa0
// 00979349  6884b09b00           push 0x9bb084
// 0097934e  68180a9e00           push 0x9e0a18
// 00979353  b94c5fb900           mov ecx, 0xb95f4c
// 00979358  e8f355dbff           call 0x72e950
// 0097935d  68f0809800           push 0x9880f0
// 00979362  e8c2b5e7ff           call 0x7f4929
// 00979367  59                   pop ecx
// 00979368  c3                   ret 

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

static Desc desc("MinValue", "Data", 160, 15, 0);
