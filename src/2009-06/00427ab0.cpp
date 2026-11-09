// from server: 100% by EspClaude
// roc 2009-06 00427ab0  unit: CWrapperView  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00427ab0
//
// 00427ab0  6aff                 push -1
// 00427ab2  68b2ee8400           push 0x84eeb2
// 00427ab7  64a100000000         mov eax, dword ptr fs:[0]
// 00427abd  50                   push eax
// 00427abe  64892500000000       mov dword ptr fs:[0], esp
// 00427ac5  83ec20               sub esp, 0x20
// 00427ac8  a16cc8a300           mov eax, dword ptr [0xa3c86c]
// 00427acd  56                   push esi
// 00427ace  57                   push edi
// 00427acf  50                   push eax
// 00427ad0  8d4c2410             lea ecx, [esp + 0x10]
// 00427ad4  51                   push ecx
// 00427ad5  e8e6092e00           call 0x7084c0
// 00427ada  83c408               add esp, 8
// 00427add  8d4c2408             lea ecx, [esp + 8]
// 00427ae1  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00427ae9  ff15bcfc8900         call dword ptr [0x89fcbc]
// 00427aef  8d4c240c             lea ecx, [esp + 0xc]
// 00427af3  c644243001           mov byte ptr [esp + 0x30], 1
// 00427af8  ff15bce48900         call dword ptr [0x89e4bc]
// 00427afe  50                   push eax
// 00427aff  8d54240c             lea edx, [esp + 0xc]
// 00427b03  68c0118b00           push 0x8b11c0
// 00427b08  52                   push edx
// 00427b09  ff15c4fc8900         call dword ptr [0x89fcc4]
// 00427b0f  8b742444             mov esi, dword ptr [esp + 0x44]
// 00427b13  8b3e                 mov edi, dword ptr [esi]
// 00427b15  83c40c               add esp, 0xc
// 00427b18  8d4c2408             lea ecx, [esp + 8]
// 00427b1c  ff15d0fc8900         call dword ptr [0x89fcd0]
// 00427b22  50                   push eax
// 00427b23  8b470c               mov eax, dword ptr [edi + 0xc]
// 00427b26  8bce                 mov ecx, esi
// 00427b28  ffd0                 call eax
// 00427b2a  8d4c2408             lea ecx, [esp + 8]
// 00427b2e  ff1510fd8900         call dword ptr [0x89fd10]
// 00427b34  8d4c240c             lea ecx, [esp + 0xc]
// 00427b38  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00427b40  ff15c4e48900         call dword ptr [0x89e4c4]
// 00427b46  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00427b4a  5f                   pop edi
// 00427b4b  5e                   pop esi
// 00427b4c  64890d00000000       mov dword ptr fs:[0], ecx
// 00427b53  83c42c               add esp, 0x2c
// 00427b56  c20400               ret 4
// copied from an identical function in another client (function ?func_42ed20@ns_ROCX0000eb@@YGXPAUOutput@1@@Z)

namespace ns_ROCX0000eb {
struct String {
    char storage[28];
    ~String();
    const char *c_str() const;
};

struct Text {
    char storage[4];
    Text();
    __declspec(dllimport) ~Text() throw();
    const char *c_str() const;
};

extern void (__thiscall *destroyString)(String *);
extern const char *(__thiscall *stringData)(const String *);
extern void (__thiscall *constructText)(Text *);
extern void (__thiscall *destroyText)(Text *);
extern const char *(__thiscall *textData)(const Text *);
extern void (__cdecl *formatText)(Text *, const char *, ...);

inline String::~String()
{
    destroyString(this);
}

inline const char *String::c_str() const
{
    return stringData(this);
}

inline Text::Text()
{
    constructText(this);
}

inline const char *Text::c_str() const
{
    return textData(this);
}

extern unsigned int count;
extern String __cdecl formatCount(unsigned int);

struct Output;

struct OutputTable {
    char reserved[12];
    void (__thiscall *write)(Output *, const char *);
};

struct Output {
    OutputTable *table;
};

void __stdcall func_42ed20(Output *output)
{
    String value = formatCount(count);
    Text text;
    formatText(&text, "VAR %s", value.c_str());
    OutputTable *t = output->table;
    t->write(output, text.c_str());
}
}
