// from server: 100% by nuck16
// roc 2009-12 0096ee40  unit: seg_00960000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ee40
//
// 0096ee40  6a01                 push 1
// 0096ee42  33c9                 xor ecx, ecx
// 0096ee44  68e0c19c00           push 0x9cc1e0
// 0096ee49  51                   push ecx
// 0096ee4a  b8e0866300           mov eax, 0x6386e0
// 0096ee4f  50                   push eax
// 0096ee50  b9f856b800           mov ecx, 0xb856f8
// 0096ee55  e896a4ccff           call 0x6392f0
// 0096ee5a  68301b9800           push 0x981b30
// 0096ee5f  e8c55ae8ff           call 0x7f4929
// 0096ee64  59                   pop ecx
// 0096ee65  c3                   ret 

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

static Desc desc(&Owner::m0, "Get", 1);
