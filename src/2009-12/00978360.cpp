// from server: 100% by nuck16
// roc 2009-12 00978360  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978360
//
// 00978360  6a01                 push 1
// 00978362  6800e79d00           push 0x9de700
// 00978367  68f0e69d00           push 0x9de6f0
// 0097836c  683c020000           push 0x23c
// 00978371  b9f855b900           mov ecx, 0xb955f8
// 00978376  e835c4d9ff           call 0x7147b0
// 0097837b  68d07b9800           push 0x987bd0
// 00978380  e8a4c5e7ff           call 0x7f4929
// 00978385  59                   pop ecx
// 00978386  c3                   ret 

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

static Desc desc(572, "LightingChanged", "skyboxChanged", 1);
