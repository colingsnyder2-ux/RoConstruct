// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00642f10  unit: RBX::VWidget::?$NonFactoryProduct  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00642f10
//
// 00642f10  64a100000000         mov eax, dword ptr fs:[0]
// 00642f16  6aff                 push -1
// 00642f18  68b9fe7c00           push 0x7cfeb9
// 00642f1d  50                   push eax
// 00642f1e  64892500000000       mov dword ptr fs:[0], esp
// 00642f25  83ec44               sub esp, 0x44
// 00642f28  83b96401000000       cmp dword ptr [ecx + 0x164], 0
// 00642f2f  7533                 jne 0x642f64
// 00642f31  6858a88400           push 0x84a858
// 00642f36  8d4c2404             lea ecx, [esp + 4]
// 00642f3a  ff1558248000         call dword ptr [0x802458]
// 00642f40  8d0424               lea eax, [esp]
// 00642f43  50                   push eax
// 00642f44  8d4c2420             lea ecx, [esp + 0x20]
// 00642f48  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00642f50  e8fb6ddcff           call 0x409d50
// 00642f55  68c81b8d00           push 0x8d1bc8
// 00642f5a  8d4c2420             lea ecx, [esp + 0x20]
// 00642f5e  51                   push ecx
// 00642f5f  e828e60500           call 0x6a158c
// 00642f64  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00642f68  64890d00000000       mov dword ptr fs:[0], ecx
// 00642f6f  83c450               add esp, 0x50
// 00642f72  c3                   ret 

typedef void (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor constructString;

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class C, class Traits, class Alloc>
    class basic_string {
        Alloc alloc;
        union {
            C buffer[16];
            C* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const C*);
        basic_string(const basic_string&);
        ~basic_string();
    };

    template<class C, class Traits, class Alloc>
    inline basic_string<C, Traits, Alloc>::basic_string(const C* text)
    {
        constructString(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception {
        const char* message;
        int ownsMessage;

    public:
        exception();
        exception(const exception&);
        virtual ~exception();
        virtual const char* what() const;
    };

    class runtime_error : public exception {
        string text;

    public:
        runtime_error(const string&);
        runtime_error(const runtime_error&);
        virtual ~runtime_error();
        virtual const char* what() const;
    };
}

struct S {
    char padding[0xc0];
    int active;

    void f();
};

void S::f()
{
    if (!active)
        throw std::runtime_error(std::string("This Mouse is no longer active"));
}
