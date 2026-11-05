// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0060e920  unit: RBX::BlockBlockContact  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060e920
//
// 0060e920  56                   push esi
// 0060e921  57                   push edi
// 0060e922  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0060e926  8b4710               mov eax, dword ptr [edi + 0x10]
// 0060e929  2b470c               sub eax, dword ptr [edi + 0xc]
// 0060e92c  33f6                 xor esi, esi
// 0060e92e  c1f802               sar eax, 2
// 0060e931  85c0                 test eax, eax
// 0060e933  7632                 jbe 0x60e967
// 0060e935  53                   push ebx
// 0060e936  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0060e93a  55                   push ebp
// 0060e93b  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0060e941  3bf0                 cmp esi, eax
// 0060e943  7202                 jb 0x60e947
// 0060e945  ffd5                 call ebp
// 0060e947  8b470c               mov eax, dword ptr [edi + 0xc]
// 0060e94a  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 0060e94d  53                   push ebx
// 0060e94e  51                   push ecx
// 0060e94f  e8ecdcf8ff           call 0x59c640
// 0060e954  8b4710               mov eax, dword ptr [edi + 0x10]
// 0060e957  2b470c               sub eax, dword ptr [edi + 0xc]
// 0060e95a  46                   inc esi
// 0060e95b  c1f802               sar eax, 2
// 0060e95e  83c408               add esp, 8
// 0060e961  3bf0                 cmp esi, eax
// 0060e963  72e2                 jb 0x60e947
// 0060e965  5d                   pop ebp
// 0060e966  5b                   pop ebx
// 0060e967  5f                   pop edi
// 0060e968  5e                   pop esi
// 0060e969  c3                   ret 

extern "C" void (__cdecl *_invalid_parameter_noinfo)();
extern "C" void __cdecl process_entry(void *, void *);

struct S {
    unsigned int padding[3];
    void **begin;
    void **end;
};

void __cdecl f(S *s, void *argument)
{
    unsigned int i = 0;
    if (i < static_cast<unsigned int>(s->end - s->begin)) {
        void (__cdecl *invalid_parameter)() = _invalid_parameter_noinfo;
        do {
            if (i >= static_cast<unsigned int>(s->end - s->begin))
                invalid_parameter();

            process_entry(s->begin[i], argument);
            ++i;
        } while (i < static_cast<unsigned int>(s->end - s->begin));
    }
}
