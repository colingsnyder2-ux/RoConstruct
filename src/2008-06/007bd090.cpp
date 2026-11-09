// roc 2008-06 007bd090  unit: CSpinButtonCtrl  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007bd090
//
// 007bd090  8b01 35c0ff0000 83e0ff00 8901 c3
// mov eax, dword ptr [ecx]
// and eax, 0xfffffffe
// mov dword ptr [ecx], eax
// ret
//
// Compiled with: cl /c /O2 /GS- /MD /arch:SSE2 /fp:fast
//
extern "C" int func_007bd090(int *ecx)
{
    int result = *ecx;
    result &= 0xfffffffe;
    *ecx = result;
    return result;
}