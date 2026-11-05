// from server: 100% by EspClaude
// from server: 75% by EspClaude
// roc 2009-06 0061abb0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 370 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0061abb0
//
// 0061abb0  6aff                 push -1
// 0061abb2  68b2838600           push 0x8683b2
// 0061abb7  64a100000000         mov eax, dword ptr fs:[0]
// 0061abbd  50                   push eax
// 0061abbe  64892500000000       mov dword ptr fs:[0], esp
// 0061abc5  83ec40               sub esp, 0x40
// 0061abc8  53                   push ebx
// 0061abc9  56                   push esi
// 0061abca  8bf1                 mov esi, ecx
// 0061abcc  8d4c242c             lea ecx, [esp + 0x2c]
// 0061abd0  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0061abd8  ff15c0e48900         call dword ptr [0x89e4c0]
// 0061abde  80bec100000000       cmp byte ptr [esi + 0xc1], 0
// 0061abe5  bb01000000           mov ebx, 1
// 0061abea  895c2450             mov dword ptr [esp + 0x50], ebx
// 0061abee  0f84b2000000         je 0x61aca6
// 0061abf4  6a00                 push 0
// 0061abf6  8d442430             lea eax, [esp + 0x30]
// 0061abfa  50                   push eax
// 0061abfb  8bce                 mov ecx, esi
// 0061abfd  e83edfffff           call 0x618b40
// 0061ac02  84c0                 test al, al
// 0061ac04  0f849c000000         je 0x61aca6
// 0061ac0a  6a02                 push 2
// 0061ac0c  8d4c2418             lea ecx, [esp + 0x18]
// 0061ac10  e86bfcffff           call 0x61a880
// 0061ac15  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0061ac19  2b4c2420             sub ecx, dword ptr [esp + 0x20]
// 0061ac1d  8b35ace98900         mov esi, dword ptr [0x89e9ac]
// 0061ac23  c1f903               sar ecx, 3
// 0061ac26  c644245002           mov byte ptr [esp + 0x50], 2
// 0061ac2b  885c240b             mov byte ptr [esp + 0xb], bl
// 0061ac2f  85c9                 test ecx, ecx
// 0061ac31  7702                 ja 0x61ac35
// 0061ac33  ffd6                 call esi
// 0061ac35  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0061ac39  8d54240b             lea edx, [esp + 0xb]
// 0061ac3d  52                   push edx
// 0061ac3e  e8cdf0deff           call 0x409d10
// 0061ac43  8b442424             mov eax, dword ptr [esp + 0x24]
// 0061ac47  2b442420             sub eax, dword ptr [esp + 0x20]
// 0061ac4b  c1f803               sar eax, 3
// 0061ac4e  3bc3                 cmp eax, ebx
// 0061ac50  7702                 ja 0x61ac54
// 0061ac52  ffd6                 call esi
// 0061ac54  8b742420             mov esi, dword ptr [esp + 0x20]
// 0061ac58  011d38a5a400         add dword ptr [0xa4a538], ebx
// 0061ac5e  83c608               add esi, 8
// 0061ac61  e89ab0fcff           call 0x5e5d00
// 0061ac66  8d4c242c             lea ecx, [esp + 0x2c]
// 0061ac6a  51                   push ecx
// 0061ac6b  8906                 mov dword ptr [esi], eax
// 0061ac6d  8d4c2414             lea ecx, [esp + 0x14]
// 0061ac71  83c604               add esi, 4
// 0061ac74  e897b3e0ff           call 0x426010
// 0061ac79  3bc6                 cmp eax, esi
// 0061ac7b  7408                 je 0x61ac85
// 0061ac7d  8b16                 mov edx, dword ptr [esi]
// 0061ac7f  8b08                 mov ecx, dword ptr [eax]
// 0061ac81  8910                 mov dword ptr [eax], edx
// 0061ac83  890e                 mov dword ptr [esi], ecx
// 0061ac85  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0061ac89  85c9                 test ecx, ecx
// 0061ac8b  7407                 je 0x61ac94
// 0061ac8d  8b01                 mov eax, dword ptr [ecx]
// 0061ac8f  8b10                 mov edx, dword ptr [eax]
// 0061ac91  53                   push ebx
// 0061ac92  ffd2                 call edx
// 0061ac94  8b742458             mov esi, dword ptr [esp + 0x58]
// 0061ac98  8d442414             lea eax, [esp + 0x14]
// 0061ac9c  50                   push eax
// 0061ac9d  8bce                 mov ecx, esi
// 0061ac9f  e88cf4faff           call 0x5ca130
// 0061aca4  eb47                 jmp 0x61aced
// 0061aca6  53                   push ebx
// 0061aca7  8d4c2418             lea ecx, [esp + 0x18]
// 0061acab  e8d0fbffff           call 0x61a880
// 0061acb0  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0061acb4  2b4c2420             sub ecx, dword ptr [esp + 0x20]
// 0061acb8  c644245003           mov byte ptr [esp + 0x50], 3
// 0061acbd  c1f903               sar ecx, 3
// 0061acc0  c644240b00           mov byte ptr [esp + 0xb], 0
// 0061acc5  85c9                 test ecx, ecx
// 0061acc7  7706                 ja 0x61accf
// 0061acc9  ff15ace98900         call dword ptr [0x89e9ac]
// 0061accf  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0061acd3  8d54240b             lea edx, [esp + 0xb]
// 0061acd7  52                   push edx
// 0061acd8  e833f0deff           call 0x409d10
// 0061acdd  8b742458             mov esi, dword ptr [esp + 0x58]
// 0061ace1  8d442414             lea eax, [esp + 0x14]
// 0061ace5  50                   push eax
// 0061ace6  8bce                 mov ecx, esi
// 0061ace8  e843f4faff           call 0x5ca130
// 0061aced  8d4c2414             lea ecx, [esp + 0x14]
// 0061acf1  895c240c             mov dword ptr [esp + 0xc], ebx
// 0061acf5  885c2450             mov byte ptr [esp + 0x50], bl
// 0061acf9  e8c2b9e0ff           call 0x4266c0
// 0061acfe  8d4c242c             lea ecx, [esp + 0x2c]
// 0061ad02  c644245000           mov byte ptr [esp + 0x50], 0
// 0061ad07  ff15c4e48900         call dword ptr [0x89e4c4]
// 0061ad0d  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0061ad11  8bc6                 mov eax, esi
// 0061ad13  5e                   pop esi
// 0061ad14  5b                   pop ebx
// 0061ad15  64890d00000000       mov dword ptr fs:[0], ecx
// 0061ad1c  83c44c               add esp, 0x4c
// 0061ad1f  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 00589ed0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 364 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00589ed0
//
// 00589ed0  6aff                 push -1
// 00589ed2  68d2157d00           push 0x7d15d2
// 00589ed7  64a100000000         mov eax, dword ptr fs:[0]
// 00589edd  50                   push eax
// 00589ede  64892500000000       mov dword ptr fs:[0], esp
// 00589ee5  83ec40               sub esp, 0x40
// 00589ee8  53                   push ebx
// 00589ee9  56                   push esi
// 00589eea  8bf1                 mov esi, ecx
// 00589eec  8d4c242c             lea ecx, [esp + 0x2c]
// 00589ef0  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00589ef8  ff1560248000         call dword ptr [0x802460]
// 00589efe  80be6501000000       cmp byte ptr [esi + 0x165], 0
// 00589f05  bb01000000           mov ebx, 1
// 00589f0a  895c2450             mov dword ptr [esp + 0x50], ebx
// 00589f0e  0f84ac000000         je 0x589fc0
// 00589f14  6a00                 push 0
// 00589f16  8d442430             lea eax, [esp + 0x30]
// 00589f1a  50                   push eax
// 00589f1b  8bce                 mov ecx, esi
// 00589f1d  e86edbffff           call 0x587a90
// 00589f22  84c0                 test al, al
// 00589f24  0f8496000000         je 0x589fc0
// 00589f2a  6a02                 push 2
// 00589f2c  8d4c2418             lea ecx, [esp + 0x18]
// 00589f30  e80bfdffff           call 0x589c40
// 00589f35  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00589f39  2b4c2420             sub ecx, dword ptr [esp + 0x20]
// 00589f3d  8b3590288000         mov esi, dword ptr [0x802890]
// 00589f43  c1f903               sar ecx, 3
// 00589f46  c644245002           mov byte ptr [esp + 0x50], 2
// 00589f4b  885c240b             mov byte ptr [esp + 0xb], bl
// 00589f4f  85c9                 test ecx, ecx
// 00589f51  7702                 ja 0x589f55
// 00589f53  ffd6                 call esi
// 00589f55  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00589f59  8d54240b             lea edx, [esp + 0xb]
// 00589f5d  52                   push edx
// 00589f5e  e8ad06e8ff           call 0x40a610
// 00589f63  8b442424             mov eax, dword ptr [esp + 0x24]
// 00589f67  2b442420             sub eax, dword ptr [esp + 0x20]
// 00589f6b  c1f803               sar eax, 3
// 00589f6e  3bc3                 cmp eax, ebx
// 00589f70  7702                 ja 0x589f74
// 00589f72  ffd6                 call esi
// 00589f74  8b742420             mov esi, dword ptr [esp + 0x20]
// 00589f78  83c608               add esi, 8
// 00589f7b  e8702efeff           call 0x56cdf0
// 00589f80  8d4c242c             lea ecx, [esp + 0x2c]
// 00589f84  51                   push ecx
// 00589f85  8906                 mov dword ptr [esi], eax
// 00589f87  8d4c2414             lea ecx, [esp + 0x14]
// 00589f8b  83c604               add esi, 4
// 00589f8e  e89dd2e8ff           call 0x417230
// 00589f93  3bc6                 cmp eax, esi
// 00589f95  7408                 je 0x589f9f
// 00589f97  8b16                 mov edx, dword ptr [esi]
// 00589f99  8b08                 mov ecx, dword ptr [eax]
// 00589f9b  8910                 mov dword ptr [eax], edx
// 00589f9d  890e                 mov dword ptr [esi], ecx
// 00589f9f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00589fa3  85c9                 test ecx, ecx
// 00589fa5  7407                 je 0x589fae
// 00589fa7  8b01                 mov eax, dword ptr [ecx]
// 00589fa9  8b10                 mov edx, dword ptr [eax]
// 00589fab  53                   push ebx
// 00589fac  ffd2                 call edx
// 00589fae  8b742458             mov esi, dword ptr [esp + 0x58]
// 00589fb2  8d442414             lea eax, [esp + 0x14]
// 00589fb6  50                   push eax
// 00589fb7  8bce                 mov ecx, esi
// 00589fb9  e8125ffdff           call 0x55fed0
// 00589fbe  eb47                 jmp 0x58a007
// 00589fc0  53                   push ebx
// 00589fc1  8d4c2418             lea ecx, [esp + 0x18]
// 00589fc5  e876fcffff           call 0x589c40
// 00589fca  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00589fce  2b4c2420             sub ecx, dword ptr [esp + 0x20]
// 00589fd2  c644245003           mov byte ptr [esp + 0x50], 3
// 00589fd7  c1f903               sar ecx, 3
// 00589fda  c644240b00           mov byte ptr [esp + 0xb], 0
// 00589fdf  85c9                 test ecx, ecx
// 00589fe1  7706                 ja 0x589fe9
// 00589fe3  ff1590288000         call dword ptr [0x802890]
// 00589fe9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00589fed  8d54240b             lea edx, [esp + 0xb]
// 00589ff1  52                   push edx
// 00589ff2  e81906e8ff           call 0x40a610
// 00589ff7  8b742458             mov esi, dword ptr [esp + 0x58]
// 00589ffb  8d442414             lea eax, [esp + 0x14]
// 00589fff  50                   push eax
// 0058a000  8bce                 mov ecx, esi
// 0058a002  e8c95efdff           call 0x55fed0
// 0058a007  8d4c2414             lea ecx, [esp + 0x14]
// 0058a00b  895c240c             mov dword ptr [esp + 0xc], ebx
// 0058a00f  885c2450             mov byte ptr [esp + 0x50], bl
// 0058a013  e81836eaff           call 0x42d630
// 0058a018  8d4c242c             lea ecx, [esp + 0x2c]
// 0058a01c  c644245000           mov byte ptr [esp + 0x50], 0
// 0058a021  ff1568248000         call dword ptr [0x802468]
// 0058a027  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0058a02b  8bc6                 mov eax, esi
// 0058a02d  5e                   pop esi
// 0058a02e  5b                   pop ebx
// 0058a02f  64890d00000000       mov dword ptr fs:[0], ecx
// 0058a036  83c44c               add esp, 0x4c
// 0058a039  c20400               ret 4

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
extern int stringTypeCounter;

struct S {
    char padding[0xc1];
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
        ++stringTypeCounter;
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
