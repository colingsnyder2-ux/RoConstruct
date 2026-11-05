// from server: 100% by colin
// roc 2007-08 0056d5b0  unit: boost::any::N::?$holder  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056d5b0
//
// 0056d5b0  6aff                 push -1
// 0056d5b2  68f8b57500           push 0x75b5f8
// 0056d5b7  64a100000000         mov eax, dword ptr fs:[0]
// 0056d5bd  50                   push eax
// 0056d5be  64892500000000       mov dword ptr fs:[0], esp
// 0056d5c5  51                   push ecx
// 0056d5c6  53                   push ebx
// 0056d5c7  56                   push esi
// 0056d5c8  8bf1                 mov esi, ecx
// 0056d5ca  57                   push edi
// 0056d5cb  8974240c             mov dword ptr [esp + 0xc], esi
// 0056d5cf  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0056d5d3  8d7e04               lea edi, [esi + 4]
// 0056d5d6  53                   push ebx
// 0056d5d7  8bcf                 mov ecx, edi
// 0056d5d9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0056d5e1  c706c49f7a00         mov dword ptr [esi], 0x7a9fc4
// 0056d5e7  ff159ce67700         call dword ptr [0x77e69c]
// 0056d5ed  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 0056d5f0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056d5f4  89471c               mov dword ptr [edi + 0x1c], eax
// 0056d5f7  5f                   pop edi
// 0056d5f8  8bc6                 mov eax, esi
// 0056d5fa  5e                   pop esi
// 0056d5fb  5b                   pop ebx
// 0056d5fc  64890d00000000       mov dword ptr fs:[0], ecx
// 0056d603  83c410               add esp, 0x10
// 0056d606  c20400               ret 4
// copied from an identical function in another client (function ??0S@@QAE@ABUSource@@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct StringData {
    unsigned char data[28];
};

extern void (__thiscall *copy_string)(StringData*, const StringData&);

struct Source {
    StringData text;
    int value;

    Source(const Source& other)
    {
        copy_string(&text, other.text);
        value = other.value;
    }
};

struct Base {
    virtual ~Base();
};

struct S : Base {
    Source data;

    S(const Source&);
    virtual ~S();
};

S::S(const Source& source) : data(source)
{
}