// from server: 100% by Yeetserama
// roc 2010-06 006a0b70  unit: UString_sink::?$stream_buffer  size: 175 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006a0b70
//
// 006a0b70  64a100000000         mov eax, dword ptr fs:[0]
// 006a0b76  6aff                 push -1
// 006a0b78  68593f9a00           push 0x9a3f59
// 006a0b7d  50                   push eax
// 006a0b7e  64892500000000       mov dword ptr fs:[0], esp
// 006a0b85  83ec4c               sub esp, 0x4c
// 006a0b88  56                   push esi
// 006a0b89  8bf1                 mov esi, ecx
// 006a0b8b  8b0e                 mov ecx, dword ptr [esi]
// 006a0b8d  8d442404             lea eax, [esp + 4]
// 006a0b91  50                   push eax
// 006a0b92  51                   push ecx
// 006a0b93  ff15ecbc9e00         call dword ptr [0x9ebcec]
// 006a0b99  85c0                 test eax, eax
// 006a0b9b  7407                 je 0x6a0ba4
// 006a0b9d  837c240400           cmp dword ptr [esp + 4], 0
// 006a0ba2  7515                 jne 0x6a0bb9
// 006a0ba4  83c8ff               or eax, 0xffffffff
// 006a0ba7  5e                   pop esi
// 006a0ba8  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006a0bac  64890d00000000       mov dword ptr fs:[0], ecx
// 006a0bb3  83c458               add esp, 0x58
// 006a0bb6  c20800               ret 8
// 006a0bb9  8b442464             mov eax, dword ptr [esp + 0x64]
// 006a0bbd  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 006a0bc1  8d542408             lea edx, [esp + 8]
// 006a0bc5  52                   push edx
// 006a0bc6  8b16                 mov edx, dword ptr [esi]
// 006a0bc8  50                   push eax
// 006a0bc9  51                   push ecx
// 006a0bca  52                   push edx
// 006a0bcb  ff15f0bc9e00         call dword ptr [0x9ebcf0]
// 006a0bd1  85c0                 test eax, eax
// 006a0bd3  7534                 jne 0x6a0c09
// 006a0bd5  68c809a400           push 0xa409c8
// 006a0bda  8d4c2410             lea ecx, [esp + 0x10]
// 006a0bde  ff1510a49e00         call dword ptr [0x9ea410]
// 006a0be4  8d44240c             lea eax, [esp + 0xc]
// 006a0be8  50                   push eax
// 006a0be9  8d4c242c             lea ecx, [esp + 0x2c]
// 006a0bed  c744245c00000000     mov dword ptr [esp + 0x5c], 0
// 006a0bf5  e8b687d6ff           call 0x4093b0
// 006a0bfa  687430b000           push 0xb03074
// 006a0bff  8d4c242c             lea ecx, [esp + 0x2c]
// 006a0c03  51                   push ecx
// 006a0c04  e8a97d1000           call 0x7a89b2
// 006a0c09  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 006a0c0d  8b442408             mov eax, dword ptr [esp + 8]
// 006a0c11  5e                   pop esi
// 006a0c12  64890d00000000       mov dword ptr fs:[0], ecx
// 006a0c19  83c458               add esp, 0x58
// 006a0c1c  c20800               ret 8
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
