// from server: 100% by nuck16
// roc 2009-12 0096d110  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d110
//
// 0096d110  6a00                 push 0
// 0096d112  6a0f                 push 0xf
// 0096d114  6898000000           push 0x98
// 0096d119  68b8c59b00           push 0x9bc5b8
// 0096d11e  68d4c59b00           push 0x9bc5d4
// 0096d123  b99000b800           mov ecx, 0xb80090
// 0096d128  e8c3c3bbff           call 0x5294f0
// 0096d12d  68b0019800           push 0x9801b0
// 0096d132  e8f277e8ff           call 0x7f4929
// 0096d137  59                   pop ecx
// 0096d138  c3                   ret 

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

static Desc desc("PrintPhysicsErrors", "Diagnostics", 152, 15, 0);
