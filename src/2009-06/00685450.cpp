// from server: 100% by EspClaude
// roc 2009-06 00685450  unit: boost::iostreams::Uinput::V?$chain::?$chain_client  size: 175 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00685450
//
// 00685450  64a100000000         mov eax, dword ptr fs:[0]
// 00685456  6aff                 push -1
// 00685458  6849b88500           push 0x85b849
// 0068545d  50                   push eax
// 0068545e  64892500000000       mov dword ptr fs:[0], esp
// 00685465  83ec4c               sub esp, 0x4c
// 00685468  56                   push esi
// 00685469  8bf1                 mov esi, ecx
// 0068546b  8b0e                 mov ecx, dword ptr [esi]
// 0068546d  8d442404             lea eax, [esp + 4]
// 00685471  50                   push eax
// 00685472  51                   push ecx
// 00685473  ff1558ef8900         call dword ptr [0x89ef58]
// 00685479  85c0                 test eax, eax
// 0068547b  7407                 je 0x685484
// 0068547d  837c240400           cmp dword ptr [esp + 4], 0
// 00685482  7515                 jne 0x685499
// 00685484  83c8ff               or eax, 0xffffffff
// 00685487  5e                   pop esi
// 00685488  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0068548c  64890d00000000       mov dword ptr fs:[0], ecx
// 00685493  83c458               add esp, 0x58
// 00685496  c20800               ret 8
// 00685499  8b442464             mov eax, dword ptr [esp + 0x64]
// 0068549d  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 006854a1  8d542408             lea edx, [esp + 8]
// 006854a5  52                   push edx
// 006854a6  8b16                 mov edx, dword ptr [esi]
// 006854a8  50                   push eax
// 006854a9  51                   push ecx
// 006854aa  52                   push edx
// 006854ab  ff1560ef8900         call dword ptr [0x89ef60]
// 006854b1  85c0                 test eax, eax
// 006854b3  7534                 jne 0x6854e9
// 006854b5  68105f8e00           push 0x8e5f10
// 006854ba  8d4c2410             lea ecx, [esp + 0x10]
// 006854be  ff15b4e48900         call dword ptr [0x89e4b4]
// 006854c4  8d44240c             lea eax, [esp + 0xc]
// 006854c8  50                   push eax
// 006854c9  8d4c242c             lea ecx, [esp + 0x2c]
// 006854cd  c744245c00000000     mov dword ptr [esp + 0x5c], 0
// 006854d5  e8363fd8ff           call 0x409410
// 006854da  6850a79700           push 0x97a750
// 006854df  8d4c242c             lea ecx, [esp + 0x2c]
// 006854e3  51                   push ecx
// 006854e4  e861450900           call 0x719a4a
// 006854e9  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 006854ed  8b442408             mov eax, dword ptr [esp + 8]
// 006854f1  5e                   pop esi
// 006854f2  64890d00000000       mov dword ptr fs:[0], ecx
// 006854f9  83c458               add esp, 0x58
// 006854fc  c20800               ret 8
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
