// from server: 100% by nuck16
// roc 2009-12 0096df40  unit: seg_00960000  size: 45 bytes
//
// 0096df40  33c9                 xor ecx, ecx
// 0096df42  51                   push ecx
// 0096df43  6a0f                 push 0xf
// 0096df45  51                   push ecx
// 0096df46  51                   push ecx
// 0096df47  b840bf6200           mov eax, 0x62bf40
// 0096df4c  50                   push eax
// 0096df4d  6864b79a00           push 0x9ab764
// 0096df52  6818b99c00           push 0x9cb918
// 0096df57  b9284eb800           mov ecx, 0xb84e28
// 0096df5c  e8ff15ccff           call 0x62f560
// 0096df61  6800109800           push 0x981000
// 0096df66  e8be69e8ff           call 0x7f4929
// 0096df6b  59                   pop ecx
// 0096df6c  c3                   ret 

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
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("CpuCount", "Profile", &Owner::m0, 0, 15, 0);
