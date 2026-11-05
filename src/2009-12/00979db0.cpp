// from server: 100% by nuck16
// roc 2009-12 00979db0  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979db0
//
// 00979db0  6a01                 push 1
// 00979db2  68b8b19b00           push 0x9bb1b8
// 00979db7  688c269e00           push 0x9e268c
// 00979dbc  689c000000           push 0x9c
// 00979dc1  b92869b900           mov ecx, 0xb96928
// 00979dc6  e87559dcff           call 0x73f740
// 00979dcb  68208c9800           push 0x988c20
// 00979dd0  e854abe7ff           call 0x7f4929
// 00979dd5  59                   pop ecx
// 00979dd6  c3                   ret 

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

static Desc desc(156, "ItemRemoved", "instance", 1);
