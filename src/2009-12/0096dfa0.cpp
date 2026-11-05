// from server: 100% by nuck16
// roc 2009-12 0096dfa0  unit: seg_00960000  size: 45 bytes
//
// 0096dfa0  33c9                 xor ecx, ecx
// 0096dfa2  51                   push ecx
// 0096dfa3  6a0f                 push 0xf
// 0096dfa5  51                   push ecx
// 0096dfa6  51                   push ecx
// 0096dfa7  b870bf6200           mov eax, 0x62bf70
// 0096dfac  50                   push eax
// 0096dfad  6864b79a00           push 0x9ab764
// 0096dfb2  6834b99c00           push 0x9cb934
// 0096dfb7  b9244db800           mov ecx, 0xb84d24
// 0096dfbc  e85f14ccff           call 0x62f420
// 0096dfc1  6840109800           push 0x981040
// 0096dfc6  e85e69e8ff           call 0x7f4929
// 0096dfcb  59                   pop ecx
// 0096dfcc  c3                   ret 

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

static Desc desc("OsVer", "Profile", &Owner::m0, 0, 15, 0);
