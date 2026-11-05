// from server: 100% by nuck16
// roc 2009-12 0096d0e0  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d0e0
//
// 0096d0e0  6a00                 push 0
// 0096d0e2  6a0f                 push 0xf
// 0096d0e4  689a000000           push 0x9a
// 0096d0e9  68b8c59b00           push 0x9bc5b8
// 0096d0ee  68c4c59b00           push 0x9bc5c4
// 0096d0f3  b9d8feb700           mov ecx, 0xb7fed8
// 0096d0f8  e8f3c3bbff           call 0x5294f0
// 0096d0fd  6890019800           push 0x980190
// 0096d102  e82278e8ff           call 0x7f4929
// 0096d107  59                   pop ecx
// 0096d108  c3                   ret 

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

static Desc desc("PrintProperties", "Diagnostics", 154, 15, 0);
