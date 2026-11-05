// from server: 100% by nuck16
// roc 2009-12 0097b230  unit: seg_00970000  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b230
//
// 0097b230  33c9                 xor ecx, ecx
// 0097b232  51                   push ecx
// 0097b233  68ec709e00           push 0x9e70ec
// 0097b238  68d8709e00           push 0x9e70d8
// 0097b23d  68cc709e00           push 0x9e70cc
// 0097b242  68c0709e00           push 0x9e70c0
// 0097b247  51                   push ecx
// 0097b248  b8b0e37500           mov eax, 0x75e3b0
// 0097b24d  50                   push eax
// 0097b24e  b91079b900           mov ecx, 0xb97910
// 0097b253  e8b837deff           call 0x75ea10
// 0097b258  6840989800           push 0x989840
// 0097b25d  e8c796e7ff           call 0x7f4929
// 0097b262  59                   pop ecx
// 0097b263  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "MouseDown", "MousePart", "PointOnMousePart", "Parts", 0);
