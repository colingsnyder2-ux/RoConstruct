// from server: 100% by nuck16
// roc 2009-12 00967fe0  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00967fe0
//
// 00967fe0  6a00                 push 0
// 00967fe2  6a0f                 push 0xf
// 00967fe4  6899000000           push 0x99
// 00967fe9  68c8079a00           push 0x9a07c8
// 00967fee  68b0079a00           push 0x9a07b0
// 00967ff3  b94ca0b700           mov ecx, 0xb7a04c
// 00967ff8  e89324aaff           call 0x40a490
// 00967ffd  6880d89700           push 0x97d880
// 00968002  e822c9e8ff           call 0x7f4929
// 00968007  59                   pop ecx
// 00968008  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};


struct Desc
{
    Desc(const char *, const char *, int, int, int);
    ~Desc();
};

static Desc desc("ShowPreliminaryObjects", "Browsing", 153, 15, 0);
