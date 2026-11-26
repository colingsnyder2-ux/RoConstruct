// from server: 100% by Xemicl
// roc 2012-06 0083a0d0  unit: seg_00830000  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0083a0d0
//
// 0083a0d0  64a100000000         mov eax, dword ptr fs:[0]
// 0083a0d6  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083a0da  6aff                 push -1
// 0083a0dc  6889c9ac00           push 0xacc989
// 0083a0e1  50                   push eax
// 0083a0e2  8b442414             mov eax, dword ptr [esp + 0x14]
// 0083a0e6  64892500000000       mov dword ptr fs:[0], esp
// 0083a0ed  83ec44               sub esp, 0x44
// 0083a0f0  6a00                 push 0
// 0083a0f2  50                   push eax
// 0083a0f3  51                   push ecx
// 0083a0f4  e8f77dffff           call 0x831ef0
// 0083a0f9  83c40c               add esp, 0xc
// 0083a0fc  85c0                 test eax, eax
// 0083a0fe  7533                 jne 0x83a133
// 0083a100  680818bd00           push 0xbd1808
// 0083a105  8d4c2404             lea ecx, [esp + 4]
// 0083a109  ff154826b200         call dword ptr [0xb22648]
// 0083a10f  8d1424               lea edx, [esp]
// 0083a112  52                   push edx
// 0083a113  8d4c2420             lea ecx, [esp + 0x20]
// 0083a117  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0083a11f  e87c1fbdff           call 0x40c0a0
// 0083a124  686c80cd00           push 0xcd806c
// 0083a129  8d442420             lea eax, [esp + 0x20]
// 0083a12d  50                   push eax
// 0083a12e  e811901400           call 0x983144
// 0083a133  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0083a137  64890d00000000       mov dword ptr fs:[0], ecx
// 0083a13e  83c450               add esp, 0x50
// 0083a141  c3                   ret 
// copied from an identical function in another client (function ?Function0061c7b0@ns_ROCX000004@@YAPBDPAXH@Z)

namespace ns_ROCX000004 {
// from server: 100% by king_originala
// roc 2008-06 0061c7b0  unit: RBX::Lua::LuaArguments  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0061c7b0
//
// 0061c7b0  64a100000000         mov eax, dword ptr fs:[0]
// 0061c7b6  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0061c7ba  6aff                 push -1
// 0061c7bc  68b9fe7c00           push 0x7cfeb9
// 0061c7c1  50                   push eax
// 0061c7c2  8b442414             mov eax, dword ptr [esp + 0x14]
// 0061c7c6  64892500000000       mov dword ptr fs:[0], esp
// 0061c7cd  83ec44               sub esp, 0x44
// 0061c7d0  6a00                 push 0
// 0061c7d2  50                   push eax
// 0061c7d3  51                   push ecx
// 0061c7d4  e83758ffff           call 0x612010
// 0061c7d9  83c40c               add esp, 0xc
// 0061c7dc  85c0                 test eax, eax
// 0061c7de  7533                 jne 0x61c813
// 0061c7e0  6870448400           push 0x844470
// 0061c7e5  8d4c2404             lea ecx, [esp + 4]
// 0061c7e9  ff1558248000         call dword ptr [0x802458]
// 0061c7ef  8d1424               lea edx, [esp]
// 0061c7f2  52                   push edx
// 0061c7f3  8d4c2420             lea ecx, [esp + 0x20]
// 0061c7f7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0061c7ff  e84cd5deff           call 0x409d50
// 0061c804  68c81b8d00           push 0x8d1bc8
// 0061c809  8d442420             lea eax, [esp + 0x20]
// 0061c80d  50                   push eax
// 0061c80e  e8794d0800           call 0x6a158c
// 0061c813  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0061c817  64890d00000000       mov dword ptr fs:[0], ecx
// 0061c81e  83c450               add esp, 0x50
// 0061c821  c3                   ret 

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
