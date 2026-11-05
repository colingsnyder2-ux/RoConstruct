// from server: 100% by nuck16
// roc 2009-12 0097be40  unit: seg_00970000  size: 57 bytes
//
// 0097be40  56                   push esi
// 0097be41  33f6                 xor esi, esi
// 0097be43  56                   push esi
// 0097be44  6a08                 push 8
// 0097be46  33c9                 xor ecx, ecx
// 0097be48  51                   push ecx
// 0097be49  b8502a6800           mov eax, 0x682a50
// 0097be4e  50                   push eax
// 0097be4f  56                   push esi
// 0097be50  ba20797500           mov edx, 0x757920
// 0097be55  52                   push edx
// 0097be56  6884b09b00           push 0x9bb084
// 0097be5b  68ec7e9d00           push 0x9d7eec
// 0097be60  b95084b900           mov ecx, 0xb98450
// 0097be65  e8d62adfff           call 0x76e940
// 0097be6a  68109f9800           push 0x989f10
// 0097be6f  e8b58ae7ff           call 0x7f4929
// 0097be74  83c404               add esp, 4
// 0097be77  5e                   pop esi
// 0097be78  c3                   ret 

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

static Desc desc("Transparency", "Data", &Owner::m0, &Owner::m1, 8, 0);
