// from server: 100% by nuck16
// roc 2009-12 0096ef00  unit: seg_00960000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ef00
//
// 0096ef00  6a01                 push 1
// 0096ef02  33c9                 xor ecx, ecx
// 0096ef04  68bcc39c00           push 0x9cc3bc
// 0096ef09  51                   push ecx
// 0096ef0a  b8104c4500           mov eax, 0x454c10
// 0096ef0f  50                   push eax
// 0096ef10  b99059b800           mov ecx, 0xb85990
// 0096ef15  e826d7ccff           call 0x63c640
// 0096ef1a  68001c9800           push 0x981c00
// 0096ef1f  e8055ae8ff           call 0x7f4929
// 0096ef24  59                   pop ecx
// 0096ef25  c3                   ret 

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

static Desc desc(&Owner::m0, "Run", 1);
