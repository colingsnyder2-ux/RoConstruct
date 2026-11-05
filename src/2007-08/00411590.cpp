// from server: 100% by Yeetserama
// roc 2007-08 00411590  unit: CopyVerb  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00411590
//
// 00411590  56                   push esi
// 00411591  57                   push edi
// 00411592  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00411596  85ff                 test edi, edi
// 00411598  8bf1                 mov esi, ecx
// 0041159a  750a                 jne 0x4115a6
// 0041159c  5f                   pop edi
// 0041159d  b803400080           mov eax, 0x80004003
// 004115a2  5e                   pop esi
// 004115a3  c20400               ret 4
// 004115a6  57                   push edi
// 004115a7  ff15d8e97700         call dword ptr [0x77e9d8]
// 004115ad  85c0                 test eax, eax
// 004115af  7c1c                 jl 0x4115cd
// 004115b1  6a10                 push 0x10
// 004115b3  56                   push esi
// 004115b4  6a10                 push 0x10
// 004115b6  57                   push edi
// 004115b7  ff15d4e67700         call dword ptr [0x77e6d4]
// 004115bd  50                   push eax
// 004115be  e81d01ffff           call 0x4016e0
// 004115c3  83c414               add esp, 0x14
// 004115c6  66c7060000           mov word ptr [esi], 0
// 004115cb  33c0                 xor eax, eax
// 004115cd  5f                   pop edi
// 004115ce  5e                   pop esi
// 004115cf  c20400               ret 4
// copied from an identical function in another client (function ?moveTo@Variant@ns_ROCX000001@@QAEJPAU12@@Z)

namespace ns_ROCX000001 {
// from server: 100% by king_originala
struct Variant {
    unsigned short type;
    unsigned char data[14];

    long moveTo(Variant* destination);
};

extern "C" long (__stdcall *VariantClear)(Variant*);
extern "C" int (__cdecl *memcpy_s)(void*, unsigned int, const void*, unsigned int);
void __cdecl checkResult(int);

long Variant::moveTo(Variant* destination)
{
    if (!destination)
        return (long)0x80004003;

    long result = VariantClear(destination);
    if (result >= 0) {
        checkResult(memcpy_s(destination, 16, this, 16));
        type = 0;
        result = 0;
    }
    return result;
}
}
