// from server: 100% by EspClaude
// roc 2009-06 004e2300  unit: RBX::Network::VPeer::?$BoundFuncDesc  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e2300
//
// 004e2300  6aff                 push -1
// 004e2302  6868398600           push 0x863968
// 004e2307  64a100000000         mov eax, dword ptr fs:[0]
// 004e230d  50                   push eax
// 004e230e  64892500000000       mov dword ptr fs:[0], esp
// 004e2315  83ec14               sub esp, 0x14
// 004e2318  56                   push esi
// 004e2319  57                   push edi
// 004e231a  8bf9                 mov edi, ecx
// 004e231c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 004e231f  8b4740               mov eax, dword ptr [edi + 0x40]
// 004e2322  89442408             mov dword ptr [esp + 8], eax
// 004e2326  85c9                 test ecx, ecx
// 004e2328  7409                 je 0x4e2333
// 004e232a  8b11                 mov edx, dword ptr [ecx]
// 004e232c  8b4208               mov eax, dword ptr [edx + 8]
// 004e232f  ffd0                 call eax
// 004e2331  eb02                 jmp 0x4e2335
// 004e2333  33c0                 xor eax, eax
// 004e2335  8944240c             mov dword ptr [esp + 0xc], eax
// 004e2339  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004e233d  8b11                 mov edx, dword ptr [ecx]
// 004e233f  8b5204               mov edx, dword ptr [edx + 4]
// 004e2342  8d442408             lea eax, [esp + 8]
// 004e2346  50                   push eax
// 004e2347  6a01                 push 1
// 004e2349  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004e2351  ffd2                 call edx
// 004e2353  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004e2357  6a00                 push 0
// 004e2359  6838089f00           push 0x9f0838
// 004e235e  68c4bf9d00           push 0x9dbfc4
// 004e2363  6a00                 push 0
// 004e2365  50                   push eax
// 004e2366  e80f792300           call 0x719c7a
// 004e236b  8bf0                 mov esi, eax
// 004e236d  83c414               add esp, 0x14
// 004e2370  85f6                 test esi, esi
// 004e2372  751e                 jne 0x4e2392
// 004e2374  6850d38a00           push 0x8ad350
// 004e2379  8d4c2414             lea ecx, [esp + 0x14]
// 004e237d  ff1570e98900         call dword ptr [0x89e970]
// 004e2383  68b04b9800           push 0x984bb0
// 004e2388  8d4c2414             lea ecx, [esp + 0x14]
// 004e238c  51                   push ecx
// 004e238d  e8b8762300           call 0x719a4a
// 004e2392  8d4c2408             lea ecx, [esp + 8]
// 004e2396  e8b55b1000           call 0x5e7f50
// 004e239b  0fb610               movzx edx, byte ptr [eax]
// 004e239e  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 004e23a1  8b4738               mov eax, dword ptr [edi + 0x38]
// 004e23a4  52                   push edx
// 004e23a5  03ce                 add ecx, esi
// 004e23a7  ffd0                 call eax
// 004e23a9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004e23ad  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004e23b5  85c9                 test ecx, ecx
// 004e23b7  7408                 je 0x4e23c1
// 004e23b9  8b11                 mov edx, dword ptr [ecx]
// 004e23bb  8b02                 mov eax, dword ptr [edx]
// 004e23bd  6a01                 push 1
// 004e23bf  ffd0                 call eax
// 004e23c1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004e23c5  5f                   pop edi
// 004e23c6  5e                   pop esi
// 004e23c7  64890d00000000       mov dword ptr fs:[0], ecx
// 004e23ce  83c420               add esp, 0x20
// 004e23d1  c20800               ret 8
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
