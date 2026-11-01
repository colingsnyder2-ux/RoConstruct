// from server: 100% by Yeetserama
// roc 2007-08 0044c8d0  unit: CRobloxControlColorSelector  size: 222 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044c8d0
//
// 0044c8d0  6aff                 push -1
// 0044c8d2  6898027400           push 0x740298
// 0044c8d7  64a100000000         mov eax, dword ptr fs:[0]
// 0044c8dd  50                   push eax
// 0044c8de  83ec1c               sub esp, 0x1c
// 0044c8e1  53                   push ebx
// 0044c8e2  56                   push esi
// 0044c8e3  57                   push edi
// 0044c8e4  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044c8e9  33c4                 xor eax, esp
// 0044c8eb  50                   push eax
// 0044c8ec  8d44242c             lea eax, [esp + 0x2c]
// 0044c8f0  64a300000000         mov dword ptr fs:[0], eax
// 0044c8f6  a1b4be8b00           mov eax, dword ptr [0x8bbeb4]
// 0044c8fb  8bd8                 mov ebx, eax
// 0044c8fd  83c001               add eax, 1
// 0044c900  8d4c2413             lea ecx, [esp + 0x13]
// 0044c904  a3b4be8b00           mov dword ptr [0x8bbeb4], eax
// 0044c909  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0044c90d  51                   push ecx
// 0044c90e  8d4c2420             lea ecx, [esp + 0x20]
// 0044c912  89442420             mov dword ptr [esp + 0x20], eax
// 0044c916  e855a11300           call 0x586a70
// 0044c91b  0fb67802             movzx edi, byte ptr [eax + 2]
// 0044c91f  8d542416             lea edx, [esp + 0x16]
// 0044c923  52                   push edx
// 0044c924  8d4c2420             lea ecx, [esp + 0x20]
// 0044c928  c1e708               shl edi, 8
// 0044c92b  e840a11300           call 0x586a70
// 0044c930  0fb67001             movzx esi, byte ptr [eax + 1]
// 0044c934  8d442419             lea eax, [esp + 0x19]
// 0044c938  0bf7                 or esi, edi
// 0044c93a  50                   push eax
// 0044c93b  8d4c2420             lea ecx, [esp + 0x20]
// 0044c93f  c1e608               shl esi, 8
// 0044c942  e829a11300           call 0x586a70
// 0044c947  0fb638               movzx edi, byte ptr [eax]
// 0044c94a  8d4c2428             lea ecx, [esp + 0x28]
// 0044c94e  0bfe                 or edi, esi
// 0044c950  ff15acdd7700         call dword ptr [0x77ddac]
// 0044c956  897c2420             mov dword ptr [esp + 0x20], edi
// 0044c95a  895c2424             mov dword ptr [esp + 0x24], ebx
// 0044c95e  8d4c243c             lea ecx, [esp + 0x3c]
// 0044c962  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0044c96a  e861a11300           call 0x586ad0
// 0044c96f  8bc8                 mov ecx, eax
// 0044c971  ff15a8e67700         call dword ptr [0x77e6a8]
// 0044c977  50                   push eax
// 0044c978  8d4c242c             lea ecx, [esp + 0x2c]
// 0044c97c  ff156cdd7700         call dword ptr [0x77dd6c]
// 0044c982  8d4c2420             lea ecx, [esp + 0x20]
// 0044c986  51                   push ecx
// 0044c987  b9b8be8b00           mov ecx, 0x8bbeb8
// 0044c98c  e89ffeffff           call 0x44c830
// 0044c991  8d4c2428             lea ecx, [esp + 0x28]
// 0044c995  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0044c99b  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0044c99f  64890d00000000       mov dword ptr fs:[0], ecx
// 0044c9a6  59                   pop ecx
// 0044c9a7  5f                   pop edi
// 0044c9a8  5e                   pop esi
// 0044c9a9  5b                   pop ebx
// 0044c9aa  83c428               add esp, 0x28
// 0044c9ad  c3                   ret 
// copied from an identical function in another client (function ?addColor@ns_ROCX000002@@YAXUBrickColor@1@@Z)

namespace ns_ROCX000002 {
struct RGB
{
    unsigned char r, g, b;
};

struct String
{
    const char* c_str() const;
};

struct BrickColor
{
    int value;
    RGB rgb() const;
    const String& name() const;
};

struct Text;
extern void (__thiscall *textConstruct)(Text*);
extern void (__thiscall *textDestroy)(Text*) throw();
extern void (__thiscall *textAssign)(Text*, const char*);
extern const char* (__thiscall *stringData)(const String*);

struct __declspec(dllimport) Text
{
    unsigned long value;
    Text();
    ~Text() throw();
    void assign(const char*);
};


struct Entry
{
    unsigned long color;
    int id;
    Text text;
    Entry(unsigned long, int);
};

inline Entry::Entry(unsigned long c, int i)
{
    color = c;
    id = i;
}

struct Registry
{
    void insert(const Entry*);
};

extern int nextId;
extern Registry registry;

void addColor(BrickColor color)
{
    int id = nextId++;
    BrickColor copy = color;

    unsigned long rgb =
        copy.rgb().r |
        ((copy.rgb().g | (copy.rgb().b << 8)) << 8);

    Entry entry(rgb, id);
    entry.text.assign(stringData(&color.name()));
    registry.insert(&entry);
}
}
