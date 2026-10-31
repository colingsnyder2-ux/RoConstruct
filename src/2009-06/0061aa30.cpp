// from server: 75% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00589d60  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 364 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00589d60
//
// 00589d60  6aff                 push -1
// 00589d62  68d2157d00           push 0x7d15d2
// 00589d67  64a100000000         mov eax, dword ptr fs:[0]
// 00589d6d  50                   push eax
// 00589d6e  64892500000000       mov dword ptr fs:[0], esp
// 00589d75  83ec40               sub esp, 0x40
// 00589d78  53                   push ebx
// 00589d79  56                   push esi
// 00589d7a  8bf1                 mov esi, ecx
// 00589d7c  8d4c242c             lea ecx, [esp + 0x2c]
// 00589d80  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00589d88  ff1560248000         call dword ptr [0x802460]
// 00589d8e  80be6501000000       cmp byte ptr [esi + 0x165], 0
// 00589d95  bb01000000           mov ebx, 1
// 00589d9a  895c2450             mov dword ptr [esp + 0x50], ebx
// 00589d9e  0f84ac000000         je 0x589e50
// 00589da4  6a00                 push 0
// 00589da6  8d442430             lea eax, [esp + 0x30]
// 00589daa  50                   push eax
// 00589dab  8bce                 mov ecx, esi
// 00589dad  e8beddffff           call 0x587b70
// 00589db2  84c0                 test al, al
// 00589db4  0f8496000000         je 0x589e50
// 00589dba  6a02                 push 2
// 00589dbc  8d4c2418             lea ecx, [esp + 0x18]
// 00589dc0  e87bfeffff           call 0x589c40
// 00589dc5  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00589dc9  2b4c2420             sub ecx, dword ptr [esp + 0x20]
// 00589dcd  8b3590288000         mov esi, dword ptr [0x802890]
// 00589dd3  c1f903               sar ecx, 3
// 00589dd6  c644245002           mov byte ptr [esp + 0x50], 2
// 00589ddb  885c240b             mov byte ptr [esp + 0xb], bl
// 00589ddf  85c9                 test ecx, ecx
// 00589de1  7702                 ja 0x589de5
// 00589de3  ffd6                 call esi
// 00589de5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00589de9  8d54240b             lea edx, [esp + 0xb]
// 00589ded  52                   push edx
// 00589dee  e81d08e8ff           call 0x40a610
// 00589df3  8b442424             mov eax, dword ptr [esp + 0x24]
// 00589df7  2b442420             sub eax, dword ptr [esp + 0x20]
// 00589dfb  c1f803               sar eax, 3
// 00589dfe  3bc3                 cmp eax, ebx
// 00589e00  7702                 ja 0x589e04
// 00589e02  ffd6                 call esi
// 00589e04  8b742420             mov esi, dword ptr [esp + 0x20]
// 00589e08  83c608               add esi, 8
// 00589e0b  e8e02ffeff           call 0x56cdf0
// 00589e10  8d4c242c             lea ecx, [esp + 0x2c]
// 00589e14  51                   push ecx
// 00589e15  8906                 mov dword ptr [esi], eax
// 00589e17  8d4c2414             lea ecx, [esp + 0x14]
// 00589e1b  83c604               add esi, 4
// 00589e1e  e80dd4e8ff           call 0x417230
// 00589e23  3bc6                 cmp eax, esi
// 00589e25  7408                 je 0x589e2f
// 00589e27  8b16                 mov edx, dword ptr [esi]
// 00589e29  8b08                 mov ecx, dword ptr [eax]
// 00589e2b  8910                 mov dword ptr [eax], edx
// 00589e2d  890e                 mov dword ptr [esi], ecx
// 00589e2f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00589e33  85c9                 test ecx, ecx
// 00589e35  7407                 je 0x589e3e
// 00589e37  8b01                 mov eax, dword ptr [ecx]
// 00589e39  8b10                 mov edx, dword ptr [eax]
// 00589e3b  53                   push ebx
// 00589e3c  ffd2                 call edx
// 00589e3e  8b742458             mov esi, dword ptr [esp + 0x58]
// 00589e42  8d442414             lea eax, [esp + 0x14]
// 00589e46  50                   push eax
// 00589e47  8bce                 mov ecx, esi
// 00589e49  e88260fdff           call 0x55fed0
// 00589e4e  eb47                 jmp 0x589e97
// 00589e50  53                   push ebx
// 00589e51  8d4c2418             lea ecx, [esp + 0x18]
// 00589e55  e8e6fdffff           call 0x589c40
// 00589e5a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00589e5e  2b4c2420             sub ecx, dword ptr [esp + 0x20]
// 00589e62  c644245003           mov byte ptr [esp + 0x50], 3
// 00589e67  c1f903               sar ecx, 3
// 00589e6a  c644240b00           mov byte ptr [esp + 0xb], 0
// 00589e6f  85c9                 test ecx, ecx
// 00589e71  7706                 ja 0x589e79
// 00589e73  ff1590288000         call dword ptr [0x802890]
// 00589e79  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00589e7d  8d54240b             lea edx, [esp + 0xb]
// 00589e81  52                   push edx
// 00589e82  e88907e8ff           call 0x40a610
// 00589e87  8b742458             mov esi, dword ptr [esp + 0x58]
// 00589e8b  8d442414             lea eax, [esp + 0x14]
// 00589e8f  50                   push eax
// 00589e90  8bce                 mov ecx, esi
// 00589e92  e83960fdff           call 0x55fed0
// 00589e97  8d4c2414             lea ecx, [esp + 0x14]
// 00589e9b  895c240c             mov dword ptr [esp + 0xc], ebx
// 00589e9f  885c2450             mov byte ptr [esp + 0x50], bl
// 00589ea3  e88837eaff           call 0x42d630
// 00589ea8  8d4c242c             lea ecx, [esp + 0x2c]
// 00589eac  c644245000           mov byte ptr [esp + 0x50], 0
// 00589eb1  ff1568248000         call dword ptr [0x802468]
// 00589eb7  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00589ebb  8bc6                 mov eax, esi
// 00589ebd  5e                   pop esi
// 00589ebe  5b                   pop ebx
// 00589ebf  64890d00000000       mov dword ptr fs:[0], ecx
// 00589ec6  83c44c               add esp, 0x4c
// 00589ec9  c20400               ret 4

