// from server: 100% by Yeetserama
// roc 2010-06 005d5840  unit: RBX::VDataModel::?$BoundFuncDesc  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005d5840
//
// 005d5840  6aff                 push -1
// 005d5842  68e8d09800           push 0x98d0e8
// 005d5847  64a100000000         mov eax, dword ptr fs:[0]
// 005d584d  50                   push eax
// 005d584e  64892500000000       mov dword ptr fs:[0], esp
// 005d5855  83ec14               sub esp, 0x14
// 005d5858  56                   push esi
// 005d5859  57                   push edi
// 005d585a  8bf9                 mov edi, ecx
// 005d585c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 005d585f  8b4740               mov eax, dword ptr [edi + 0x40]
// 005d5862  89442408             mov dword ptr [esp + 8], eax
// 005d5866  85c9                 test ecx, ecx
// 005d5868  7409                 je 0x5d5873
// 005d586a  8b11                 mov edx, dword ptr [ecx]
// 005d586c  8b4208               mov eax, dword ptr [edx + 8]
// 005d586f  ffd0                 call eax
// 005d5871  eb02                 jmp 0x5d5875
// 005d5873  33c0                 xor eax, eax
// 005d5875  8944240c             mov dword ptr [esp + 0xc], eax
// 005d5879  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 005d587d  8b11                 mov edx, dword ptr [ecx]
// 005d587f  8b5204               mov edx, dword ptr [edx + 4]
// 005d5882  8d442408             lea eax, [esp + 8]
// 005d5886  50                   push eax
// 005d5887  6a01                 push 1
// 005d5889  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005d5891  ffd2                 call edx
// 005d5893  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005d5897  6a00                 push 0
// 005d5899  68b051b800           push 0xb851b0
// 005d589e  684090b700           push 0xb79040
// 005d58a3  6a00                 push 0
// 005d58a5  50                   push eax
// 005d58a6  e83f331d00           call 0x7a8bea
// 005d58ab  8bf0                 mov esi, eax
// 005d58ad  83c414               add esp, 0x14
// 005d58b0  85f6                 test esi, esi
// 005d58b2  751e                 jne 0x5d58d2
// 005d58b4  68540aa000           push 0xa00a54
// 005d58b9  8d4c2414             lea ecx, [esp + 0x14]
// 005d58bd  ff159ca89e00         call dword ptr [0x9ea89c]
// 005d58c3  689022b100           push 0xb12290
// 005d58c8  8d4c2414             lea ecx, [esp + 0x14]
// 005d58cc  51                   push ecx
// 005d58cd  e8e0301d00           call 0x7a89b2
// 005d58d2  8d4c2408             lea ecx, [esp + 8]
// 005d58d6  e8f532fdff           call 0x5a8bd0
// 005d58db  0fb610               movzx edx, byte ptr [eax]
// 005d58de  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 005d58e1  8b4738               mov eax, dword ptr [edi + 0x38]
// 005d58e4  52                   push edx
// 005d58e5  03ce                 add ecx, esi
// 005d58e7  ffd0                 call eax
// 005d58e9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005d58ed  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 005d58f5  85c9                 test ecx, ecx
// 005d58f7  7408                 je 0x5d5901
// 005d58f9  8b11                 mov edx, dword ptr [ecx]
// 005d58fb  8b02                 mov eax, dword ptr [edx]
// 005d58fd  6a01                 push 1
// 005d58ff  ffd0                 call eax
// 005d5901  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005d5905  5f                   pop edi
// 005d5906  5e                   pop esi
// 005d5907  64890d00000000       mov dword ptr fs:[0], ecx
// 005d590e  83c420               add esp, 0x20
// 005d5911  c20800               ret 8
// copied from an identical function in another client (function ?invoke@S@ns_ROCX000005@@QAEXPAXPAUArguments@2@@Z)

namespace ns_ROCX000005 {
// from server: 100% by colin
struct ValueOwner {
    virtual ~ValueOwner();
    virtual void reserved();
    virtual ValueOwner* clone() = 0;
};

struct Value {
    void* data;
    ValueOwner* owner;

    Value(const Value& other);
    ~Value();
    unsigned char* get();
    static ValueOwner* copyOwner(ValueOwner* owner);
};

inline ValueOwner* Value::copyOwner(ValueOwner* owner)
{
    if (owner)
        return owner->clone();
    return 0;
}

inline Value::Value(const Value& other)
    : data(other.data), owner(copyOwner(other.owner))
{
}

inline Value::~Value()
{
    if (owner)
        delete owner;
}

struct Arguments {
    virtual void reserved();
    virtual void read(int index, Value* value) = 0;
};

namespace std {
    class bad_cast {
        void* vtable;
        const char* message;
        int ownsMessage;
    };
}

extern std::bad_cast* (__thiscall* badCastConstruct)(
    std::bad_cast*, const char*);

extern char sourceType;
extern char destinationType;
extern char badCastThrowInfo;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

extern "C" __declspec(noreturn) void __stdcall throwException(
    void*, void*);

struct S {
    char padding[0x38];
    void (__thiscall* callback)(void*, int);
    int adjustment;
    Value defaultValue;

    void invoke(void* object, Arguments* arguments);
};

void S::invoke(void* object, Arguments* arguments)
{
    Value value(defaultValue);
    arguments->read(1, &value);

    void* peer = __RTDynamicCast(
        object, 0, &sourceType, &destinationType, 0);

    if (!peer) {
        std::bad_cast error;
        badCastConstruct(&error, "bad cast");
        throwException(&error, &badCastThrowInfo);
    }

    callback(static_cast<char*>(peer) + adjustment, *value.get());
}
}
