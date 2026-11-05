// from server: 100% by nuck16
// roc 2009-12 0097aff0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097aff0
//
// 0097aff0  33c9                 xor ecx, ecx
// 0097aff2  51                   push ecx
// 0097aff3  6a08                 push 8
// 0097aff5  51                   push ecx
// 0097aff6  b8f0b77500           mov eax, 0x75b7f0
// 0097affb  50                   push eax
// 0097affc  68f0877500           push 0x7587f0
// 0097b001  6884b09b00           push 0x9bb084
// 0097b006  68e45e9e00           push 0x9e5ee4
// 0097b00b  b9f076b900           mov ecx, 0xb976f0
// 0097b010  e8bb03deff           call 0x75b3d0
// 0097b015  6830979800           push 0x989730
// 0097b01a  e80a99e7ff           call 0x7f4929
// 0097b01f  59                   pop ecx
// 0097b020  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_007587f0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextColor", "Data", func_007587f0, &Owner::m0, 8, 0);
