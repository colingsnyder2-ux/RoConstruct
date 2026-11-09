// roc 2009-12 0080fb80  unit: CXTPImageManagerIcon  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080fb80
//
// 0080fb80  56                   push esi
// 0080fb81  57                   push edi
// 0080fb82  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0080fb86  57                   push edi
// 0080fb87  8bf1                 mov esi, ecx
// 0080fb89  e8e2d8ffff           call 0x80d470
// 0080fb8e  85c0                 test eax, eax
// 0080fb90  7413                 je 0x80fba5
// 0080fb92  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0080fb96  6a01                 push 1
// 0080fb98  51                   push ecx
// 0080fb99  8bc8                 mov ecx, eax
// 0080fb9b  e8e0d7ffff           call 0x80d380
// 0080fba0  5f                   pop edi
// 0080fba1  5e                   pop esi
// 0080fba2  c20800               ret 8
// 0080fba5  57                   push edi
// 0080fba6  8bce                 mov ecx, esi
// 0080fba8  e813cdffff           call 0x80c8c0
// 0080fbad  85c0                 test eax, eax
// 0080fbaf  740d                 je 0x80fbbe
// 0080fbb1  57                   push edi
// 0080fbb2  8bc8                 mov ecx, eax
// 0080fbb4  e887deffff           call 0x80da40
// 0080fbb9  5f                   pop edi
// 0080fbba  5e                   pop esi
// 0080fbbb  c20800               ret 8
// 0080fbbe  5f                   pop edi
// 0080fbbf  33c0                 xor eax, eax
// 0080fbc1  5e                   pop esi
// 0080fbc2  c20800               ret 8
// copied from an identical function in another client (function ?setImage@CXTPImageManager@ns_ROCX000033@ns_ROCX000017@@QAEPAXHH@Z)

namespace ns_ROCX000033 {
extern char G;

char* fn_ROCX000033()
{
    return &G;
}
}
