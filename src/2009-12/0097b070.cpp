// from server: 100% by nuck16
// roc 2009-12 0097b070  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b070
//
// 0097b070  33c9                 xor ecx, ecx
// 0097b072  51                   push ecx
// 0097b073  6a0f                 push 0xf
// 0097b075  51                   push ecx
// 0097b076  b8f0b07500           mov eax, 0x75b0f0
// 0097b07b  50                   push eax
// 0097b07c  6890f75d00           push 0x5df790
// 0097b081  6884b09b00           push 0x9bb084
// 0097b086  68fc5e9e00           push 0x9e5efc
// 0097b08b  b91477b900           mov ecx, 0xb97714
// 0097b090  e87b04deff           call 0x75b510
// 0097b095  68f0969800           push 0x9896f0
// 0097b09a  e88a98e7ff           call 0x7f4929
// 0097b09f  59                   pop ecx
// 0097b0a0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_005df790();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextTransparency", "Data", func_005df790, &Owner::m0, 15, 0);
