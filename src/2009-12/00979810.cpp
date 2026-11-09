// from server: 100% by nuck16
// roc 2009-12 00979810  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979810
//
// 00979810  6a00                 push 0
// 00979812  6a0f                 push 0xf
// 00979814  685c010000           push 0x15c
// 00979819  68141c9e00           push 0x9e1c14
// 0097981e  6850f69900           push 0x99f650
// 00979823  b96063b900           mov ecx, 0xb96360
// 00979828  e823f2dbff           call 0x738a50
// 0097982d  68d0869800           push 0x9886d0
// 00979832  e8f2b0e7ff           call 0x7f4929
// 00979837  59                   pop ecx
// 00979838  c3                   ret 

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

static Desc desc("D", "Goals", 348, 15, 0);
