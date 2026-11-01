// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 0040a530  unit: boost::any::_N::?$holder  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040a530
//
// 0040a530  83ec0c               sub esp, 0xc
// 0040a533  53                   push ebx
// 0040a534  56                   push esi
// 0040a535  8bf1                 mov esi, ecx
// 0040a537  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0040a53a  2b4e10               sub ecx, dword ptr [esi + 0x10]
// 0040a53d  8b561c               mov edx, dword ptr [esi + 0x1c]
// 0040a540  c1f902               sar ecx, 2
// 0040a543  57                   push edi
// 0040a544  33c0                 xor eax, eax
// 0040a546  8d7c240c             lea edi, [esp + 0xc]
// 0040a54a  8944240c             mov dword ptr [esp + 0xc], eax
// 0040a54e  894c2410             mov dword ptr [esp + 0x10], ecx
// 0040a552  89542414             mov dword ptr [esp + 0x14], edx
// 0040a556  897e1c               mov dword ptr [esi + 0x1c], edi
// 0040a559  85c9                 test ecx, ecx
// 0040a55b  7656                 jbe 0x40a5b3
// 0040a55d  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0040a563  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0040a566  2b4e10               sub ecx, dword ptr [esi + 0x10]
// 0040a569  8bf8                 mov edi, eax
// 0040a56b  c1f902               sar ecx, 2
// 0040a56e  3bc1                 cmp eax, ecx
// 0040a570  7202                 jb 0x40a574
// 0040a572  ffd3                 call ebx
// 0040a574  8b5610               mov edx, dword ptr [esi + 0x10]
// 0040a577  8b04ba               mov eax, dword ptr [edx + edi*4]
// 0040a57a  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0040a57e  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0040a582  50                   push eax
// 0040a583  83ec08               sub esp, 8
// 0040a586  8bc4                 mov eax, esp
// 0040a588  894804               mov dword ptr [eax + 4], ecx
// 0040a58b  8bce                 mov ecx, esi
// 0040a58d  8910                 mov dword ptr [eax], edx
// 0040a58f  e82cfcffff           call 0x40a1c0
// 0040a594  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040a598  40                   inc eax
// 0040a599  8944240c             mov dword ptr [esp + 0xc], eax
// 0040a59d  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0040a5a1  72c0                 jb 0x40a563
// 0040a5a3  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040a5a7  89461c               mov dword ptr [esi + 0x1c], eax
// 0040a5ab  5f                   pop edi
// 0040a5ae  5e                   pop esi
// 0040a5ac  5b                   pop ebx
// 0040a5ad  83c40c               add esp, 0xc
// 0040a5b0  c20800               ret 8
// 0040a5b3  5f                   pop edi
// 0040a5b4  89561c               mov dword ptr [esi + 0x1c], edx
// 0040a5b7  5e                   pop esi
// 0040a5b8  5b                   pop ebx
// 0040a5b9  83c40c               add esp, 0xc
// 0040a5bc  c20800               ret 8

extern "C" void (__cdecl * _invalid_parameter_noinfo)();

struct Arguments {
    unsigned first;
    unsigned second;

    Arguments(const Arguments& other);
};

inline Arguments::Arguments(const Arguments& other)
{
    const volatile Arguments& source = other;
    unsigned secondValue = source.second;
    unsigned firstValue = source.first;
    second = secondValue;
    first = firstValue;
}

struct Iteration {
    unsigned index;
    unsigned count;
    Iteration* previous;
};

struct S {
    unsigned padding[4];
    unsigned* begin;
    unsigned* end;
    unsigned reserved;
    Iteration* active;

    void dispatch(Arguments args, unsigned value);
    void f(Arguments args);
};

void S::f(Arguments args)
{
    Iteration iteration;
    iteration.index = 0;
    iteration.count = static_cast<unsigned>(end - begin);
    iteration.previous = active;
    active = &iteration;

    if (iteration.count > 0) {
        void (__cdecl * invalid)() = _invalid_parameter_noinfo;
        do {
            unsigned index = iteration.index;
            if (index >= static_cast<unsigned>(end - begin))
                invalid();
            unsigned beginCopy = begin[index];
            dispatch(args, beginCopy);
            ++iteration.index;
        } while (iteration.index < iteration.count);
    }

    active = iteration.previous;
}