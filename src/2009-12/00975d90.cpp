// from server: 100% by nuck16
// roc 2009-12 00975d90  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00975d90
//
// 00975d90  6a00                 push 0
// 00975d92  6a0f                 push 0xf
// 00975d94  6898000000           push 0x98
// 00975d99  6884b09b00           push 0x9bb084
// 00975d9e  6810209d00           push 0x9d2010
// 00975da3  b9f434b900           mov ecx, 0xb934f4
// 00975da8  e8d3ccd6ff           call 0x6e2a80
// 00975dad  6810659800           push 0x986510
// 00975db2  e872ebe7ff           call 0x7f4929
// 00975db7  59                   pop ecx
// 00975db8  c3                   ret 

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

static Desc desc("Enabled", "Data", 152, 15, 0);
