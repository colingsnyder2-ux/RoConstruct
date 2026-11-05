// from server: 100% by nuck16
// roc 2009-12 0096d3f0  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d3f0
//
// 0096d3f0  6a04                 push 4
// 0096d3f2  6840b09b00           push 0x9bb040
// 0096d3f7  33c9                 xor ecx, ecx
// 0096d3f9  68cccb9b00           push 0x9bcbcc
// 0096d3fe  51                   push ecx
// 0096d3ff  b8d0ba5200           mov eax, 0x52bad0
// 0096d404  50                   push eax
// 0096d405  b9b803b800           mov ecx, 0xb803b8
// 0096d40a  e81104bcff           call 0x52d820
// 0096d40f  6880049800           push 0x980480
// 0096d414  e81075e8ff           call 0x7f4929
// 0096d419  59                   pop ecx
// 0096d41a  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "SetIsPlayerAuthenticationRequired", "value", 4);
