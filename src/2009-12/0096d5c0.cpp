// from server: 100% by nuck16
// roc 2009-12 0096d5c0  unit: seg_00960000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d5c0
//
// 0096d5c0  6a01                 push 1
// 0096d5c2  33c9                 xor ecx, ecx
// 0096d5c4  687ce39b00           push 0x9be37c
// 0096d5c9  51                   push ecx
// 0096d5ca  b810835300           mov eax, 0x538310
// 0096d5cf  50                   push eax
// 0096d5d0  b91807b800           mov ecx, 0xb80718
// 0096d5d5  e8d675bdff           call 0x544bb0
// 0096d5da  6840069800           push 0x980640
// 0096d5df  e84573e8ff           call 0x7f4929
// 0096d5e4  59                   pop ecx
// 0096d5e5  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "CloseConnection", 1);
