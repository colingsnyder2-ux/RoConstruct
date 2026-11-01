// from server: 100% by colin
// roc 2007-08 0054c470  unit: UString_sink::?$stream_buffer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054c470
//
// 0054c470  56                   push esi
// 0054c471  8bf1                 mov esi, ecx
// 0054c473  8b4614               mov eax, dword ptr [esi + 0x14]
// 0054c476  8b08                 mov ecx, dword ptr [eax]
// 0054c478  8b5624               mov edx, dword ptr [esi + 0x24]
// 0054c47b  8b02                 mov eax, dword ptr [edx]
// 0054c47d  2bc1                 sub eax, ecx
// 0054c47f  85c0                 test eax, eax
// 0054c481  7e24                 jle 0x54c4a7
// 0054c483  50                   push eax
// 0054c484  51                   push ecx
// 0054c485  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c488  ff1520e57700         call dword ptr [0x77e520]
// 0054c48e  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 0054c491  8b5614               mov edx, dword ptr [esi + 0x14]
// 0054c494  8b4650               mov eax, dword ptr [esi + 0x50]
// 0054c497  890a                 mov dword ptr [edx], ecx
// 0054c499  8b5624               mov edx, dword ptr [esi + 0x24]
// 0054c49c  03c1                 add eax, ecx
// 0054c49e  890a                 mov dword ptr [edx], ecx
// 0054c4a0  2bc1                 sub eax, ecx
// 0054c4a2  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0054c4a5  8901                 mov dword ptr [ecx], eax
// 0054c4a7  5e                   pop esi
// 0054c4a8  c3                   ret 
// copied from an identical function in another client (function ?flush@S@@QAEXXZ)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef void *(__thiscall *AppendFunction)(void *, const char *, unsigned int);
extern AppendFunction append;

struct S {
    char padding0[0x14];
    char **first;
    char padding1[0x0C];
    char **last;
    char padding2[0x0C];
    int *available;
    char padding3[0x08];
    void *output;
    char padding4[0x08];
    char *buffer;
    int length;

    void flush();
};

void S::flush()
{
    char *start = *first;
    int count = *last - start;
    if (count > 0) {
        append(output, start, count);
        char *begin = buffer;
        char *end = begin + length;
        *first = begin;
        *last = begin;
        *available = end - begin;
    }
}