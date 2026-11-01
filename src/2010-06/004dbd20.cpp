// from server: 100% by Yeetserama
// roc 2010-06 004dbd20  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004dbd20
//
// 004dbd20  6aff                 push -1
// 004dbd22  68e8d09800           push 0x98d0e8
// 004dbd27  64a100000000         mov eax, dword ptr fs:[0]
// 004dbd2d  50                   push eax
// 004dbd2e  64892500000000       mov dword ptr fs:[0], esp
// 004dbd35  83ec14               sub esp, 0x14
// 004dbd38  56                   push esi
// 004dbd39  57                   push edi
// 004dbd3a  8bf9                 mov edi, ecx
// 004dbd3c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 004dbd3f  8b4740               mov eax, dword ptr [edi + 0x40]
// 004dbd42  89442408             mov dword ptr [esp + 8], eax
// 004dbd46  85c9                 test ecx, ecx
// 004dbd48  7409                 je 0x4dbd53
// 004dbd4a  8b11                 mov edx, dword ptr [ecx]
// 004dbd4c  8b4208               mov eax, dword ptr [edx + 8]
// 004dbd4f  ffd0                 call eax
// 004dbd51  eb02                 jmp 0x4dbd55
// 004dbd53  33c0                 xor eax, eax
// 004dbd55  8944240c             mov dword ptr [esp + 0xc], eax
// 004dbd59  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004dbd5d  8b11                 mov edx, dword ptr [ecx]
// 004dbd5f  8b5204               mov edx, dword ptr [edx + 4]
// 004dbd62  8d442408             lea eax, [esp + 8]
// 004dbd66  50                   push eax
// 004dbd67  6a01                 push 1
// 004dbd69  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004dbd71  ffd2                 call edx
// 004dbd73  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004dbd77  6a00                 push 0
// 004dbd79  68c815b900           push 0xb915c8
// 004dbd7e  684090b700           push 0xb79040
// 004dbd83  6a00                 push 0
// 004dbd85  50                   push eax
// 004dbd86  e85fce2c00           call 0x7a8bea
// 004dbd8b  8bf0                 mov esi, eax
// 004dbd8d  83c414               add esp, 0x14
// 004dbd90  85f6                 test esi, esi
// 004dbd92  751e                 jne 0x4dbdb2
// 004dbd94  68540aa000           push 0xa00a54
// 004dbd99  8d4c2414             lea ecx, [esp + 0x14]
// 004dbd9d  ff159ca89e00         call dword ptr [0x9ea89c]
// 004dbda3  689022b100           push 0xb12290
// 004dbda8  8d4c2414             lea ecx, [esp + 0x14]
// 004dbdac  51                   push ecx
// 004dbdad  e800cc2c00           call 0x7a89b2
// 004dbdb2  8d4c2408             lea ecx, [esp + 8]
// 004dbdb6  e815ce0c00           call 0x5a8bd0
// 004dbdbb  0fb610               movzx edx, byte ptr [eax]
// 004dbdbe  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 004dbdc1  8b4738               mov eax, dword ptr [edi + 0x38]
// 004dbdc4  52                   push edx
// 004dbdc5  03ce                 add ecx, esi
// 004dbdc7  ffd0                 call eax
// 004dbdc9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004dbdcd  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004dbdd5  85c9                 test ecx, ecx
// 004dbdd7  7408                 je 0x4dbde1
// 004dbdd9  8b11                 mov edx, dword ptr [ecx]
// 004dbddb  8b02                 mov eax, dword ptr [edx]
// 004dbddd  6a01                 push 1
// 004dbddf  ffd0                 call eax
// 004dbde1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004dbde5  5f                   pop edi
// 004dbde6  5e                   pop esi
// 004dbde7  64890d00000000       mov dword ptr fs:[0], ecx
// 004dbdee  83c420               add esp, 0x20
// 004dbdf1  c20800               ret 8
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
