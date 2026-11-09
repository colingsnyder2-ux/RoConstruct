// from server: 100% by EspClaude
// roc 2009-06 0044ccf0  unit: CRobloxControlColorSelector  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044ccf0
//
// 0044ccf0  6aff                 push -1
// 0044ccf2  68c80d8500           push 0x850dc8
// 0044ccf7  64a100000000         mov eax, dword ptr fs:[0]
// 0044ccfd  50                   push eax
// 0044ccfe  64892500000000       mov dword ptr fs:[0], esp
// 0044cd05  83ec1c               sub esp, 0x1c
// 0044cd08  a148b3a300           mov eax, dword ptr [0xa3b348]
// 0044cd0d  53                   push ebx
// 0044cd0e  56                   push esi
// 0044cd0f  8bd8                 mov ebx, eax
// 0044cd11  40                   inc eax
// 0044cd12  57                   push edi
// 0044cd13  8d4c240f             lea ecx, [esp + 0xf]
// 0044cd17  a348b3a300           mov dword ptr [0xa3b348], eax
// 0044cd1c  8b442438             mov eax, dword ptr [esp + 0x38]
// 0044cd20  51                   push ecx
// 0044cd21  8d4c241c             lea ecx, [esp + 0x1c]
// 0044cd25  8944241c             mov dword ptr [esp + 0x1c], eax
// 0044cd29  e8f25d1f00           call 0x642b20
// 0044cd2e  0fb67802             movzx edi, byte ptr [eax + 2]
// 0044cd32  8d542412             lea edx, [esp + 0x12]
// 0044cd36  52                   push edx
// 0044cd37  8d4c241c             lea ecx, [esp + 0x1c]
// 0044cd3b  c1e708               shl edi, 8
// 0044cd3e  e8dd5d1f00           call 0x642b20
// 0044cd43  0fb67001             movzx esi, byte ptr [eax + 1]
// 0044cd47  8d442415             lea eax, [esp + 0x15]
// 0044cd4b  0bf7                 or esi, edi
// 0044cd4d  50                   push eax
// 0044cd4e  8d4c241c             lea ecx, [esp + 0x1c]
// 0044cd52  c1e608               shl esi, 8
// 0044cd55  e8c65d1f00           call 0x642b20
// 0044cd5a  0fb638               movzx edi, byte ptr [eax]
// 0044cd5d  8d4c2424             lea ecx, [esp + 0x24]
// 0044cd61  0bfe                 or edi, esi
// 0044cd63  ff15bcfc8900         call dword ptr [0x89fcbc]
// 0044cd69  897c241c             mov dword ptr [esp + 0x1c], edi
// 0044cd6d  895c2420             mov dword ptr [esp + 0x20], ebx
// 0044cd71  8d4c2438             lea ecx, [esp + 0x38]
// 0044cd75  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0044cd7d  e8ce5d1f00           call 0x642b50
// 0044cd82  8bc8                 mov ecx, eax
// 0044cd84  ff15bce48900         call dword ptr [0x89e4bc]
// 0044cd8a  50                   push eax
// 0044cd8b  8d4c2428             lea ecx, [esp + 0x28]
// 0044cd8f  ff15acfc8900         call dword ptr [0x89fcac]
// 0044cd95  8d4c241c             lea ecx, [esp + 0x1c]
// 0044cd99  51                   push ecx
// 0044cd9a  b94cb3a300           mov ecx, 0xa3b34c
// 0044cd9f  e8acfeffff           call 0x44cc50
// 0044cda4  8d4c2424             lea ecx, [esp + 0x24]
// 0044cda8  ff1510fd8900         call dword ptr [0x89fd10]
// 0044cdae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0044cdb2  5f                   pop edi
// 0044cdb3  5e                   pop esi
// 0044cdb4  5b                   pop ebx
// 0044cdb5  64890d00000000       mov dword ptr fs:[0], ecx
// 0044cdbc  83c428               add esp, 0x28
// 0044cdbf  c3                   ret 
// copied from an identical function in another client (function ?addColor@ns_ROCX00001d@@YAXUBrickColor@1@@Z)

