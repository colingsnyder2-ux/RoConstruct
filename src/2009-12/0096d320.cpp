// from server: 100% by nuck16
// roc 2009-12 0096d320  unit: seg_00960000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d320
//
// 0096d320  6a01                 push 1
// 0096d322  6a14                 push 0x14
// 0096d324  68dcbe9b00           push 0x9bbedc
// 0096d329  33c9                 xor ecx, ecx
// 0096d32b  51                   push ecx
// 0096d32c  68a4cb9b00           push 0x9bcba4
// 0096d331  689ccb9b00           push 0x9bcb9c
// 0096d336  51                   push ecx
// 0096d337  b890bf5200           mov eax, 0x52bf90
// 0096d33c  50                   push eax
// 0096d33d  b9b004b800           mov ecx, 0xb804b0
// 0096d342  e81900bcff           call 0x52d360
// 0096d347  6810059800           push 0x980510
// 0096d34c  e8d875e8ff           call 0x7f4929
// 0096d351  59                   pop ecx
// 0096d352  c3                   ret 

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

static Desc desc(&Owner::m0, "Start", "port", 0, "threadSleepTime", 20, 1);
