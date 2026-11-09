// from server: 100% by nuck16
// roc 2009-12 0096ee70  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ee70
//
// 0096ee70  6a01                 push 1
// 0096ee72  68e8c19c00           push 0x9cc1e8
// 0096ee77  33c9                 xor ecx, ecx
// 0096ee79  68e4c19c00           push 0x9cc1e4
// 0096ee7e  51                   push ecx
// 0096ee7f  b8a0a66300           mov eax, 0x63a6a0
// 0096ee84  50                   push eax
// 0096ee85  b93857b800           mov ecx, 0xb85738
// 0096ee8a  e8e1a5ccff           call 0x639470
// 0096ee8f  68201b9800           push 0x981b20
// 0096ee94  e8905ae8ff           call 0x7f4929
// 0096ee99  59                   pop ecx
// 0096ee9a  c3                   ret 

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

static Desc desc(&Owner::m0, "Set", "selection", 1);
