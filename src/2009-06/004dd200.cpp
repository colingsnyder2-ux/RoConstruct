// from server: 85% by EspClaude
// from server: 100% by colin
// roc 2008-06 004a62d0  unit: RBX::VHint::?$FactoryProduct::Creator  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a62d0
//
// 004a62d0  64a100000000         mov eax, dword ptr fs:[0]
// 004a62d6  6aff                 push -1
// 004a62d8  68b9fe7c00           push 0x7cfeb9
// 004a62dd  50                   push eax
// 004a62de  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a62e2  64892500000000       mov dword ptr fs:[0], esp
// 004a62e9  83ec44               sub esp, 0x44
// 004a62ec  56                   push esi
// 004a62ed  8b742458             mov esi, dword ptr [esp + 0x58]
// 004a62f1  6a01                 push 1
// 004a62f3  6a20                 push 0x20
// 004a62f5  50                   push eax
// 004a62f6  8bce                 mov ecx, esi
// 004a62f8  e813efffff           call 0x4a5210
// 004a62fd  84c0                 test al, al
// 004a62ff  7534                 jne 0x4a6335
// 004a6301  68b43c8200           push 0x823cb4
// 004a6306  8d4c2408             lea ecx, [esp + 8]
// 004a630a  ff1558248000         call dword ptr [0x802458]
// 004a6310  8d4c2404             lea ecx, [esp + 4]
// 004a6314  51                   push ecx
// 004a6315  8d4c2424             lea ecx, [esp + 0x24]
// 004a6319  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004a6321  e82a3af6ff           call 0x409d50
// 004a6326  68c81b8d00           push 0x8d1bc8
// 004a632b  8d542424             lea edx, [esp + 0x24]
// 004a632f  52                   push edx
// 004a6330  e857b21f00           call 0x6a158c
// 004a6335  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004a6339  8bc6                 mov eax, esi
// 004a633b  5e                   pop esi
// 004a633c  64890d00000000       mov dword ptr fs:[0], ecx
// 004a6343  83c450               add esp, 0x50
// 004a6346  c3                   ret 

typedef void (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor stringConstructor;

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned int allocator_storage;
        union {
            T buffer[16];
            T* pointer;
        };
        unsigned int length;
        unsigned int capacity;
    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    __forceinline basic_string<T, Traits, Allocator>::basic_string(const T* text)
    {
        stringConstructor(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception {
        const char* message;
        int owns_message;
    public:
        exception();
        exception(const exception&);
        virtual ~exception();
        virtual const char* what() const;
    };

    class runtime_error : public exception {
        string message;
    public:
        runtime_error(const string&);
        runtime_error(const runtime_error&);
        virtual ~runtime_error();
        virtual const char* what() const;
    };
}

struct Stream {
    bool read(void*, int, bool);
};

Stream& readLong(Stream& stream, long& value)
{
    if (!stream.read(&value, 32, true)) {
        std::string message("BitStream >> size_t failed");
        throw std::runtime_error(message);
    }
    return stream;
}
