// from server: 100% by nuck16
// roc 2009-12 0096e700  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096e700
//
// 0096e700  6a01                 push 1
// 0096e702  6840b09b00           push 0x9bb040
// 0096e707  33c9                 xor ecx, ecx
// 0096e709  68b4bb9c00           push 0x9cbbb4
// 0096e70e  51                   push ecx
// 0096e70f  b8b0bc6200           mov eax, 0x62bcb0
// 0096e714  50                   push eax
// 0096e715  b9e048b800           mov ecx, 0xb848e0
// 0096e71a  e8a12bccff           call 0x6312c0
// 0096e71f  6800179800           push 0x981700
// 0096e724  e80062e8ff           call 0x7f4929
// 0096e729  59                   pop ecx
// 0096e72a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetBlockingRemove", "value", 1);
