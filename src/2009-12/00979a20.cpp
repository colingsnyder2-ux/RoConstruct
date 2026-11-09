// from server: 100% by nuck16
// roc 2009-12 00979a20  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979a20
//
// 00979a20  6a00                 push 0
// 00979a22  6a0f                 push 0xf
// 00979a24  685c010000           push 0x15c
// 00979a29  68141c9e00           push 0x9e1c14
// 00979a2e  68c41c9e00           push 0x9e1cc4
// 00979a33  b9b862b900           mov ecx, 0xb962b8
// 00979a38  e823f4dbff           call 0x738e60
// 00979a3d  68d0879800           push 0x9887d0
// 00979a42  e8e2aee7ff           call 0x7f4929
// 00979a47  59                   pop ecx
// 00979a48  c3                   ret 

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

static Desc desc("maxTorque", "Goals", 348, 15, 0);
