// from server: 100% by EspClaude
// roc 2009-06 004d8080  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d8080
//
// 004d8080  6aff                 push -1
// 004d8082  6868398600           push 0x863968
// 004d8087  64a100000000         mov eax, dword ptr fs:[0]
// 004d808d  50                   push eax
// 004d808e  64892500000000       mov dword ptr fs:[0], esp
// 004d8095  83ec14               sub esp, 0x14
// 004d8098  56                   push esi
// 004d8099  57                   push edi
// 004d809a  8bf9                 mov edi, ecx
// 004d809c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 004d809f  8b4740               mov eax, dword ptr [edi + 0x40]
// 004d80a2  89442408             mov dword ptr [esp + 8], eax
// 004d80a6  85c9                 test ecx, ecx
// 004d80a8  7409                 je 0x4d80b3
// 004d80aa  8b11                 mov edx, dword ptr [ecx]
// 004d80ac  8b4208               mov eax, dword ptr [edx + 8]
// 004d80af  ffd0                 call eax
// 004d80b1  eb02                 jmp 0x4d80b5
// 004d80b3  33c0                 xor eax, eax
// 004d80b5  8944240c             mov dword ptr [esp + 0xc], eax
// 004d80b9  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004d80bd  8b11                 mov edx, dword ptr [ecx]
// 004d80bf  8b5204               mov edx, dword ptr [edx + 4]
// 004d80c2  8d442408             lea eax, [esp + 8]
// 004d80c6  50                   push eax
// 004d80c7  6a01                 push 1
// 004d80c9  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004d80d1  ffd2                 call edx
// 004d80d3  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004d80d7  6a00                 push 0
// 004d80d9  68002e9f00           push 0x9f2e00
// 004d80de  68c4bf9d00           push 0x9dbfc4
// 004d80e3  6a00                 push 0
// 004d80e5  50                   push eax
// 004d80e6  e88f1b2400           call 0x719c7a
// 004d80eb  8bf0                 mov esi, eax
// 004d80ed  83c414               add esp, 0x14
// 004d80f0  85f6                 test esi, esi
// 004d80f2  751e                 jne 0x4d8112
// 004d80f4  6850d38a00           push 0x8ad350
// 004d80f9  8d4c2414             lea ecx, [esp + 0x14]
// 004d80fd  ff1570e98900         call dword ptr [0x89e970]
// 004d8103  68b04b9800           push 0x984bb0
// 004d8108  8d4c2414             lea ecx, [esp + 0x14]
// 004d810c  51                   push ecx
// 004d810d  e838192400           call 0x719a4a
// 004d8112  8d4c2408             lea ecx, [esp + 8]
// 004d8116  e835fe1000           call 0x5e7f50
// 004d811b  0fb610               movzx edx, byte ptr [eax]
// 004d811e  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 004d8121  8b4738               mov eax, dword ptr [edi + 0x38]
// 004d8124  52                   push edx
// 004d8125  03ce                 add ecx, esi
// 004d8127  ffd0                 call eax
// 004d8129  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004d812d  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004d8135  85c9                 test ecx, ecx
// 004d8137  7408                 je 0x4d8141
// 004d8139  8b11                 mov edx, dword ptr [ecx]
// 004d813b  8b02                 mov eax, dword ptr [edx]
// 004d813d  6a01                 push 1
// 004d813f  ffd0                 call eax
// 004d8141  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004d8145  5f                   pop edi
// 004d8146  5e                   pop esi
// 004d8147  64890d00000000       mov dword ptr fs:[0], ecx
// 004d814e  83c420               add esp, 0x20
// 004d8151  c20800               ret 8
// copied from an identical function in another client (function ?invoke@S@ns_ROCX000011@@QAEXPAXPAUArguments@2@@Z)

namespace ns_ROCX000011 {
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
