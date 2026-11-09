// from server: 100% by nuck16
// roc 2009-12 0096eb10  unit: seg_00960000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096eb10
//
// 0096eb10  33c9                 xor ecx, ecx
// 0096eb12  51                   push ecx
// 0096eb13  68d8bf9c00           push 0x9cbfd8
// 0096eb18  51                   push ecx
// 0096eb19  b840316300           mov eax, 0x633140
// 0096eb1e  50                   push eax
// 0096eb1f  b9f054b800           mov ecx, 0xb854f0
// 0096eb24  e87761ccff           call 0x634ca0
// 0096eb29  68e0189800           push 0x9818e0
// 0096eb2e  e8f65de8ff           call 0x7f4929
// 0096eb33  59                   pop ecx
// 0096eb34  c3                   ret 

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

static Desc desc(&Owner::m0, "children", 0);
