// from server: 100% by Yeetserama
// roc 2007-08 0042eee0  unit: CWrapperView  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042eee0
//
// 0042eee0  6aff                 push -1
// 0042eee2  6882d77300           push 0x73d782
// 0042eee7  64a100000000         mov eax, dword ptr fs:[0]
// 0042eeed  50                   push eax
// 0042eeee  83ec24               sub esp, 0x24
// 0042eef1  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042eef6  33c4                 xor eax, esp
// 0042eef8  89442420             mov dword ptr [esp + 0x20], eax
// 0042eefc  56                   push esi
// 0042eefd  57                   push edi
// 0042eefe  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042ef03  33c4                 xor eax, esp
// 0042ef05  50                   push eax
// 0042ef06  8d442430             lea eax, [esp + 0x30]
// 0042ef0a  64a300000000         mov dword ptr fs:[0], eax
// 0042ef10  a1b4d08b00           mov eax, dword ptr [0x8bd0b4]
// 0042ef15  8b742440             mov esi, dword ptr [esp + 0x40]
// 0042ef19  50                   push eax
// 0042ef1a  8d4c2414             lea ecx, [esp + 0x14]
// 0042ef1e  51                   push ecx
// 0042ef1f  e8ac0f1500           call 0x57fed0
// 0042ef24  83c408               add esp, 8
// 0042ef27  8d4c240c             lea ecx, [esp + 0xc]
// 0042ef2b  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0042ef33  ff15acdd7700         call dword ptr [0x77ddac]
// 0042ef39  8d4c2410             lea ecx, [esp + 0x10]
// 0042ef3d  c644243801           mov byte ptr [esp + 0x38], 1
// 0042ef42  ff15a8e67700         call dword ptr [0x77e6a8]
// 0042ef48  50                   push eax
// 0042ef49  8d542410             lea edx, [esp + 0x10]
// 0042ef4d  6830ab7800           push 0x78ab30
// 0042ef52  52                   push edx
// 0042ef53  ff1594dd7700         call dword ptr [0x77dd94]
// 0042ef59  8b3e                 mov edi, dword ptr [esi]
// 0042ef5b  83c40c               add esp, 0xc
// 0042ef5e  8d4c240c             lea ecx, [esp + 0xc]
// 0042ef62  ff1598dd7700         call dword ptr [0x77dd98]
// 0042ef68  50                   push eax
// 0042ef69  8b470c               mov eax, dword ptr [edi + 0xc]
// 0042ef6c  8bce                 mov ecx, esi
// 0042ef6e  ffd0                 call eax
// 0042ef70  8d4c240c             lea ecx, [esp + 0xc]
// 0042ef74  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0042ef7a  8d4c2410             lea ecx, [esp + 0x10]
// 0042ef7e  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 0042ef86  ff15ace67700         call dword ptr [0x77e6ac]
// 0042ef8c  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0042ef90  64890d00000000       mov dword ptr fs:[0], ecx
// 0042ef97  59                   pop ecx
// 0042ef98  5f                   pop edi
// 0042ef99  5e                   pop esi
// 0042ef9a  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0042ef9e  33cc                 xor ecx, esp
// 0042efa0  e8791a2000           call 0x630a1e
// 0042efa5  83c430               add esp, 0x30
// 0042efa8  c20400               ret 4
// copied from an identical function in another client (function ?func_42ed20@ns_ROCX000003@@YGXPAUOutput@1@@Z)

namespace ns_ROCX000003 {
// from server: 100% by king_originala
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
