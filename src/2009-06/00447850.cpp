// from server: 100% by EspClaude
// roc 2009-06 00447850  unit: CRobloxModule  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00447850
//
// 00447850  64a100000000         mov eax, dword ptr fs:[0]
// 00447856  6aff                 push -1
// 00447858  6811088500           push 0x850811
// 0044785d  50                   push eax
// 0044785e  64892500000000       mov dword ptr fs:[0], esp
// 00447865  8b0d3cb1a300         mov ecx, dword ptr [0xa3b13c]
// 0044786b  83ec6c               sub esp, 0x6c
// 0044786e  85c9                 test ecx, ecx
// 00447870  746e                 je 0x4478e0
// 00447872  8b01                 mov eax, dword ptr [ecx]
// 00447874  8b5004               mov edx, dword ptr [eax + 4]
// 00447877  ffd2                 call edx
// 00447879  50                   push eax
// 0044787a  8d4c2404             lea ecx, [esp + 4]
// 0044787e  ff15b4e48900         call dword ptr [0x89e4b4]
// 00447884  8d0424               lea eax, [esp]
// 00447887  50                   push eax
// 00447888  8d4c2420             lea ecx, [esp + 0x20]
// 0044788c  c744247800000000     mov dword ptr [esp + 0x78], 0
// 00447894  e8771bfcff           call 0x409410
// 00447899  8d0c24               lea ecx, [esp]
// 0044789c  c644247402           mov byte ptr [esp + 0x74], 2
// 004478a1  ff15c4e48900         call dword ptr [0x89e4c4]
// 004478a7  8b0d3cb1a300         mov ecx, dword ptr [0xa3b13c]
// 004478ad  c7053cb1a30000000000 mov dword ptr [0xa3b13c], 0
// 004478b7  85c9                 test ecx, ecx
// 004478b9  7408                 je 0x4478c3
// 004478bb  8b11                 mov edx, dword ptr [ecx]
// 004478bd  8b02                 mov eax, dword ptr [edx]
// 004478bf  6a01                 push 1
// 004478c1  ffd0                 call eax
// 004478c3  8d4c241c             lea ecx, [esp + 0x1c]
// 004478c7  51                   push ecx
// 004478c8  8d4c2448             lea ecx, [esp + 0x48]
// 004478cc  e8af1bfcff           call 0x409480
// 004478d1  6850a79700           push 0x97a750
// 004478d6  8d542448             lea edx, [esp + 0x48]
// 004478da  52                   push edx
// 004478db  e86a212d00           call 0x719a4a
// 004478e0  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 004478e4  64890d00000000       mov dword ptr fs:[0], ecx
// 004478eb  83c478               add esp, 0x78
// 004478ee  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000003_0044ab30@ns_ROCX000003@@YAXXZ)

namespace ns_ROCX000003 {
struct String
{
    char storage[28];
    String(const char *);
    ~String();
};

struct Error
{
    char storage[40];
    Error(const String &);
    Error(const Error &);
    ~Error();
};

struct Source
{
    virtual void destroy(unsigned int) = 0;
    virtual const char *message() = 0;
};

extern Source *globalSource;

extern void (__thiscall *stringConstruct)(String *, const char *);
extern void (__thiscall *stringDestroy)(String *);

inline String::String(const char *text)
{
    stringConstruct(this, text);
}

inline String::~String()
{
    stringDestroy(this);
}

void fn_ROCX000003_0044ab30()
{
    if (globalSource)
    {
        Error error(String(globalSource->message()));
        Source *source = globalSource;
        globalSource = 0;
        if (source)
            source->destroy(1);
        throw error;
    }
}
}