namespace std {
template<class T> struct char_traits;
template<class T> class allocator {};

template<class C, class T = char_traits<C>, class A = allocator<C> >
class basic_string {
    A alloc;
    union {
        C buffer[16];
        C* pointer;
    } storage;
    unsigned length;
    unsigned capacity;
public:
    basic_string();
    ~basic_string();
};
}

typedef std::basic_string<char> String;

extern void (__thiscall *stringConstructor)(String*);
extern void (__thiscall *stringDestructor)(String*);
extern "C" void (__cdecl * const _invalid_parameter_noinfo)();

namespace std {
template<class C, class T, class A>
inline basic_string<C, T, A>::basic_string() {
    stringConstructor(this);
}

template<class C, class T, class A>
inline basic_string<C, T, A>::~basic_string() {
    stringDestructor(this);
}
}

struct Object {
    virtual void destroy(unsigned);
};

struct Holder {
    Object* pointer;

    Holder(const String&);
    ~Holder();
    void swap(Object*&);
};

inline Holder::~Holder() {
    if (pointer)
        pointer->destroy(1);
}

inline void Holder::swap(Object*& other) {
    if (&pointer != &other) {
        Object* saved = pointer;
        pointer = other;
        other = saved;
    }
}

struct Value {
    void* type;
    Object* object;
    void assign(const bool&);
};

struct Values {
    unsigned reserved[3];
    Value* first;
    Value* last;
    Value* limit;

    Values(unsigned);
    ~Values();
    Value& at(unsigned);
};

inline Value& Values::at(unsigned index) {
    if (static_cast<unsigned>(last - first) <= index)
        _invalid_parameter_noinfo();
    return first[index];
}

struct Result {
    Result(const Values&);
    ~Result();
};

extern void* __cdecl stringType();

struct S {
    char padding[0x165];
    bool enabled;

    bool query(String&, int);
    Result f();
};

Result S::f() {
    String text;
    if (enabled && query(text, 0)) {
        Values values(2);
        void (__cdecl *invalid)() = _invalid_parameter_noinfo;
        bool flag = true;
        if (static_cast<unsigned>(values.last - values.first) <= 0)
            invalid();
        values.first[0].assign(flag);

        if (static_cast<unsigned>(values.last - values.first) <= 1)
            invalid();
        Value& value = values.first[1];
        value.type = stringType();
        Object*& destination = value.object;
        Holder(text).swap(destination);
        return Result(values);
    } else {
        Values values(1);
        bool flag = false;
        values.at(0).assign(flag);
        return Result(values);
    }
}
