// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005becc0  unit: RBX::Soundscape::SoundService  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005becc0
//
// 005becc0  51                   push ecx
// 005becc1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005becc5  56                   push esi
// 005becc6  c744240400000000     mov dword ptr [esp + 4], 0
// 005becce  e8dd74ffff           call 0x5b61b0
// 005becd3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005becd7  50                   push eax
// 005becd8  8bce                 mov ecx, esi
// 005becda  ff155c248000         call dword ptr [0x80245c]
// 005bece0  8bc6                 mov eax, esi
// 005bece2  5e                   pop esi
// 005bece3  59                   pop ecx
// 005bece4  c3                   ret 

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
    public:
        basic_string(const basic_string&);
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern std::string* (__thiscall *copy_string)(
    std::string*, const std::string&);

namespace std {
    template<class T, class Traits, class Allocator>
    __forceinline basic_string<T, Traits, Allocator>::basic_string(
        const basic_string& source)
    {
        copy_string(this, source);
    }
}

struct S {
    const std::string& name() const;
};

std::string f(const S& source)
{
    return source.name();
}
