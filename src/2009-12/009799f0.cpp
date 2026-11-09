// from server: 100% by nuck16
// roc 2009-12 009799f0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009799f0
//
// 009799f0  6a00                 push 0
// 009799f2  6a0f                 push 0xf
// 009799f4  6858010000           push 0x158
// 009799f9  68141c9e00           push 0x9e1c14
// 009799fe  68c01c9e00           push 0x9e1cc0
// 00979a03  b95865b900           mov ecx, 0xb96558
// 00979a08  e883f3dbff           call 0x738d90
// 00979a0d  68f0879800           push 0x9887f0
// 00979a12  e812afe7ff           call 0x7f4929
// 00979a17  59                   pop ecx
// 00979a18  c3                   ret 

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
