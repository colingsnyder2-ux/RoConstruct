// from server: 100% by nuck16
// roc 2009-12 0097af30  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097af30
//
// 0097af30  33c9                 xor ecx, ecx
// 0097af32  51                   push ecx
// 0097af33  6a0f                 push 0xf
// 0097af35  51                   push ecx
// 0097af36  b8409e7500           mov eax, 0x759e40
// 0097af3b  50                   push eax
// 0097af3c  68f0337700           push 0x7733f0
// 0097af41  6884b09b00           push 0x9bb084
// 0097af46  681c5f9e00           push 0x9e5f1c
// 0097af4b  b9c476b900           mov ecx, 0xb976c4
// 0097af50  e83bf3ddff           call 0x75a290
// 0097af55  68d0959800           push 0x9895d0
// 0097af5a  e8ca99e7ff           call 0x7f4929
// 0097af5f  59                   pop ecx
// 0097af60  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_007733f0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextXAlignment", "Data", func_007733f0, &Owner::m0, 15, 0);
