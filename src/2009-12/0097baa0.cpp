// from server: 100% by nuck16
// roc 2009-12 0097baa0  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097baa0
//
// 0097baa0  33c9                 xor ecx, ecx
// 0097baa2  51                   push ecx
// 0097baa3  6a0f                 push 0xf
// 0097baa5  51                   push ecx
// 0097baa6  51                   push ecx
// 0097baa7  b800b87600           mov eax, 0x76b800
// 0097baac  50                   push eax
// 0097baad  6884b09b00           push 0x9bb084
// 0097bab2  6898819e00           push 0x9e8198
// 0097bab7  b9707fb900           mov ecx, 0xb97f70
// 0097babc  e8bf03dfff           call 0x76be80
// 0097bac1  68509a9800           push 0x989a50
// 0097bac6  e85e8ee7ff           call 0x7f4929
// 0097bacb  59                   pop ecx
// 0097bacc  c3                   ret 

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
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("ViewSizeX", "Data", &Owner::m0, 0, 15, 0);
