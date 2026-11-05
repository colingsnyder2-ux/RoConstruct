// from server: 100% by nuck16
// roc 2009-12 0096d5f0  unit: seg_00960000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d5f0
//
// 0096d5f0  6a01                 push 1
// 0096d5f2  33c9                 xor ecx, ecx
// 0096d5f4  688ce39b00           push 0x9be38c
// 0096d5f9  51                   push ecx
// 0096d5fa  b8c0365400           mov eax, 0x5436c0
// 0096d5ff  50                   push eax
// 0096d600  b95807b800           mov ecx, 0xb80758
// 0096d605  e88676bdff           call 0x544c90
// 0096d60a  68c0069800           push 0x9806c0
// 0096d60f  e81573e8ff           call 0x7f4929
// 0096d614  59                   pop ecx
// 0096d615  c3                   ret 

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

static Desc desc(&Owner::m0, "GetPlayer", 1);
