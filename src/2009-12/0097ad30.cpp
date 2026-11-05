// from server: 100% by nuck16
// roc 2009-12 0097ad30  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097ad30
//
// 0097ad30  33c9                 xor ecx, ecx
// 0097ad32  51                   push ecx
// 0097ad33  6a0f                 push 0xf
// 0097ad35  51                   push ecx
// 0097ad36  b8008e7500           mov eax, 0x758e00
// 0097ad3b  50                   push eax
// 0097ad3c  6840887500           push 0x758840
// 0097ad41  6884b09b00           push 0x9bb084
// 0097ad46  68105f9e00           push 0x9e5f10
// 0097ad4b  b98075b900           mov ecx, 0xb97580
// 0097ad50  e88be4ddff           call 0x7591e0
// 0097ad55  6810959800           push 0x989510
// 0097ad5a  e8ca9be7ff           call 0x7f4929
// 0097ad5f  59                   pop ecx
// 0097ad60  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00758840();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextWrap", "Data", func_00758840, &Owner::m0, 15, 0);
