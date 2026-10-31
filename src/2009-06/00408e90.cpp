// from server: 91% by EspClaude
// from server: 100% by colin
// roc 2008-06 004097c0  unit: RBX::VSelection::?$FactoryProduct::Creator  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004097c0
//
// 004097c0  55                   push ebp
// 004097c1  8d6c24c0             lea ebp, [esp - 0x40]
// 004097c5  83ec40               sub esp, 0x40
// 004097c8  6aff                 push -1
// 004097ca  68facf7b00           push 0x7bcffa
// 004097cf  64a100000000         mov eax, dword ptr fs:[0]
// 004097d5  50                   push eax
// 004097d6  64892500000000       mov dword ptr fs:[0], esp
// 004097dd  81ecd0000000         sub esp, 0xd0
// 004097e3  53                   push ebx
// 004097e4  56                   push esi
// 004097e5  57                   push edi
// 004097e6  33ff                 xor edi, edi
// 004097e8  f60538c3960001       test byte ptr [0x96c338], 1
// 004097ef  8965f0               mov dword ptr [ebp - 0x10], esp
// 004097f2  894d3c               mov dword ptr [ebp + 0x3c], ecx
// 004097f5  897d38               mov dword ptr [ebp + 0x38], edi
// 004097f8  897dfc               mov dword ptr [ebp - 4], edi
// 004097fb  7542                 jne 0x40983f
// 004097fd  830d38c3960001       or dword ptr [0x96c338], 1
// 00409804  6890000000           push 0x90
// 00409809  8d8528ffffff         lea eax, [ebp - 0xd8]
// 0040980f  57                   push edi
// 00409810  50                   push eax
// 00409811  e8ee7e2900           call 0x6a1704
// 00409816  83c40c               add esp, 0xc
// 00409819  8d8d24ffffff         lea ecx, [ebp - 0xdc]
// 0040981f  51                   push ecx
// 00409820  c78524ffffff94000000 mov dword ptr [ebp - 0xdc], 0x94
// 0040982a  ff159c218000         call dword ptr [0x80219c]
// 00409830  83bd28ffffff06       cmp dword ptr [ebp - 0xd8], 6
// 00409837  0f93c0               setae al
// 0040983a  a234c39600           mov byte ptr [0x96c334], al
// 0040983f  803d34c3960000       cmp byte ptr [0x96c334], 0
// 00409846  7517                 jne 0x40985f
// 00409848  8b7548               mov esi, dword ptr [ebp + 0x48]
// 0040984b  6816b78000           push 0x80b716
// 00409850  8bce                 mov ecx, esi
// 00409852  ff1558248000         call dword ptr [0x802458]
// 00409858  8bc6                 mov eax, esi
// 0040985a  e9d8000000           jmp 0x409937
// 0040985f  8d4d00               lea ecx, [ebp]
// 00409862  ff1560248000         call dword ptr [0x802460]
// 00409868  8b554c               mov edx, dword ptr [ebp + 0x4c]
// 0040986b  52                   push edx
// 0040986c  8d4d1c               lea ecx, [ebp + 0x1c]
// 0040986f  c645fc01             mov byte ptr [ebp - 4], 1
// 00409873  ff1558248000         call dword ptr [0x802458]
// 00409879  8b7550               mov esi, dword ptr [ebp + 0x50]
// 0040987c  b302                 mov bl, 2
// 0040987e  885dfc               mov byte ptr [ebp - 4], bl
// 00409881  3bf7                 cmp esi, edi
// 00409883  7418                 je 0x40989d
// 00409885  680cb78000           push 0x80b70c
// 0040988a  8d4d1c               lea ecx, [ebp + 0x1c]
// 0040988d  ff1548248000         call dword ptr [0x802448]
// 00409893  56                   push esi
// 00409894  8d4d1c               lea ecx, [ebp + 0x1c]
// 00409897  ff1548248000         call dword ptr [0x802448]
// 0040989d  8d4d1c               lea ecx, [ebp + 0x1c]
// 004098a0  ff1564248000         call dword ptr [0x802464]
// 004098a6  50                   push eax
// 004098a7  8d4db8               lea ecx, [ebp - 0x48]
// 004098aa  e8a1feffff           call 0x409750
// 004098af  68ecb68000           push 0x80b6ec
// 004098b4  8d4dd4               lea ecx, [ebp - 0x2c]
// 004098b7  c645fc03             mov byte ptr [ebp - 4], 3
// 004098bb  ff154c248000         call dword ptr [0x80244c]
// 004098c1  8b453c               mov eax, dword ptr [ebp + 0x3c]
// 004098c4  50                   push eax
// 004098c5  8d4dd4               lea ecx, [ebp - 0x2c]
// 004098c8  ff1550248000         call dword ptr [0x802450]
// 004098ce  68e8b68000           push 0x80b6e8
// 004098d3  8d4dd4               lea ecx, [ebp - 0x2c]
// 004098d6  ff1548248000         call dword ptr [0x802448]
// 004098dc  8d4d00               lea ecx, [ebp]
// 004098df  51                   push ecx
// 004098e0  8d4db8               lea ecx, [ebp - 0x48]
// 004098e3  e8f8011600           call 0x569ae0
// 004098e8  8d4db8               lea ecx, [ebp - 0x48]
// 004098eb  885dfc               mov byte ptr [ebp - 4], bl
// 004098ee  e82d5d1d00           call 0x5df620
// 004098f3  8d4d1c               lea ecx, [ebp + 0x1c]
// 004098f6  c645fc01             mov byte ptr [ebp - 4], 1
// 004098fa  ff1568248000         call dword ptr [0x802468]
// 00409900  8b7548               mov esi, dword ptr [ebp + 0x48]
// 00409903  8d5500               lea edx, [ebp]
// 00409906  52                   push edx
// 00409907  8bce                 mov ecx, esi
// 00409909  ff155c248000         call dword ptr [0x80245c]
// 0040990f  8d4d00               lea ecx, [ebp]
// 00409912  c645fc00             mov byte ptr [ebp - 4], 0
// 00409916  ff1568248000         call dword ptr [0x802468]
// 0040991c  8bc6                 mov eax, esi
// 0040991e  eb17                 jmp 0x409937

