// from server: 100% by Yeetserama
// roc 2007-08 00448c10  unit: CRbxDocTemplate  size: 198 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00448c10
//
// 00448c10  6aff                 push -1
// 00448c12  68f1fb7300           push 0x73fbf1
// 00448c17  64a100000000         mov eax, dword ptr fs:[0]
// 00448c1d  50                   push eax
// 00448c1e  83ec70               sub esp, 0x70
// 00448c21  a188518b00           mov eax, dword ptr [0x8b5188]
// 00448c26  33c4                 xor eax, esp
// 00448c28  8944246c             mov dword ptr [esp + 0x6c], eax
// 00448c2c  a188518b00           mov eax, dword ptr [0x8b5188]
// 00448c31  33c4                 xor eax, esp
// 00448c33  50                   push eax
// 00448c34  8d442474             lea eax, [esp + 0x74]
// 00448c38  64a300000000         mov dword ptr fs:[0], eax
// 00448c3e  8b0d94be8b00         mov ecx, dword ptr [0x8bbe94]
// 00448c44  85c9                 test ecx, ecx
// 00448c46  7473                 je 0x448cbb
// 00448c48  8b01                 mov eax, dword ptr [ecx]
// 00448c4a  8b5004               mov edx, dword ptr [eax + 4]
// 00448c4d  ffd2                 call edx
// 00448c4f  50                   push eax
// 00448c50  8d4c2408             lea ecx, [esp + 8]
// 00448c54  ff1598e67700         call dword ptr [0x77e698]
// 00448c5a  8d442404             lea eax, [esp + 4]
// 00448c5e  50                   push eax
// 00448c5f  8d4c244c             lea ecx, [esp + 0x4c]
// 00448c63  c784248000000000000000 mov dword ptr [esp + 0x80], 0
// 00448c6e  e84da1fcff           call 0x412dc0
// 00448c73  8d4c2404             lea ecx, [esp + 4]
// 00448c77  c644247c02           mov byte ptr [esp + 0x7c], 2
// 00448c7c  ff15ace67700         call dword ptr [0x77e6ac]
// 00448c82  8b0d94be8b00         mov ecx, dword ptr [0x8bbe94]
// 00448c88  85c9                 test ecx, ecx
// 00448c8a  c70594be8b0000000000 mov dword ptr [0x8bbe94], 0
// 00448c94  7408                 je 0x448c9e
// 00448c96  8b11                 mov edx, dword ptr [ecx]
// 00448c98  8b02                 mov eax, dword ptr [edx]
// 00448c9a  6a01                 push 1
// 00448c9c  ffd0                 call eax
// 00448c9e  8d4c2448             lea ecx, [esp + 0x48]
// 00448ca2  51                   push ecx
// 00448ca3  8d4c2424             lea ecx, [esp + 0x24]
// 00448ca7  e804aafcff           call 0x4136b0
// 00448cac  68c0108400           push 0x8410c0
// 00448cb1  8d542424             lea edx, [esp + 0x24]
// 00448cb5  52                   push edx
// 00448cb6  e8e37e1e00           call 0x630b9e
// 00448cbb  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 00448cbf  64890d00000000       mov dword ptr fs:[0], ecx
// 00448cc6  59                   pop ecx
// 00448cc7  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 00448ccb  33cc                 xor ecx, esp
// 00448ccd  e84c7d1e00           call 0x630a1e
// 00448cd2  83c47c               add esp, 0x7c
// 00448cd5  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000002_0044ab30@ns_ROCX000002@@YAXXZ)

namespace ns_ROCX000002 {
// from server: 100% by king_originala
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

void fn_ROCX000002_0044ab30()
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
