// from server: 100% by nuck16
// roc 2009-12 0097b980  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b980
//
// 0097b980  33c9                 xor ecx, ecx
// 0097b982  51                   push ecx
// 0097b983  6a0f                 push 0xf
// 0097b985  51                   push ecx
// 0097b986  51                   push ecx
// 0097b987  b820b57600           mov eax, 0x76b520
// 0097b98c  50                   push eax
// 0097b98d  6884b09b00           push 0x9bb084
// 0097b992  6888819e00           push 0x9e8188
// 0097b997  b98c81b900           mov ecx, 0xb9818c
// 0097b99c  e8ef02dfff           call 0x76bc90
// 0097b9a1  68909a9800           push 0x989a90
// 0097b9a6  e87e8fe7ff           call 0x7f4929
// 0097b9ab  59                   pop ecx
// 0097b9ac  c3                   ret 

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

static Desc desc("Origin", "Data", &Owner::m0, 0, 15, 0);
