// from server: 100% by Yeetserama
// roc 2010-06 00728960  unit: RBX::Lua::LuaArguments  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00728960
//
// 00728960  64a100000000         mov eax, dword ptr fs:[0]
// 00728966  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0072896a  6aff                 push -1
// 0072896c  68593f9a00           push 0x9a3f59
// 00728971  50                   push eax
// 00728972  8b442414             mov eax, dword ptr [esp + 0x14]
// 00728976  64892500000000       mov dword ptr fs:[0], esp
// 0072897d  83ec44               sub esp, 0x44
// 00728980  6a00                 push 0
// 00728982  50                   push eax
// 00728983  51                   push ecx
// 00728984  e8c789ffff           call 0x721350
// 00728989  83c40c               add esp, 0xc
// 0072898c  85c0                 test eax, eax
// 0072898e  7533                 jne 0x7289c3
// 00728990  6888d6a400           push 0xa4d688
// 00728995  8d4c2404             lea ecx, [esp + 4]
// 00728999  ff1510a49e00         call dword ptr [0x9ea410]
// 0072899f  8d1424               lea edx, [esp]
// 007289a2  52                   push edx
// 007289a3  8d4c2420             lea ecx, [esp + 0x20]
// 007289a7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 007289af  e8fc09ceff           call 0x4093b0
// 007289b4  687430b000           push 0xb03074
// 007289b9  8d442420             lea eax, [esp + 0x20]
// 007289bd  50                   push eax
// 007289be  e8efff0700           call 0x7a89b2
// 007289c3  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 007289c7  64890d00000000       mov dword ptr fs:[0], ecx
// 007289ce  83c450               add esp, 0x50
// 007289d1  c3                   ret 
// copied from an identical function in another client (function ?Function0061c7b0@ns_ROCX000007@@YAPBDPAXH@Z)

namespace ns_ROCX000007 {
// from server: 100% by king_originala
extern void (__thiscall *Function00802458)(void*, const char*);

namespace std
{
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string
    {
        Alloc alloc;
        union
        {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string(const T* text)
    {
        Function00802458(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception
    {
        char* message;
        bool owned;

    public:
        exception(const exception&);
        virtual ~exception();
        virtual const char* what() const;
    };

    class runtime_error : public exception
    {
        string message;

    public:
        runtime_error(const string&);
        runtime_error(const runtime_error&);
        virtual ~runtime_error();
        virtual const char* what() const;
    };
}

extern "C" const char* __cdecl Function00612010(
    void*, int, unsigned int*);

const char* __cdecl Function0061c7b0(void* state, int index)
{
    const char* result = Function00612010(state, index, 0);
    if (!result)
    {
        std::string message("String expected");
        throw std::runtime_error(message);
    }
    return result;
}
}
