// from server: 100% by Yeetserama
// roc 2011-06 006e1c40  unit: UString_sink::?$stream_buffer  size: 175 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006e1c40
//
// 006e1c40  64a100000000         mov eax, dword ptr fs:[0]
// 006e1c46  6aff                 push -1
// 006e1c48  6899bc9d00           push 0x9dbc99
// 006e1c4d  50                   push eax
// 006e1c4e  64892500000000       mov dword ptr fs:[0], esp
// 006e1c55  83ec4c               sub esp, 0x4c
// 006e1c58  56                   push esi
// 006e1c59  8bf1                 mov esi, ecx
// 006e1c5b  8b0e                 mov ecx, dword ptr [esi]
// 006e1c5d  8d442404             lea eax, [esp + 4]
// 006e1c61  50                   push eax
// 006e1c62  51                   push ecx
// 006e1c63  ff15d41ca400         call dword ptr [0xa41cd4]
// 006e1c69  85c0                 test eax, eax
// 006e1c6b  7407                 je 0x6e1c74
// 006e1c6d  837c240400           cmp dword ptr [esp + 4], 0
// 006e1c72  7515                 jne 0x6e1c89
// 006e1c74  83c8ff               or eax, 0xffffffff
// 006e1c77  5e                   pop esi
// 006e1c78  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006e1c7c  64890d00000000       mov dword ptr fs:[0], ecx
// 006e1c83  83c458               add esp, 0x58
// 006e1c86  c20800               ret 8
// 006e1c89  8b442464             mov eax, dword ptr [esp + 0x64]
// 006e1c8d  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 006e1c91  8d542408             lea edx, [esp + 8]
// 006e1c95  52                   push edx
// 006e1c96  8b16                 mov edx, dword ptr [esi]
// 006e1c98  50                   push eax
// 006e1c99  51                   push ecx
// 006e1c9a  52                   push edx
// 006e1c9b  ff15d01ca400         call dword ptr [0xa41cd0]
// 006e1ca1  85c0                 test eax, eax
// 006e1ca3  7534                 jne 0x6e1cd9
// 006e1ca5  681883aa00           push 0xaa8318
// 006e1caa  8d4c2410             lea ecx, [esp + 0x10]
// 006e1cae  ff15c404a400         call dword ptr [0xa404c4]
// 006e1cb4  8d44240c             lea eax, [esp + 0xc]
// 006e1cb8  50                   push eax
// 006e1cb9  8d4c242c             lea ecx, [esp + 0x2c]
// 006e1cbd  c744245c00000000     mov dword ptr [esp + 0x5c], 0
// 006e1cc5  e8868cd2ff           call 0x40a950
// 006e1cca  682091b800           push 0xb89120
// 006e1ccf  8d4c242c             lea ecx, [esp + 0x2c]
// 006e1cd3  51                   push ecx
// 006e1cd4  e8d3931200           call 0x80b0ac
// 006e1cd9  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 006e1cdd  8b442408             mov eax, dword ptr [esp + 8]
// 006e1ce1  5e                   pop esi
// 006e1ce2  64890d00000000       mov dword ptr fs:[0], ecx
// 006e1ce9  83c458               add esp, 0x58
// 006e1cec  c20800               ret 8
// copied from an identical function in another client (function ?read@StreamBuffer@ns_ROCX000013@@QAEHPAXK@Z)

namespace ns_ROCX000013 {
// from server: 100% by colin
typedef unsigned long DWORD;

extern "C" {
    extern int (__stdcall *WinHttpQueryDataAvailable)(void *, DWORD *);
    extern int (__stdcall *WinHttpReadData)(void *, void *, DWORD, DWORD *);
}

extern void (__thiscall *string_construct)(void *, const char *);

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string(const T *);
        basic_string(const basic_string &);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string(const T *text)
    {
        string_construct(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception {
        void *vtable;
        const char *message;
    public:
        exception(const exception &);
        virtual ~exception();
        virtual const char *what() const;
    };

    class runtime_error : public exception {
        string message;
    public:
        runtime_error(const string &);
        runtime_error(const runtime_error &);
        virtual ~runtime_error();
        virtual const char *what() const;
    };
}

struct StreamBuffer {
    void *handle;
    int read(void *buffer, DWORD length);
};

int StreamBuffer::read(void *buffer, DWORD length)
{
    DWORD available;
    DWORD received;

    if (!WinHttpQueryDataAvailable(handle, &available))
        goto fail;
    if (available == 0)
        goto fail;

    if (!WinHttpReadData(handle, buffer, length, &received)) {
        std::string message("InternetReadFile failed");
        throw std::runtime_error(message);
    }
    return received;

fail:
    return -1;
}
}