// from server: 0% by king_originala
#include <intrin.h>
// from server: 90% by colin
// from server: 86% by king_originala
// roc 2008-06 004097c0  unit: RBX::VSelection::?$FactoryProduct::Creator  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004097c0
//
// 004097c0  55                   push ebp
// 004097c1  8d6c24c0             lea ebp, [esp - 0x40]
// 004097c5  83ec40               sub esp, 0x40
// 004097c8  6aff                 push -1
// 004097ca  68facf7b00           push 0x7bcffa
// 004097cf  64a100000000         mov eax, dword ptr fs:[0]
// 004097d5  50                   push eax
// 004097d6  64892500000000       mov dword ptr fs:[0], esp
// 004097dd  81ecd0000000         sub esp, 0xd0
// 004097e3  53                   push ebx
// 004097e4  56                   push esi
// 004097e5  57                   push edi
// 004097e6  33ff                 xor edi, edi
// 004097e8  f60538c3960001       test byte ptr [0x96c338], 1
// 004097ef  8965f0               mov dword ptr [ebp - 0x10], esp
// 004097f2  894d3c               mov dword ptr [ebp + 0x3c], ecx
// 004097f5  897d38               mov dword ptr [ebp + 0x38], edi
// 004097f8  897dfc               mov dword ptr [ebp - 4], edi
// 004097fb  7542                 jne 0x40983f
// 004097fd  830d38c3960001       or dword ptr [0x96c338], 1
// 00409804  6890000000           push 0x90
// 00409809  8d8528ffffff         lea eax, [ebp - 0xd8]
// 0040980f  57                   push edi
// 00409810  50                   push eax
// 00409811  e8ee7e2900           call 0x6a1704
// 00409816  83c40c               add esp, 0xc
// 00409819  8d8d24ffffff         lea ecx, [ebp - 0xdc]
// 0040981f  51                   push ecx
// 00409820  c78524ffffff94000000 mov dword ptr [ebp - 0xdc], 0x94
// 0040982a  ff159c218000         call dword ptr [0x80219c]
// 00409830  83bd28ffffff06       cmp dword ptr [ebp - 0xd8], 6
// 00409837  0f93c0               setae al
// 0040983a  a234c39600           mov byte ptr [0x96c334], al
// 0040983f  803d34c3960000       cmp byte ptr [0x96c334], 0
// 00409846  7517                 jne 0x40985f
// 00409848  8b7548               mov esi, dword ptr [ebp + 0x48]
// 0040984b  6816b78000           push 0x80b716
// 00409850  8bce                 mov ecx, esi
// 00409852  ff1558248000         call dword ptr [0x802458]
// 00409858  8bc6                 mov eax, esi
// 0040985a  e9d8000000           jmp 0x409937
// 0040985f  8d4d00               lea ecx, [ebp]
// 00409862  ff1560248000         call dword ptr [0x802460]
// 00409868  8b554c               mov edx, dword ptr [ebp + 0x4c]
// 0040986b  52                   push edx
// 0040986c  8d4d1c               lea ecx, [ebp + 0x1c]
// 0040986f  c645fc01             mov byte ptr [ebp - 4], 1
// 00409873  ff1558248000         call dword ptr [0x802458]
// 00409879  8b7550               mov esi, dword ptr [ebp + 0x50]
// 0040987c  b302                 mov bl, 2
// 0040987e  885dfc               mov byte ptr [ebp - 4], bl
// 00409881  3bf7                 cmp esi, edi
// 00409883  7418                 je 0x40989d
// 00409885  680cb78000           push 0x80b70c
// 0040988a  8d4d1c               lea ecx, [ebp + 0x1c]
// 0040988d  ff1548248000         call dword ptr [0x802448]
// 00409893  56                   push esi
// 00409894  8d4d1c               lea ecx, [ebp + 0x1c]
// 00409897  ff1548248000         call dword ptr [0x802448]
// 0040989d  8d4d1c               lea ecx, [ebp + 0x1c]
// 004098a0  ff1564248000         call dword ptr [0x802464]
// 004098a6  50                   push eax
// 004098a7  8d4db8               lea ecx, [ebp - 0x48]
// 004098aa  e8a1feffff           call 0x409750
// 004098af  68ecb68000           push 0x80b6ec
// 004098b4  8d4dd4               lea ecx, [ebp - 0x2c]
// 004098b7  c645fc03             mov byte ptr [ebp - 4], 3
// 004098bb  ff154c248000         call dword ptr [0x80244c]
// 004098c1  8b453c               mov eax, dword ptr [ebp + 0x3c]
// 004098c4  50                   push eax
// 004098c5  8d4dd4               lea ecx, [ebp - 0x2c]
// 004098c8  ff1550248000         call dword ptr [0x802450]
// 004098ce  68e8b68000           push 0x80b6e8
// 004098d3  8d4dd4               lea ecx, [ebp - 0x2c]
// 004098d6  ff1548248000         call dword ptr [0x802448]
// 004098dc  8d4d00               lea ecx, [ebp]
// 004098df  51                   push ecx
// 004098e0  8d4db8               lea ecx, [ebp - 0x48]
// 004098e3  e8f8011600           call 0x569ae0
// 004098e8  8d4db8               lea ecx, [ebp - 0x48]
// 004098eb  885dfc               mov byte ptr [ebp - 4], bl
// 004098ee  e82d5d1d00           call 0x5df620
// 004098f3  8d4d1c               lea ecx, [ebp + 0x1c]
// 004098f6  c645fc01             mov byte ptr [ebp - 4], 1
// 004098fa  ff1568248000         call dword ptr [0x802468]
// 00409900  8b7548               mov esi, dword ptr [ebp + 0x48]
// 00409903  8d5500               lea edx, [ebp]
// 00409906  52                   push edx
// 00409907  8bce                 mov ecx, esi
// 00409909  ff155c248000         call dword ptr [0x80245c]
// 0040990f  8d4d00               lea ecx, [ebp]
// 00409912  c645fc00             mov byte ptr [ebp - 4], 0
// 00409916  ff1568248000         call dword ptr [0x802468]
// 0040991c  8bc6                 mov eax, esi
// 0040991e  eb17                 jmp 0x409937

