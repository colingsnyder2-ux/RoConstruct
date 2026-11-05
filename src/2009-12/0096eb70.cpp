// from server: 100% by nuck16
// roc 2009-12 0096eb70  unit: seg_00960000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096eb70
//
// 0096eb70  33c9                 xor ecx, ecx
// 0096eb72  51                   push ecx
// 0096eb73  68f0bf9c00           push 0x9cbff0
// 0096eb78  51                   push ecx
// 0096eb79  b890266300           mov eax, 0x632690
// 0096eb7e  50                   push eax
// 0096eb7f  b9b855b800           mov ecx, 0xb855b8
// 0096eb84  e8f761ccff           call 0x634d80
// 0096eb89  6820199800           push 0x981920
// 0096eb8e  e8965de8ff           call 0x7f4929
// 0096eb93  59                   pop ecx
// 0096eb94  c3                   ret 

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

static Desc desc(&Owner::m0, "GetFullName", 0);
