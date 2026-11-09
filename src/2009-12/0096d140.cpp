// from server: 100% by nuck16
// roc 2009-12 0096d140  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d140
//
// 0096d140  6a00                 push 0
// 0096d142  6a0f                 push 0xf
// 0096d144  68d0000000           push 0xd0
// 0096d149  68b8c59b00           push 0x9bc5b8
// 0096d14e  68e8c59b00           push 0x9bc5e8
// 0096d153  b97000b800           mov ecx, 0xb80070
// 0096d158  e893c3bbff           call 0x5294f0
// 0096d15d  68d0019800           push 0x9801d0
// 0096d162  e8c277e8ff           call 0x7f4929
// 0096d167  59                   pop ecx
// 0096d168  c3                   ret 

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

static Desc desc("ReplicatorDiagnostics", "Diagnostics", 208, 15, 0);
