// from server: 100% by nuck16
// roc 2009-12 00979140  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979140
//
// 00979140  33c9                 xor ecx, ecx
// 00979142  51                   push ecx
// 00979143  6a0f                 push 0xf
// 00979145  51                   push ecx
// 00979146  b850327300           mov eax, 0x733250
// 0097914b  50                   push eax
// 0097914c  6894000000           push 0x94
// 00979151  6884b09b00           push 0x9bb084
// 00979156  684cd59a00           push 0x9ad54c
// 0097915b  b92461b900           mov ecx, 0xb96124
// 00979160  e8fb5ddbff           call 0x72ef60
// 00979165  6830829800           push 0x988230
// 0097916a  e8bab7e7ff           call 0x7f4929
// 0097916f  59                   pop ecx
// 00979170  c3                   ret 

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
    Desc(const char *, const char *, int, void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Value", "Data", 148, &Owner::m0, 15, 0);
