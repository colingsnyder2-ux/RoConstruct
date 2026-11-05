// from server: 100% by nuck16
// roc 2009-12 0096ea50  unit: seg_00960000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ea50
//
// 0096ea50  33c9                 xor ecx, ecx
// 0096ea52  51                   push ecx
// 0096ea53  68a8bf9c00           push 0x9cbfa8
// 0096ea58  68a4bf9c00           push 0x9cbfa4
// 0096ea5d  51                   push ecx
// 0096ea5e  b870276300           mov eax, 0x632770
// 0096ea63  50                   push eax
// 0096ea64  b91052b800           mov ecx, 0xb85210
// 0096ea69  e8125cccff           call 0x634680
// 0096ea6e  68c01a9800           push 0x981ac0
// 0096ea73  e8b15ee8ff           call 0x7f4929
// 0096ea78  59                   pop ecx
// 0096ea79  c3                   ret 

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

static Desc desc(&Owner::m0, "IsA", "className", 0);
