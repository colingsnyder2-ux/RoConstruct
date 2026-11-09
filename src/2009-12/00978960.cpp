// from server: 100% by nuck16
// roc 2009-12 00978960  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978960
//
// 00978960  6a01                 push 1
// 00978962  68d81d9b00           push 0x9b1dd8
// 00978967  683cf69d00           push 0x9df63c
// 0097896c  68d4000000           push 0xd4
// 00978971  b91058b900           mov ecx, 0xb95810
// 00978976  e8150cdaff           call 0x719590
// 0097897b  68007e9800           push 0x987e00
// 00978980  e8a4bfe7ff           call 0x7f4929
// 00978985  59                   pop ecx
// 00978986  c3                   ret 

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
    Desc(int, const char *, const char *, int);
    ~Desc();
};

static Desc desc(212, "AssemblyAdded", "part", 1);
