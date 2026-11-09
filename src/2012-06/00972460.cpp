// roc 2012-06 00972460  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00972460
//
// 00972460  8b442404             mov eax, dword ptr [esp + 4]
// 00972464  56                   push esi
// 00972465  57                   push edi
// 00972466  8bf1                 mov esi, ecx
// 00972468  85c0                 test eax, eax
// 0097246a  7502                 jne 0x97246e
// 0097246c  8b06                 mov eax, dword ptr [esi]
// 0097246e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00972471  51                   push ecx
// 00972472  50                   push eax
// 00972473  8d7e08               lea edi, [esi + 8]
// 00972476  6a64                 push 0x64
// 00972478  57                   push edi
// 00972479  ff15482ab200         call dword ptr [0xb22a48]
// 0097247f  ff4604               inc dword ptr [esi + 4]
// 00972482  83c410               add esp, 0x10
// 00972485  8bc7                 mov eax, edi
// 00972487  5f                   pop edi
// 00972488  5e                   pop esi
// 00972489  c20400               ret 4
// copied from an identical function in another client (function ?f@S@@QAEPADPAD@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" int (__cdecl *_snprintf)(char *, unsigned int, const char *, ...);

struct S
{
    char *buffer;
    int count;
    char data[1];

    char *f(char *);
};

char *S::f(char *value)
{
    if (value == 0)
        value = buffer;
    _snprintf(data, 100, value, count);
    ++count;
    return data;
}