// from server: 100% by Yeetserama
// roc 2010-06 004ff5b0  unit: RBX::Network::VPeer::?$BoundFuncDesc  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ff5b0
//
// 004ff5b0  6aff                 push -1
// 004ff5b2  68e8d09800           push 0x98d0e8
// 004ff5b7  64a100000000         mov eax, dword ptr fs:[0]
// 004ff5bd  50                   push eax
// 004ff5be  64892500000000       mov dword ptr fs:[0], esp
// 004ff5c5  83ec14               sub esp, 0x14
// 004ff5c8  56                   push esi
// 004ff5c9  57                   push edi
// 004ff5ca  8bf9                 mov edi, ecx
// 004ff5cc  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 004ff5cf  8b4740               mov eax, dword ptr [edi + 0x40]
// 004ff5d2  89442408             mov dword ptr [esp + 8], eax
// 004ff5d6  85c9                 test ecx, ecx
// 004ff5d8  7409                 je 0x4ff5e3
// 004ff5da  8b11                 mov edx, dword ptr [ecx]
// 004ff5dc  8b4208               mov eax, dword ptr [edx + 8]
// 004ff5df  ffd0                 call eax
// 004ff5e1  eb02                 jmp 0x4ff5e5
// 004ff5e3  33c0                 xor eax, eax
// 004ff5e5  8944240c             mov dword ptr [esp + 0xc], eax
// 004ff5e9  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004ff5ed  8b11                 mov edx, dword ptr [ecx]
// 004ff5ef  8b5204               mov edx, dword ptr [edx + 4]
// 004ff5f2  8d442408             lea eax, [esp + 8]
// 004ff5f6  50                   push eax
// 004ff5f7  6a01                 push 1
// 004ff5f9  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004ff601  ffd2                 call edx
// 004ff603  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004ff607  6a00                 push 0
// 004ff609  6830eeb800           push 0xb8ee30
// 004ff60e  684090b700           push 0xb79040
// 004ff613  6a00                 push 0
// 004ff615  50                   push eax
// 004ff616  e8cf952a00           call 0x7a8bea
// 004ff61b  8bf0                 mov esi, eax
// 004ff61d  83c414               add esp, 0x14
// 004ff620  85f6                 test esi, esi
// 004ff622  751e                 jne 0x4ff642
// 004ff624  68540aa000           push 0xa00a54
// 004ff629  8d4c2414             lea ecx, [esp + 0x14]
// 004ff62d  ff159ca89e00         call dword ptr [0x9ea89c]
// 004ff633  689022b100           push 0xb12290
// 004ff638  8d4c2414             lea ecx, [esp + 0x14]
// 004ff63c  51                   push ecx
// 004ff63d  e870932a00           call 0x7a89b2
// 004ff642  8d4c2408             lea ecx, [esp + 8]
// 004ff646  e885950a00           call 0x5a8bd0
// 004ff64b  0fb610               movzx edx, byte ptr [eax]
// 004ff64e  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 004ff651  8b4738               mov eax, dword ptr [edi + 0x38]
// 004ff654  52                   push edx
// 004ff655  03ce                 add ecx, esi
// 004ff657  ffd0                 call eax
// 004ff659  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004ff65d  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004ff665  85c9                 test ecx, ecx
// 004ff667  7408                 je 0x4ff671
// 004ff669  8b11                 mov edx, dword ptr [ecx]
// 004ff66b  8b02                 mov eax, dword ptr [edx]
// 004ff66d  6a01                 push 1
// 004ff66f  ffd0                 call eax
// 004ff671  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004ff675  5f                   pop edi
// 004ff676  5e                   pop esi
// 004ff677  64890d00000000       mov dword ptr fs:[0], ecx
// 004ff67e  83c420               add esp, 0x20
// 004ff681  c20800               ret 8
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
