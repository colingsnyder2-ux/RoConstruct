// from server: 100% by Xemicl
// roc 2012-06 00859e50  unit: UString_sink::?$stream_buffer  size: 175 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00859e50
//
// 00859e50  64a100000000         mov eax, dword ptr fs:[0]
// 00859e56  6aff                 push -1
// 00859e58  6889c9ac00           push 0xacc989
// 00859e5d  50                   push eax
// 00859e5e  64892500000000       mov dword ptr fs:[0], esp
// 00859e65  83ec4c               sub esp, 0x4c
// 00859e68  56                   push esi
// 00859e69  8bf1                 mov esi, ecx
// 00859e6b  8b0e                 mov ecx, dword ptr [esi]
// 00859e6d  8d442404             lea eax, [esp + 4]
// 00859e71  50                   push eax
// 00859e72  51                   push ecx
// 00859e73  ff15783db200         call dword ptr [0xb23d78]
// 00859e79  85c0                 test eax, eax
// 00859e7b  7407                 je 0x859e84
// 00859e7d  837c240400           cmp dword ptr [esp + 4], 0
// 00859e82  7515                 jne 0x859e99
// 00859e84  83c8ff               or eax, 0xffffffff
// 00859e87  5e                   pop esi
// 00859e88  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00859e8c  64890d00000000       mov dword ptr fs:[0], ecx
// 00859e93  83c458               add esp, 0x58
// 00859e96  c20800               ret 8
// 00859e99  8b442464             mov eax, dword ptr [esp + 0x64]
// 00859e9d  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00859ea1  8d542408             lea edx, [esp + 8]
// 00859ea5  52                   push edx
// 00859ea6  8b16                 mov edx, dword ptr [esi]
// 00859ea8  50                   push eax
// 00859ea9  51                   push ecx
// 00859eaa  52                   push edx
// 00859eab  ff15743db200         call dword ptr [0xb23d74]
// 00859eb1  85c0                 test eax, eax
// 00859eb3  7534                 jne 0x859ee9
// 00859eb5  682445bd00           push 0xbd4524
// 00859eba  8d4c2410             lea ecx, [esp + 0x10]
// 00859ebe  ff154826b200         call dword ptr [0xb22648]
// 00859ec4  8d44240c             lea eax, [esp + 0xc]
// 00859ec8  50                   push eax
// 00859ec9  8d4c242c             lea ecx, [esp + 0x2c]
// 00859ecd  c744245c00000000     mov dword ptr [esp + 0x5c], 0
// 00859ed5  e8c621bbff           call 0x40c0a0
// 00859eda  686c80cd00           push 0xcd806c
// 00859edf  8d4c242c             lea ecx, [esp + 0x2c]
// 00859ee3  51                   push ecx
// 00859ee4  e85b921200           call 0x983144
// 00859ee9  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 00859eed  8b442408             mov eax, dword ptr [esp + 8]
// 00859ef1  5e                   pop esi
// 00859ef2  64890d00000000       mov dword ptr fs:[0], ecx
// 00859ef9  83c458               add esp, 0x58
// 00859efc  c20800               ret 8
// copied from an identical function in another client (function ?read@StreamBuffer@ns_ROCX000008@@QAEHPAXK@Z)

namespace ns_ROCX000008 {
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