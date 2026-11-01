// from server: 100% by colin
// roc 2007-08 00465f80  unit: DxUserInput  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00465f80
//
// 00465f80  8b442404             mov eax, dword ptr [esp + 4]
// 00465f84  0500feffff           add eax, 0xfffffe00
// 00465f89  83f805               cmp eax, 5
// 00465f8c  7725                 ja 0x465fb3
// 00465f8e  ff2485b85f4600       jmp dword ptr [eax*4 + 0x465fb8]
// 00465f95  b805000000           mov eax, 5
// 00465f9a  c3                   ret 
// 00465f9b  b803000000           mov eax, 3
// 00465fa0  c3                   ret 
// 00465fa1  b801000000           mov eax, 1
// 00465fa6  c3                   ret 
// 00465fa7  b804000000           mov eax, 4
// 00465fac  c3                   ret 
// 00465fad  b802000000           mov eax, 2
// 00465fb2  c3                   ret 
// 00465fb3  33c0                 xor eax, eax
// 00465fb5  c3                   ret 
// 00465fb6  8bff                 mov edi, edi
// 00465fb8  95                   xchg ebp, eax
// 00465fb9  5f                   pop edi
// 00465fba  46                   inc esi
// 00465fbb  009b5f4600a7         add byte ptr [ebx - 0x58ffb9a1], bl
// 00465fc1  5f                   pop edi
// 00465fc2  46                   inc esi
// 00465fc3  00b35f4600a1         add byte ptr [ebx - 0x5effb9a1], dh
// 00465fc9  5f                   pop edi
// 00465fca  46                   inc esi
// copied from an identical function in another client (function ?getButton@@YAHH@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct DxUserInput
{
};

int __cdecl getButton(int code)
{
    switch (code)
    {
    case 512:
        return 5;
    case 513:
        return 3;
    case 514:
        return 1;
    case 515:
        return 4;
    case 516:
        return 2;
    case 517:
        return 0;
    default:
        return 0;
    }
}