// from server: 100% by nuck16
// roc 2009-12 00979720  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979720
//
// 00979720  6a00                 push 0
// 00979722  6a0f                 push 0xf
// 00979724  6858010000           push 0x158
// 00979729  68141c9e00           push 0x9e1c14
// 0097972e  68c01c9e00           push 0x9e1cc0
// 00979733  b91862b900           mov ecx, 0xb96218
// 00979738  e8a3f0dbff           call 0x7387e0
// 0097973d  6890869800           push 0x988690
// 00979742  e8e2b1e7ff           call 0x7f4929
// 00979747  59                   pop ecx
// 00979748  c3                   ret 

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