typedef unsigned long DWORD;

struct VersionInfo {
    DWORD size, major, minor, build, platform;
    char description[128];
};

extern "C" __declspec(dllimport) int __stdcall GetVersionExA(VersionInfo *);
extern "C" void * __cdecl memset(void *, int, unsigned int);

struct String;

extern void (__thiscall *stringDefault)(String *);
extern void (__thiscall *stringText)(String *, const char *);
extern void (__thiscall *stringCopy)(String *, const String &);
extern void (__thiscall *stringDestroy)(String *);
extern String &(__thiscall *stringAssign)(String *, const char *);
extern String &(__thiscall *stringAppendText)(String *, const char *);
extern String &(__thiscall *stringAppendString)(String *, const String &);
extern const char *(__thiscall *stringData)(const String *);

struct String {
    unsigned char storage[28];
    String();
    String(const char *);
    String(const String &);
    ~String();
    String &operator=(const char *);
    String &operator+=(const char *);
    String &operator+=(const String &);
    const char *c_str() const;
};

inline String::String() { stringDefault(this); }
inline String::String(const char *s) { stringText(this, s); }
inline String::String(const String &s) { stringCopy(this, s); }
inline String::~String() { stringDestroy(this); }
inline String &String::operator=(const char *s) { return stringAssign(this, s); }
inline String &String::operator+=(const char *s) { return stringAppendText(this, s); }
inline String &String::operator+=(const String &s) { return stringAppendString(this, s); }
inline const char *String::c_str() const { return stringData(this); }

struct Request {
    unsigned char storage[28];
    String headers;
    Request(const char *);
    ~Request();
    void execute(String *);
};

extern DWORD versionInitialized;
extern bool supportedVersion;

struct Creator {
    String create(const char *, const char *);
};

String Creator::create(const char *address, const char *suggestion)
{
    try {
        if (!(versionInitialized & 1)) {
            versionInitialized |= 1;
            VersionInfo version;
            memset(&version.major, 0, 0x90);
            version.size = 0x94;
            GetVersionExA(&version);
            bool supported = version.major >= 6;
            _ReadWriteBarrier();
            supportedVersion = supported;
        }

        if (!supportedVersion)
            return String("");

        String result;
        {
            String url(address);
            if (suggestion) {
                url += "?suggest=";
                url += suggestion;
            }
            Request request(url.c_str());
            request.headers = "RBXAuthenticationNegotiation:";
            request.headers += *reinterpret_cast<const String *>(this);
            request.headers += "\r\n";
            request.execute(&result);
        }
        return String(result);
    }
    catch (...) {
        return String("");
    }
}
