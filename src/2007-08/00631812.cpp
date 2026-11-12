// from server: 74% by EspClaude
// roc-flags: /O1 /EHsc /MD
// from server: 61% by Intel
// roc 2007-08 00631812  unit: std::bad_alloc  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00631812
//
// 00631812  6a08                 push 8
// 00631814  68789b8600           push 0x869b78
// 00631819  e802feffff           call 0x631620
// 0063181e  8365fc00             and dword ptr [ebp - 4], 0
// 00631822  ba00004000           mov edx, 0x400000
// 00631827  52                   push edx
// 00631828  e873ffffff           call 0x6317a0
// 0063182d  59                   pop ecx
// 0063182e  85c0                 test eax, eax
// 00631830  743d                 je 0x63186f
// 00631832  8b4508               mov eax, dword ptr [ebp + 8]
// 00631835  2bc2                 sub eax, edx
// 00631837  50                   push eax
// 00631838  52                   push edx
// 00631839  e892ffffff           call 0x6317d0
// 0063183e  59                   pop ecx
// 0063183f  59                   pop ecx
// 00631840  85c0                 test eax, eax
// 00631842  742b                 je 0x63186f
// 00631844  8b4024               mov eax, dword ptr [eax + 0x24]
// 00631847  c1e81f               shr eax, 0x1f
// 0063184a  f7d0                 not eax
// 0063184c  83e001               and eax, 1
// 0063184f  c745fcfeffffff       mov dword ptr [ebp - 4], 0xfffffffe
// 00631856  eb20                 jmp 0x631878

// IMAGE_SECTION_HEADER: Characteristics at +0x24 (target: mov eax,[eax+0x24]).
struct SectionHeader
{
    unsigned char pad[0x24];
    unsigned long Characteristics;
};

extern "C" unsigned char __ImageBase;
extern "C" int __cdecl _ValidateImageBase(unsigned char *pImageBase);
extern "C" SectionHeader *__cdecl _FindPESection(unsigned char *pImageBase, unsigned long rva);
extern "C" unsigned long __cdecl _exception_code(void);

extern "C" int __cdecl _IsNonwritableInCurrentImage(unsigned char *pTarget)
{
    unsigned char *pImageBase;
    unsigned long rvaTarget;
    SectionHeader *pSection;

    pImageBase = &__ImageBase;

    __try
    {
        if (!_ValidateImageBase(pImageBase))
        {
            return 0;
        }
        rvaTarget = (unsigned long)(pTarget - pImageBase);
        pSection = _FindPESection(pImageBase, rvaTarget);
        if (pSection == 0)
        {
            return 0;
        }
        return (pSection->Characteristics & 0x80000000) == 0;
    }
    __except (_exception_code() == 0xC0000005)
    {
        return 0;
    }
}
