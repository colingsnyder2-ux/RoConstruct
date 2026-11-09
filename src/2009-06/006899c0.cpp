// from server: 100% by EspClaude
// roc 2009-06 006899c0  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006899c0
//
// 006899c0  64a100000000         mov eax, dword ptr fs:[0]
// 006899c6  6aff                 push -1
// 006899c8  6849b88500           push 0x85b849
// 006899cd  50                   push eax
// 006899ce  64892500000000       mov dword ptr fs:[0], esp
// 006899d5  83ec4c               sub esp, 0x4c
// 006899d8  56                   push esi
// 006899d9  6a00                 push 0
// 006899db  6a00                 push 0
// 006899dd  8bf1                 mov esi, ecx
// 006899df  8b0e                 mov ecx, dword ptr [esi]
// 006899e1  8d44240c             lea eax, [esp + 0xc]
// 006899e5  50                   push eax
// 006899e6  51                   push ecx
// 006899e7  ff158cef8900         call dword ptr [0x89ef8c]
// 006899ed  85c0                 test eax, eax
// 006899ef  7407                 je 0x6899f8
// 006899f1  837c240400           cmp dword ptr [esp + 4], 0
// 006899f6  7515                 jne 0x689a0d
// 006899f8  83c8ff               or eax, 0xffffffff
// 006899fb  5e                   pop esi
// 006899fc  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00689a00  64890d00000000       mov dword ptr fs:[0], ecx
// 00689a07  83c458               add esp, 0x58
// 00689a0a  c20800               ret 8
// 00689a0d  8b442464             mov eax, dword ptr [esp + 0x64]
// 00689a11  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00689a15  8d542408             lea edx, [esp + 8]
// 00689a19  52                   push edx
// 00689a1a  8b16                 mov edx, dword ptr [esi]
// 00689a1c  50                   push eax
// 00689a1d  51                   push ecx
// 00689a1e  52                   push edx
// 00689a1f  ff1588ef8900         call dword ptr [0x89ef88]
// 00689a25  85c0                 test eax, eax
// 00689a27  7534                 jne 0x689a5d
// 00689a29  68105f8e00           push 0x8e5f10
// 00689a2e  8d4c2410             lea ecx, [esp + 0x10]
// 00689a32  ff15b4e48900         call dword ptr [0x89e4b4]
// 00689a38  8d44240c             lea eax, [esp + 0xc]
// 00689a3c  50                   push eax
// 00689a3d  8d4c242c             lea ecx, [esp + 0x2c]
// 00689a41  c744245c00000000     mov dword ptr [esp + 0x5c], 0
// 00689a49  e8c2f9d7ff           call 0x409410
// 00689a4e  6850a79700           push 0x97a750
// 00689a53  8d4c242c             lea ecx, [esp + 0x2c]
// 00689a57  51                   push ecx
// 00689a58  e8edff0800           call 0x719a4a
// 00689a5d  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 00689a61  8b442408             mov eax, dword ptr [esp + 8]
// 00689a65  5e                   pop esi
// 00689a66  64890d00000000       mov dword ptr fs:[0], ecx
// 00689a6d  83c458               add esp, 0x58
// 00689a70  c20800               ret 8
// copied from an identical function in another client (function ?read@Input@ns_ROCX000018@@QAEJPADJ@Z)

namespace ns_ROCX000018 {
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        basic_string(const T*);
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern void* (__thiscall *StringConstruct)(void*, const char*);

template<>
__forceinline std::basic_string<char, std::char_traits<char>,
    std::allocator<char> >::basic_string(const char* text)
{
    StringConstruct(this, text);
}

struct ReadError {
    char storage[40];
    ReadError(const std::string&);
    ReadError(const ReadError&);
    ~ReadError();
};

extern "C" {
    extern int (__stdcall *InternetQueryDataAvailable)(
        void*, unsigned long*, unsigned long, unsigned long);
    extern int (__stdcall *InternetReadFile)(
        void*, void*, unsigned long, unsigned long*);
}

struct Input {
    void* handle;
    long read(char*, long);
};

long Input::read(char* buffer, long count)
{
    unsigned long available;
    unsigned long received;

    if (!InternetQueryDataAvailable(handle, &available, 0, 0))
        goto fail;

    if (available == 0)
        goto fail;

    if (!InternetReadFile(handle, buffer, count, &received)) {
        std::string message("InternetReadFile failed");
        throw ReadError(message);
    }

    return received;

fail:
    return -1;
}
}
