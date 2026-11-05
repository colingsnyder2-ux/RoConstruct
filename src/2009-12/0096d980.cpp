// from server: 100% by nuck16
// roc 2009-12 0096d980  unit: seg_00960000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d980
//
// 0096d980  6a01                 push 1
// 0096d982  33c9                 xor ecx, ecx
// 0096d984  51                   push ecx
// 0096d985  6888e89b00           push 0x9be888
// 0096d98a  51                   push ecx
// 0096d98b  6878e89b00           push 0x9be878
// 0096d990  6860e89b00           push 0x9be860
// 0096d995  51                   push ecx
// 0096d996  b870ff5400           mov eax, 0x54ff70
// 0096d99b  50                   push eax
// 0096d99c  b95008b800           mov ecx, 0xb80850
// 0096d9a1  e8fa33beff           call 0x550da0
// 0096d9a6  68d0099800           push 0x9809d0
// 0096d9ab  e8796fe8ff           call 0x7f4929
// 0096d9b0  59                   pop ecx
// 0096d9b1  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int, const char *, int, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "ApplyNetworkSimulator", "minExtraPing", 0, "extraPingVariance", 0, 1);
