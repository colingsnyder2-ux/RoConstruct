// from server: 100% by nuck16
// roc 2009-12 0097b8f0  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b8f0
//
// 0097b8f0  6a01                 push 1
// 0097b8f2  68f4f99c00           push 0x9cf9f4
// 0097b8f7  6890cc9d00           push 0x9dcc90
// 0097b8fc  68e4000000           push 0xe4
// 0097b901  b9cc81b900           mov ecx, 0xb981cc
// 0097b906  e8450cdfff           call 0x76c550
// 0097b90b  68509d9800           push 0x989d50
// 0097b910  e81490e7ff           call 0x7f4929
// 0097b915  59                   pop ecx
// 0097b916  c3                   ret 

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

static Desc desc(228, "KeyDown", "Key", 1);
