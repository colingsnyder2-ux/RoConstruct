// from server: 100% by nuck16
// roc 2009-12 0097aef0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097aef0
//
// 0097aef0  33c9                 xor ecx, ecx
// 0097aef2  51                   push ecx
// 0097aef3  6a0f                 push 0xf
// 0097aef5  51                   push ecx
// 0097aef6  b8109e7500           mov eax, 0x759e10
// 0097aefb  50                   push eax
// 0097aefc  6840887500           push 0x758840
// 0097af01  6884b09b00           push 0x9bb084
// 0097af06  68105f9e00           push 0x9e5f10
// 0097af0b  b97c76b900           mov ecx, 0xb9767c
// 0097af10  e8dbf2ddff           call 0x75a1f0
// 0097af15  68f0959800           push 0x9895f0
// 0097af1a  e80a9ae7ff           call 0x7f4929
// 0097af1f  59                   pop ecx
// 0097af20  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00758840();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextWrap", "Data", func_00758840, &Owner::m0, 15, 0);
