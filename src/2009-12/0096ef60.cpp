// from server: 100% by nuck16
// roc 2009-12 0096ef60  unit: seg_00960000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ef60
//
// 0096ef60  6a01                 push 1
// 0096ef62  33c9                 xor ecx, ecx
// 0096ef64  68c8c39c00           push 0x9cc3c8
// 0096ef69  51                   push ecx
// 0096ef6a  b8304c4500           mov eax, 0x454c30
// 0096ef6f  50                   push eax
// 0096ef70  b9c858b800           mov ecx, 0xb858c8
// 0096ef75  e8c6d6ccff           call 0x63c640
// 0096ef7a  68c01b9800           push 0x981bc0
// 0096ef7f  e8a559e8ff           call 0x7f4929
// 0096ef84  59                   pop ecx
// 0096ef85  c3                   ret 

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

static Desc desc(&Owner::m0, "Reset", 1);
