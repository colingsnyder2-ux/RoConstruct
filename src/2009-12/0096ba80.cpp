// from server: 100% by nuck16
// roc 2009-12 0096ba80  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ba80
//
// 0096ba80  6a01                 push 1
// 0096ba82  6840b09b00           push 0x9bb040
// 0096ba87  33c9                 xor ecx, ecx
// 0096ba89  6848b09b00           push 0x9bb048
// 0096ba8e  51                   push ecx
// 0096ba8f  b8408a4f00           mov eax, 0x4f8a40
// 0096ba94  50                   push eax
// 0096ba95  b9e0e3b700           mov ecx, 0xb7e3e0
// 0096ba9a  e8c1ddb9ff           call 0x509860
// 0096ba9f  6840f49700           push 0x97f440
// 0096baa4  e8808ee8ff           call 0x7f4929
// 0096baa9  59                   pop ecx
// 0096baaa  c3                   ret 

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

static Desc desc(&Owner::m0, "SetSuperSafeChat", "value", 1);
