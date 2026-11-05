// from server: 100% by nuck16
// roc 2009-12 00972880  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972880
//
// 00972880  6a01                 push 1
// 00972882  33c9                 xor ecx, ecx
// 00972884  681cf39c00           push 0x9cf31c
// 00972889  51                   push ecx
// 0097288a  b890086700           mov eax, 0x670890
// 0097288f  50                   push eax
// 00972890  b96007b900           mov ecx, 0xb90760
// 00972895  e8f6c0cfff           call 0x66e990
// 0097289a  68104b9800           push 0x984b10
// 0097289f  e88520e8ff           call 0x7f4929
// 009728a4  59                   pop ecx
// 009728a5  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "ServerSave", 1);
