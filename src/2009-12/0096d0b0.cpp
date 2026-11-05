// from server: 100% by nuck16
// roc 2009-12 0096d0b0  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d0b0
//
// 0096d0b0  6a00                 push 0
// 0096d0b2  6a0f                 push 0xf
// 0096d0b4  6899000000           push 0x99
// 0096d0b9  68b8c59b00           push 0x9bc5b8
// 0096d0be  68a8c59b00           push 0x9bc5a8
// 0096d0c3  b95000b800           mov ecx, 0xb80050
// 0096d0c8  e823c4bbff           call 0x5294f0
// 0096d0cd  6850039800           push 0x980350
// 0096d0d2  e85278e8ff           call 0x7f4929
// 0096d0d7  59                   pop ecx
// 0096d0d8  c3                   ret 

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

static Desc desc("PrintInstances", "Diagnostics", 153, 15, 0);
