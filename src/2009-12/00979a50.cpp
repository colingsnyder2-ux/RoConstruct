// from server: 100% by nuck16
// roc 2009-12 00979a50  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979a50
//
// 00979a50  6a00                 push 0
// 00979a52  6a0f                 push 0xf
// 00979a54  6868010000           push 0x168
// 00979a59  68141c9e00           push 0x9e1c14
// 00979a5e  680c1d9e00           push 0x9e1d0c
// 00979a63  b93862b900           mov ecx, 0xb96238
// 00979a68  e8f3f3dbff           call 0x738e60
// 00979a6d  68b0879800           push 0x9887b0
// 00979a72  e8b2aee7ff           call 0x7f4929
// 00979a77  59                   pop ecx
// 00979a78  c3                   ret 

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

static Desc desc("angularvelocity", "Goals", 360, 15, 0);
