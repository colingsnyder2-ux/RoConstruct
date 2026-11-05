// from server: 100% by nuck16
// roc 2009-12 0097b920  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b920
//
// 0097b920  6a01                 push 1
// 0097b922  68f4f99c00           push 0x9cf9f4
// 0097b927  6898cc9d00           push 0x9dcc98
// 0097b92c  68ec000000           push 0xec
// 0097b931  b9c87fb900           mov ecx, 0xb97fc8
// 0097b936  e8150cdfff           call 0x76c550
// 0097b93b  68509b9800           push 0x989b50
// 0097b940  e8e48fe7ff           call 0x7f4929
// 0097b945  59                   pop ecx
// 0097b946  c3                   ret 

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

static Desc desc(236, "KeyUp", "Key", 1);
