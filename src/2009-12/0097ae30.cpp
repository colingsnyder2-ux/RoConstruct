// from server: 100% by nuck16
// roc 2009-12 0097ae30  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097ae30
//
// 0097ae30  33c9                 xor ecx, ecx
// 0097ae32  51                   push ecx
// 0097ae33  6a08                 push 8
// 0097ae35  51                   push ecx
// 0097ae36  b8e09e7500           mov eax, 0x759ee0
// 0097ae3b  50                   push eax
// 0097ae3c  68f0877500           push 0x7587f0
// 0097ae41  6884b09b00           push 0x9bb084
// 0097ae46  68e45e9e00           push 0x9e5ee4
// 0097ae4b  b9f475b900           mov ecx, 0xb975f4
// 0097ae50  e8bbf1ddff           call 0x75a010
// 0097ae55  6850969800           push 0x989650
// 0097ae5a  e8ca9ae7ff           call 0x7f4929
// 0097ae5f  59                   pop ecx
// 0097ae60  c3                   ret 

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
