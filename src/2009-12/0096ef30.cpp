// from server: 100% by nuck16
// roc 2009-12 0096ef30  unit: seg_00960000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ef30
//
// 0096ef30  6a01                 push 1
// 0096ef32  33c9                 xor ecx, ecx
// 0096ef34  68c0c39c00           push 0x9cc3c0
// 0096ef39  51                   push ecx
// 0096ef3a  b8204c4500           mov eax, 0x454c20
// 0096ef3f  50                   push eax
// 0096ef40  b90859b800           mov ecx, 0xb85908
// 0096ef45  e8f6d6ccff           call 0x63c640
// 0096ef4a  68801b9800           push 0x981b80
// 0096ef4f  e8d559e8ff           call 0x7f4929
// 0096ef54  59                   pop ecx
// 0096ef55  c3                   ret 

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

static Desc desc(&Owner::m0, "Pause", 1);
