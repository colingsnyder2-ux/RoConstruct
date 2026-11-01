// from server: 100% by Espeon
// from server: 82% by king_originala
// roc 2008-06 005e6240  unit: RBX::Clump  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e6240
//
// 005e6240  53                   push ebx
// 005e6241  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005e6245  56                   push esi
// 005e6246  8bf1                 mov esi, ecx
// 005e6248  895e24               mov dword ptr [esi + 0x24], ebx
// 005e624b  8b4638               mov eax, dword ptr [esi + 0x38]
// 005e624e  2b4634               sub eax, dword ptr [esi + 0x34]
// 005e6251  57                   push edi
// 005e6252  c1f802               sar eax, 2
// 005e6255  33ff                 xor edi, edi
// 005e6257  85c0                 test eax, eax
// 005e6259  7631                 jbe 0x5e628c
// 005e625b  55                   push ebp
// 005e625c  8b2d90288000         mov ebp, dword ptr [0x802890]
// 005e6262  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 005e6265  2b4e34               sub ecx, dword ptr [esi + 0x34]
// 005e6268  c1f902               sar ecx, 2
// 005e626b  3bf9                 cmp edi, ecx
// 005e626d  7202                 jb 0x5e6271
// 005e626f  ffd5                 call ebp
// 005e6271  8b5634               mov edx, dword ptr [esi + 0x34]
// 005e6274  8b0cba               mov ecx, dword ptr [edx + edi*4]
// 005e6277  53                   push ebx
// 005e6278  e8c3ffffff           call 0x5e6240
// 005e627d  8b4638               mov eax, dword ptr [esi + 0x38]
// 005e6280  2b4634               sub eax, dword ptr [esi + 0x34]
// 005e6283  47                   inc edi
// 005e6284  c1f802               sar eax, 2
// 005e6287  3bf8                 cmp edi, eax
// 005e6289  72d7                 jb 0x5e6262
// 005e628b  5d                   pop ebp
// 005e628c  5f                   pop edi
// 005e628d  5e                   pop esi
// 005e628e  5b                   pop ebx
// 005e628f  c20400               ret 4

extern "C" __declspec(dllimport) void __cdecl invalid_parameter_noinfo();

struct Clump
{
    char reserved0[0x24];
    volatile unsigned int value;
    char reserved1[0x0C];
    Clump** first;
    Clump** volatile last;

    void setValue(unsigned int newValue);
};

void Clump::setValue(unsigned int newValue)
{
    value = newValue;
    for (unsigned int i = 0; i < (unsigned int)(last - first); ++i)
    {
        if (i >= (unsigned int)(last - first))
            invalid_parameter_noinfo();
        first[i]->setValue(newValue);
    }
}