namespace ns_ROCX00001d {
// from server: 96% by king_originala
// roc 2008-06 0044eb90  unit: CRobloxControlColorSelector  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044eb90
//
// 0044eb90  6aff                 push -1
// 0044eb92  6878157c00           push 0x7c1578
// 0044eb97  64a100000000         mov eax, dword ptr fs:[0]
// 0044eb9d  50                   push eax
// 0044eb9e  64892500000000       mov dword ptr fs:[0], esp
// 0044eba5  83ec1c               sub esp, 0x1c
// 0044eba8  a120dd9600           mov eax, dword ptr [0x96dd20]
// 0044ebad  53                   push ebx
// 0044ebae  56                   push esi
// 0044ebaf  8bd8                 mov ebx, eax
// 0044ebb1  40                   inc eax
// 0044ebb2  57                   push edi
// 0044ebb3  8d4c240f             lea ecx, [esp + 0xf]
// 0044ebb7  a320dd9600           mov dword ptr [0x96dd20], eax
// 0044ebbc  8b442438             mov eax, dword ptr [esp + 0x38]
// 0044ebc0  51                   push ecx
// 0044ebc1  8d4c241c             lea ecx, [esp + 0x1c]
// 0044ebc5  8944241c             mov dword ptr [esp + 0x1c], eax
// 0044ebc9  e8b2751600           call 0x5b6180
// 0044ebce  0fb67802             movzx edi, byte ptr [eax + 2]
// 0044ebd2  8d542412             lea edx, [esp + 0x12]
// 0044ebd6  52                   push edx
// 0044ebd7  8d4c241c             lea ecx, [esp + 0x1c]
// 0044ebdb  c1e708               shl edi, 8
// 0044ebde  e89d751600           call 0x5b6180
// 0044ebe3  0fb67001             movzx esi, byte ptr [eax + 1]
// 0044ebe7  8d442415             lea eax, [esp + 0x15]
// 0044ebeb  0bf7                 or esi, edi
// 0044ebed  50                   push eax
// 0044ebee  8d4c241c             lea ecx, [esp + 0x1c]
// 0044ebf2  c1e608               shl esi, 8
// 0044ebf5  e886751600           call 0x5b6180
// 0044ebfa  0fb638               movzx edi, byte ptr [eax]
// 0044ebfd  8d4c2424             lea ecx, [esp + 0x24]
// 0044ec01  0bfe                 or edi, esi
// 0044ec03  ff15043f8000         call dword ptr [0x803f04]
// 0044ec09  897c241c             mov dword ptr [esp + 0x1c], edi
// 0044ec0d  895c2420             mov dword ptr [esp + 0x20], ebx
// 0044ec11  8d4c2438             lea ecx, [esp + 0x38]
// 0044ec15  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0044ec1d  e88e751600           call 0x5b61b0
// 0044ec22  8bc8                 mov ecx, eax
// 0044ec24  ff1564248000         call dword ptr [0x802464]
// 0044ec2a  50                   push eax
// 0044ec2b  8d4c2428             lea ecx, [esp + 0x28]
// 0044ec2f  ff15b83e8000         call dword ptr [0x803eb8]
// 0044ec35  8d4c241c             lea ecx, [esp + 0x1c]
// 0044ec39  51                   push ecx
// 0044ec3a  b924dd9600           mov ecx, 0x96dd24
// 0044ec3f  e8acfeffff           call 0x44eaf0
// 0044ec44  8d4c2424             lea ecx, [esp + 0x24]
// 0044ec48  ff15143f8000         call dword ptr [0x803f14]
// 0044ec4e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0044ec52  5f                   pop edi
// 0044ec53  5e                   pop esi
// 0044ec54  5b                   pop ebx
// 0044ec55  64890d00000000       mov dword ptr fs:[0], ecx
// 0044ec5c  83c428               add esp, 0x28
// 0044ec5f  c3                   ret 

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
