// from server: 100% by nuck16
// roc 2009-12 00968d50  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968d50
//
// 00968d50  33c9                 xor ecx, ecx
// 00968d52  51                   push ecx
// 00968d53  6a0f                 push 0xf
// 00968d55  51                   push ecx
// 00968d56  b8d0974400           mov eax, 0x4497d0
// 00968d5b  50                   push eax
// 00968d5c  6830b27a00           push 0x7ab230
// 00968d61  6880aa9a00           push 0x9aaa80
// 00968d66  6894aa9a00           push 0x9aaa94
// 00968d6b  b9c0afb700           mov ecx, 0xb7afc0
// 00968d70  e82b18aeff           call 0x44a5a0
// 00968d75  6850e39700           push 0x97e350
// 00968d7a  e8aabbe8ff           call 0x7f4929
// 00968d7f  59                   pop ecx
// 00968d80  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_007ab230();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TrussDetail", "Quality", func_007ab230, &Owner::m0, 15, 0);
