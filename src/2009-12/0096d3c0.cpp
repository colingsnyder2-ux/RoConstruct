// from server: 100% by nuck16
// roc 2009-12 0096d3c0  unit: seg_00960000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d3c0
//
// 0096d3c0  33c9                 xor ecx, ecx
// 0096d3c2  51                   push ecx
// 0096d3c3  6a0f                 push 0xf
// 0096d3c5  51                   push ecx
// 0096d3c6  51                   push ecx
// 0096d3c7  b800448200           mov eax, 0x824400
// 0096d3cc  50                   push eax
// 0096d3cd  6884b09b00           push 0x9bb084
// 0096d3d2  68c4cb9b00           push 0x9bcbc4
// 0096d3d7  b99004b800           mov ecx, 0xb80490
// 0096d3dc  e83ffabbff           call 0x52ce20
// 0096d3e1  68f0039800           push 0x9803f0
// 0096d3e6  e83e75e8ff           call 0x7f4929
// 0096d3eb  59                   pop ecx
// 0096d3ec  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("Port", "Data", &Owner::m0, 0, 15, 0);
