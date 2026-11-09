// from server: 100% by Yeetserama
// roc 2007-08 004a5620  unit: RBX::Network::Server::ClientProxy  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a5620
//
// 004a5620  6aff                 push -1
// 004a5622  68d9987400           push 0x7498d9
// 004a5627  64a100000000         mov eax, dword ptr fs:[0]
// 004a562d  50                   push eax
// 004a562e  56                   push esi
// 004a562f  a188518b00           mov eax, dword ptr [0x8b5188]
// 004a5634  33c4                 xor eax, esp
// 004a5636  50                   push eax
// 004a5637  8d442408             lea eax, [esp + 8]
// 004a563b  64a300000000         mov dword ptr fs:[0], eax
// 004a5641  8bf1                 mov esi, ecx
// 004a5643  8d442418             lea eax, [esp + 0x18]
// 004a5647  50                   push eax
// 004a5648  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004a5650  ff159ce67700         call dword ptr [0x77e69c]
// 004a5656  8a4c2434             mov cl, byte ptr [esp + 0x34]
// 004a565a  884e1c               mov byte ptr [esi + 0x1c], cl
// 004a565d  8d4c2418             lea ecx, [esp + 0x18]
// 004a5661  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004a5669  ff15ace67700         call dword ptr [0x77e6ac]
// 004a566f  8bc6                 mov eax, esi
// 004a5671  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004a5675  64890d00000000       mov dword ptr fs:[0], ecx
// 004a567c  59                   pop ecx
// 004a567d  5e                   pop esi
// 004a567e  83c40c               add esp, 0xc
// 004a5681  c22000               ret 0x20
// copied from an identical function in another client (function ??0S@ns_ROCX000009@@QAE@V?$basic_string@DU?$char_traits@D@std@ns_ROCX000009@@V?$allocator@D@23@@std@1@_N@Z)

namespace ns_ROCX000009 {
// from server: 100% by king_originala
typedef void (__thiscall *StringCopy)(void*, const void*);
typedef void (__thiscall *StringDestroy)(void*);

extern StringCopy string_copy;
extern StringDestroy string_destroy;

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        basic_string(const basic_string&);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string(const basic_string& other)
    {
        string_copy(this, &other);
    }

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::~basic_string()
    {
        string_destroy(this);
    }
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

struct S {
    String text;
    bool flag;

    S(String value, bool enabled);
};

S::S(String value, bool enabled)
    : text(value), flag(enabled)
{
}
}
