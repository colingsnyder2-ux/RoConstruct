// from server: 100% by Xemicl
// roc 2012-06 0046f3d0  unit: CRobloxModule  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046f3d0
//
// 0046f3d0  64a100000000         mov eax, dword ptr fs:[0]
// 0046f3d6  6aff                 push -1
// 0046f3d8  688100aa00           push 0xaa0081
// 0046f3dd  50                   push eax
// 0046f3de  64892500000000       mov dword ptr fs:[0], esp
// 0046f3e5  8b0d58a2e100         mov ecx, dword ptr [0xe1a258]
// 0046f3eb  83ec6c               sub esp, 0x6c
// 0046f3ee  85c9                 test ecx, ecx
// 0046f3f0  746e                 je 0x46f460
// 0046f3f2  8b01                 mov eax, dword ptr [ecx]
// 0046f3f4  8b5004               mov edx, dword ptr [eax + 4]
// 0046f3f7  ffd2                 call edx
// 0046f3f9  50                   push eax
// 0046f3fa  8d4c2404             lea ecx, [esp + 4]
// 0046f3fe  ff154826b200         call dword ptr [0xb22648]
// 0046f404  8d0424               lea eax, [esp]
// 0046f407  50                   push eax
// 0046f408  8d4c2420             lea ecx, [esp + 0x20]
// 0046f40c  c744247800000000     mov dword ptr [esp + 0x78], 0
// 0046f414  e887ccf9ff           call 0x40c0a0
// 0046f419  8d0c24               lea ecx, [esp]
// 0046f41c  c644247402           mov byte ptr [esp + 0x74], 2
// 0046f421  ff153c26b200         call dword ptr [0xb2263c]
// 0046f427  8b0d58a2e100         mov ecx, dword ptr [0xe1a258]
// 0046f42d  c70558a2e10000000000 mov dword ptr [0xe1a258], 0
// 0046f437  85c9                 test ecx, ecx
// 0046f439  7408                 je 0x46f443
// 0046f43b  8b11                 mov edx, dword ptr [ecx]
// 0046f43d  8b02                 mov eax, dword ptr [edx]
// 0046f43f  6a01                 push 1
// 0046f441  ffd0                 call eax
// 0046f443  8d4c241c             lea ecx, [esp + 0x1c]
// 0046f447  51                   push ecx
// 0046f448  8d4c2448             lea ecx, [esp + 0x48]
// 0046f44c  e8bfccf9ff           call 0x40c110
// 0046f451  686c80cd00           push 0xcd806c
// 0046f456  8d542448             lea edx, [esp + 0x48]
// 0046f45a  52                   push edx
// 0046f45b  e8e43c5100           call 0x983144
// 0046f460  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0046f464  64890d00000000       mov dword ptr fs:[0], ecx
// 0046f46b  83c478               add esp, 0x78
// 0046f46e  c3                   ret 
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