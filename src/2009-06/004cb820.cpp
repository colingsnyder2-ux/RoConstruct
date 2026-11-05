// from server: 100% by EspClaude
// roc 2009-06 004cb820  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 282 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004cb820
//
// 004cb820  6aff                 push -1
// 004cb822  68c0a48500           push 0x85a4c0
// 004cb827  64a100000000         mov eax, dword ptr fs:[0]
// 004cb82d  50                   push eax
// 004cb82e  64892500000000       mov dword ptr fs:[0], esp
// 004cb835  83ec1c               sub esp, 0x1c
// 004cb838  56                   push esi
// 004cb839  57                   push edi
// 004cb83a  8bf9                 mov edi, ecx
// 004cb83c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 004cb83f  8b4740               mov eax, dword ptr [edi + 0x40]
// 004cb842  89442410             mov dword ptr [esp + 0x10], eax
// 004cb846  85c9                 test ecx, ecx
// 004cb848  7409                 je 0x4cb853
// 004cb84a  8b11                 mov edx, dword ptr [ecx]
// 004cb84c  8b4208               mov eax, dword ptr [edx + 8]
// 004cb84f  ffd0                 call eax
// 004cb851  eb02                 jmp 0x4cb855
// 004cb853  33c0                 xor eax, eax
// 004cb855  89442414             mov dword ptr [esp + 0x14], eax
// 004cb859  8b742438             mov esi, dword ptr [esp + 0x38]
// 004cb85d  8b16                 mov edx, dword ptr [esi]
// 004cb85f  8b5204               mov edx, dword ptr [edx + 4]
// 004cb862  8d442410             lea eax, [esp + 0x10]
// 004cb866  50                   push eax
// 004cb867  6a01                 push 1
// 004cb869  8bce                 mov ecx, esi
// 004cb86b  c744243400000000     mov dword ptr [esp + 0x34], 0
// 004cb873  ffd2                 call edx
// 004cb875  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 004cb878  8b4748               mov eax, dword ptr [edi + 0x48]
// 004cb87b  89442408             mov dword ptr [esp + 8], eax
// 004cb87f  85c9                 test ecx, ecx
// 004cb881  7409                 je 0x4cb88c
// 004cb883  8b11                 mov edx, dword ptr [ecx]
// 004cb885  8b4208               mov eax, dword ptr [edx + 8]
// 004cb888  ffd0                 call eax
// 004cb88a  eb02                 jmp 0x4cb88e
// 004cb88c  33c0                 xor eax, eax
// 004cb88e  8944240c             mov dword ptr [esp + 0xc], eax
// 004cb892  8b16                 mov edx, dword ptr [esi]
// 004cb894  8b5204               mov edx, dword ptr [edx + 4]
// 004cb897  8d442408             lea eax, [esp + 8]
// 004cb89b  50                   push eax
// 004cb89c  6a02                 push 2
// 004cb89e  8bce                 mov ecx, esi
// 004cb8a0  c644243401           mov byte ptr [esp + 0x34], 1
// 004cb8a5  ffd2                 call edx
// 004cb8a7  8b442434             mov eax, dword ptr [esp + 0x34]
// 004cb8ab  6a00                 push 0
// 004cb8ad  6898009f00           push 0x9f0098
// 004cb8b2  68c4bf9d00           push 0x9dbfc4
// 004cb8b7  6a00                 push 0
// 004cb8b9  50                   push eax
// 004cb8ba  e8bbe32400           call 0x719c7a
// 004cb8bf  83c414               add esp, 0x14
// 004cb8c2  85c0                 test eax, eax
// 004cb8c4  751e                 jne 0x4cb8e4
// 004cb8c6  6850d38a00           push 0x8ad350
// 004cb8cb  8d4c241c             lea ecx, [esp + 0x1c]
// 004cb8cf  ff1570e98900         call dword ptr [0x89e970]
// 004cb8d5  68b04b9800           push 0x984bb0
// 004cb8da  8d4c241c             lea ecx, [esp + 0x1c]
// 004cb8de  51                   push ecx
// 004cb8df  e866e12400           call 0x719a4a
// 004cb8e4  8d542408             lea edx, [esp + 8]
// 004cb8e8  52                   push edx
// 004cb8e9  8d4c2414             lea ecx, [esp + 0x14]
// 004cb8ed  51                   push ecx
// 004cb8ee  83c604               add esi, 4
// 004cb8f1  56                   push esi
// 004cb8f2  50                   push eax
// 004cb8f3  8bcf                 mov ecx, edi
// 004cb8f5  e896feffff           call 0x4cb790
// 004cb8fa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004cb8fe  c644242c00           mov byte ptr [esp + 0x2c], 0
// 004cb903  85c9                 test ecx, ecx
// 004cb905  7408                 je 0x4cb90f
// 004cb907  8b11                 mov edx, dword ptr [ecx]
// 004cb909  8b02                 mov eax, dword ptr [edx]
// 004cb90b  6a01                 push 1
// 004cb90d  ffd0                 call eax
// 004cb90f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004cb913  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004cb91b  85c9                 test ecx, ecx
// 004cb91d  7408                 je 0x4cb927
// 004cb91f  8b11                 mov edx, dword ptr [ecx]
// 004cb921  8b02                 mov eax, dword ptr [edx]
// 004cb923  6a01                 push 1
// 004cb925  ffd0                 call eax
// 004cb927  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004cb92b  5f                   pop edi
// 004cb92c  5e                   pop esi
// 004cb92d  64890d00000000       mov dword ptr fs:[0], ecx
// 004cb934  83c428               add esp, 0x28
// 004cb937  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000024@@QAEXPAXPAUArguments@2@@Z)

namespace ns_ROCX000024 {
struct Holder {
    virtual ~Holder();
    virtual void reserved();
    virtual Holder* clone();

    static Holder* copy(Holder*);
};

__forceinline Holder* Holder::copy(Holder* h)
{
    if (h)
        return h->clone();
    return 0;
}

struct Value {
    void* object;
    Holder* holder;

    Value(const Value&);
    ~Value();
};

__forceinline Value::Value(const Value& other)
    : object(other.object), holder(Holder::copy(other.holder))
{
}

__forceinline Value::~Value()
{
    Holder* h = holder;
    if (h)
        delete h;
}

struct Arguments {
    virtual void reserved();
    virtual void get(int index, Value* value);
};

namespace std {
    struct bad_cast {
        char storage[12];
        bad_cast(const char*);
    };
}

typedef void (__thiscall *BadCastConstructor)(std::bad_cast*, const char*);
extern BadCastConstructor constructBadCast;

__forceinline std::bad_cast::bad_cast(const char* message)
{
    constructBadCast(this, message);
}

extern unsigned char sourceType;
extern unsigned char destinationType;
extern unsigned char badCastThrowInfo;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

extern "C" __declspec(noreturn) void __stdcall throwException(void*, void*);

struct S {
    char padding[64];
    Value first;
    Value second;

    void invoke(void*, void*, Value*, Value*);
    void f(void*, Arguments*);
};

void S::f(void* instance, Arguments* arguments)
{
    Value a(first);
    arguments->get(1, &a);

    Value b(second);
    arguments->get(2, &b);

    void* converted = __RTDynamicCast(
        instance, 0, &sourceType, &destinationType, 0);

    if (!converted) {
        std::bad_cast error("bad cast");
        throwException(&error, &badCastThrowInfo);
    }

    invoke(converted, reinterpret_cast<char*>(arguments) + 4, &a, &b);
}
}
