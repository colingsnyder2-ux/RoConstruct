// from server: 100% by Yeetserama
// roc 2010-06 005ec7c0  unit: RBX::VChangeHistoryService::?$BoundFuncDesc  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ec7c0
//
// 005ec7c0  6aff                 push -1
// 005ec7c2  68e8d09800           push 0x98d0e8
// 005ec7c7  64a100000000         mov eax, dword ptr fs:[0]
// 005ec7cd  50                   push eax
// 005ec7ce  64892500000000       mov dword ptr fs:[0], esp
// 005ec7d5  83ec14               sub esp, 0x14
// 005ec7d8  56                   push esi
// 005ec7d9  57                   push edi
// 005ec7da  8bf9                 mov edi, ecx
// 005ec7dc  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 005ec7df  8b4740               mov eax, dword ptr [edi + 0x40]
// 005ec7e2  89442408             mov dword ptr [esp + 8], eax
// 005ec7e6  85c9                 test ecx, ecx
// 005ec7e8  7409                 je 0x5ec7f3
// 005ec7ea  8b11                 mov edx, dword ptr [ecx]
// 005ec7ec  8b4208               mov eax, dword ptr [edx + 8]
// 005ec7ef  ffd0                 call eax
// 005ec7f1  eb02                 jmp 0x5ec7f5
// 005ec7f3  33c0                 xor eax, eax
// 005ec7f5  8944240c             mov dword ptr [esp + 0xc], eax
// 005ec7f9  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 005ec7fd  8b11                 mov edx, dword ptr [ecx]
// 005ec7ff  8b5204               mov edx, dword ptr [edx + 4]
// 005ec802  8d442408             lea eax, [esp + 8]
// 005ec806  50                   push eax
// 005ec807  6a01                 push 1
// 005ec809  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005ec811  ffd2                 call edx
// 005ec813  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005ec817  6a00                 push 0
// 005ec819  6868b7ba00           push 0xbab768
// 005ec81e  684090b700           push 0xb79040
// 005ec823  6a00                 push 0
// 005ec825  50                   push eax
// 005ec826  e8bfc31b00           call 0x7a8bea
// 005ec82b  8bf0                 mov esi, eax
// 005ec82d  83c414               add esp, 0x14
// 005ec830  85f6                 test esi, esi
// 005ec832  751e                 jne 0x5ec852
// 005ec834  68540aa000           push 0xa00a54
// 005ec839  8d4c2414             lea ecx, [esp + 0x14]
// 005ec83d  ff159ca89e00         call dword ptr [0x9ea89c]
// 005ec843  689022b100           push 0xb12290
// 005ec848  8d4c2414             lea ecx, [esp + 0x14]
// 005ec84c  51                   push ecx
// 005ec84d  e860c11b00           call 0x7a89b2
// 005ec852  8d4c2408             lea ecx, [esp + 8]
// 005ec856  e875c3fbff           call 0x5a8bd0
// 005ec85b  0fb610               movzx edx, byte ptr [eax]
// 005ec85e  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 005ec861  8b4738               mov eax, dword ptr [edi + 0x38]
// 005ec864  52                   push edx
// 005ec865  03ce                 add ecx, esi
// 005ec867  ffd0                 call eax
// 005ec869  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005ec86d  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 005ec875  85c9                 test ecx, ecx
// 005ec877  7408                 je 0x5ec881
// 005ec879  8b11                 mov edx, dword ptr [ecx]
// 005ec87b  8b02                 mov eax, dword ptr [edx]
// 005ec87d  6a01                 push 1
// 005ec87f  ffd0                 call eax
// 005ec881  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005ec885  5f                   pop edi
// 005ec886  5e                   pop esi
// 005ec887  64890d00000000       mov dword ptr fs:[0], ecx
// 005ec88e  83c420               add esp, 0x20
// 005ec891  c20800               ret 8
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
