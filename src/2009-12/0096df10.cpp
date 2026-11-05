// from server: 100% by nuck16
// roc 2009-12 0096df10  unit: seg_00960000  size: 45 bytes
//
// 0096df10  33c9                 xor ecx, ecx
// 0096df12  51                   push ecx
// 0096df13  6a0f                 push 0xf
// 0096df15  51                   push ecx
// 0096df16  51                   push ecx
// 0096df17  b810bf6200           mov eax, 0x62bf10
// 0096df1c  50                   push eax
// 0096df1d  6864b79a00           push 0x9ab764
// 0096df22  680cb99c00           push 0x9cb90c
// 0096df27  b9684eb800           mov ecx, 0xb84e68
// 0096df2c  e82f16ccff           call 0x62f560
// 0096df31  6880159800           push 0x981580
// 0096df36  e8ee69e8ff           call 0x7f4929
// 0096df3b  59                   pop ecx
// 0096df3c  c3                   ret 

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

static Desc desc("CpuSpeed", "Profile", &Owner::m0, 0, 15, 0);
