// from server: 100% by nuck16
// roc 2009-12 0096ec30  unit: seg_00960000  size: 45 bytes
//
// 0096ec30  33c9                 xor ecx, ecx
// 0096ec32  51                   push ecx
// 0096ec33  6a09                 push 9
// 0096ec35  51                   push ecx
// 0096ec36  51                   push ecx
// 0096ec37  b820964100           mov eax, 0x419620
// 0096ec3c  50                   push eax
// 0096ec3d  6884b09b00           push 0x9bb084
// 0096ec42  68a8bf9c00           push 0x9cbfa8
// 0096ec47  b99052b800           mov ecx, 0xb85290
// 0096ec4c  e89f54ccff           call 0x6340f0
// 0096ec51  68e0179800           push 0x9817e0
// 0096ec56  e8ce5ce8ff           call 0x7f4929
// 0096ec5b  59                   pop ecx
// 0096ec5c  c3                   ret 

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

static Desc desc("className", "Data", &Owner::m0, 0, 9, 0);
