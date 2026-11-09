// from server: 100% by nuck16
// roc 2009-12 0097acf0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097acf0
//
// 0097acf0  33c9                 xor ecx, ecx
// 0097acf2  51                   push ecx
// 0097acf3  6a0f                 push 0xf
// 0097acf5  51                   push ecx
// 0097acf6  b8d08d7500           mov eax, 0x758dd0
// 0097acfb  50                   push eax
// 0097acfc  6890f75d00           push 0x5df790
// 0097ad01  6884b09b00           push 0x9bb084
// 0097ad06  68fc5e9e00           push 0x9e5efc
// 0097ad0b  b91c75b900           mov ecx, 0xb9751c
// 0097ad10  e82be4ddff           call 0x759140
// 0097ad15  6830959800           push 0x989530
// 0097ad1a  e80a9ce7ff           call 0x7f4929
// 0097ad1f  59                   pop ecx
// 0097ad20  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_005df790();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextTransparency", "Data", func_005df790, &Owner::m0, 15, 0);
