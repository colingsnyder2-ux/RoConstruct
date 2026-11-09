// from server: 100% by nuck16
// roc 2009-12 0097a870  unit: seg_00970000  size: 57 bytes
//
// 0097a870  56                   push esi
// 0097a871  33f6                 xor esi, esi
// 0097a873  56                   push esi
// 0097a874  6a0f                 push 0xf
// 0097a876  33c9                 xor ecx, ecx
// 0097a878  51                   push ecx
// 0097a879  b880367500           mov eax, 0x753680
// 0097a87e  50                   push eax
// 0097a87f  56                   push esi
// 0097a880  ba00347500           mov edx, 0x753400
// 0097a885  52                   push edx
// 0097a886  6884b09b00           push 0x9bb084
// 0097a88b  680c1c9e00           push 0x9e1c0c
// 0097a890  b93073b900           mov ecx, 0xb97330
// 0097a895  e8f68cddff           call 0x753590
// 0097a89a  6850939800           push 0x989350
// 0097a89f  e885a0e7ff           call 0x7f4929
// 0097a8a4  83c404               add esp, 4
// 0097a8a7  5e                   pop esi
// 0097a8a8  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
    void m1();
};


struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Target", "Data", &Owner::m0, &Owner::m1, 15, 0);
