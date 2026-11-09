// from server: 100% by nuck16
// roc 2009-12 00979500  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979500
//
// 00979500  6a00                 push 0
// 00979502  6a0f                 push 0xf
// 00979504  6890010000           push 0x190
// 00979509  68481c9e00           push 0x9e1c48
// 0097950e  683c1c9e00           push 0x9e1c3c
// 00979513  b9b864b900           mov ecx, 0xb964b8
// 00979518  e823f1dbff           call 0x738640
// 0097951d  6870889800           push 0x988870
// 00979522  e802b4e7ff           call 0x7f4929
// 00979527  59                   pop ecx
// 00979528  c3                   ret 

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

static Desc desc("MaxSpeed", "Thrust", 400, 15, 0);
