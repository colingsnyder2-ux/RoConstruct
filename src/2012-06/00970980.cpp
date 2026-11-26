// from server: 100% by Xemicl
// roc 2012-06 00970980  unit: W4_D3DFORMAT::?$EnumDesc  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00970980
//
// 00970980  8b442404             mov eax, dword ptr [esp + 4]
// 00970984  83c0ec               add eax, -0x14
// 00970987  83f810               cmp eax, 0x10
// 0097098a  772b                 ja 0x9709b7
// 0097098c  ff2485bc099700       jmp dword ptr [eax*4 + 0x9709bc]
// 00970993  b808000000           mov eax, 8
// 00970998  c3                   ret 
// 00970999  b805000000           mov eax, 5
// 0097099e  c3                   ret 
// 0097099f  b804000000           mov eax, 4
// 009709a4  c3                   ret 
// 009709a5  b802000000           mov eax, 2
// 009709aa  c3                   ret 
// 009709ab  b80a000000           mov eax, 0xa
// 009709b0  c3                   ret 
// 009709b1  b810000000           mov eax, 0x10
// 009709b6  c3                   ret 
// 009709b7  33c0                 xor eax, eax
// 009709b9  c3                   ret 
// 009709ba  8bff                 mov edi, edi
// 009709bc  93                   xchg ebx, eax
// 009709bd  099700930997         or dword ptr [edi - 0x68f66d00], edx
// 009709c3  009309970099         add byte ptr [ebx - 0x66ff68f7], dl
// 009709c9  099700990997         or dword ptr [edi - 0x68f66700], edx
// 009709cf  00990997009f         add byte ptr [ecx - 0x60ff68f7], bl
// 009709d5  099700a50997         or dword ptr [edi - 0x68f65b00], edx
// 009709db  00b7099700a5         add byte ptr [edi - 0x5aff68f7], dh
// 009709e1  0997009f0997         or dword ptr [edi - 0x68f66100], edx
// 009709e7  00ab09970093         add byte ptr [ebx - 0x6cff68f7], ch
// 009709ed  099700b70997         or dword ptr [edi - 0x68f64900], edx
// 009709f3  00b7099700ab         add byte ptr [edi - 0x54ff68f7], dh
// 009709f9  099700b10997         or dword ptr [edi - 0x68f64f00], edx
// copied from an identical function in another client (function ?getColourBits@@YAHH@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
int getColourBits(int format)
{
    switch (format) {
    case 20: return 8;
    case 21: return 8;
    case 22: return 8;
    case 23: return 5;
    case 24: return 5;
    case 25: return 5;
    case 26: return 4;
    case 27: return 2;
    case 28: return 0;
    case 29: return 2;
    case 30: return 4;
    case 31: return 10;
    case 32: return 8;
    case 33: return 0;
    case 34: return 0;
    case 35: return 10;
    case 36: return 16;
    }
    return 0;
}