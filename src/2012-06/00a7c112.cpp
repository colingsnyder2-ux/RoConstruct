// from server: 100% by Xemicl
// roc 2012-06 00a7c112  unit: std::D::DU?$char_traits::DV?$basic_streambuf::?$lexical_stream_limited_src  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7c112
//
// 00a7c112  8bff                 mov edi, edi
// 00a7c114  55                   push ebp
// 00a7c115  8bec                 mov ebp, esp
// 00a7c117  d94508               fld dword ptr [ebp + 8]
// 00a7c11a  d8650c               fsub dword ptr [ebp + 0xc]
// 00a7c11d  d90590dbc200         fld dword ptr [0xc2db90]
// 00a7c123  d8d9                 fcomp st(1)
// 00a7c125  dfe0                 fnstsw ax
// 00a7c127  f6c441               test ah, 0x41
// 00a7c12a  7a12                 jp 0xa7c13e
// 00a7c12c  d81dc00cbf00         fcomp dword ptr [0xbf0cc0]
// 00a7c132  dfe0                 fnstsw ax
// 00a7c134  f6c441               test ah, 0x41
// 00a7c137  7a07                 jp 0xa7c140
// 00a7c139  33c0                 xor eax, eax
// 00a7c13b  40                   inc eax
// 00a7c13c  eb04                 jmp 0xa7c142
// 00a7c13e  ddd8                 fstp st(0)
// 00a7c140  33c0                 xor eax, eax
// 00a7c142  5d                   pop ebp
// 00a7c143  c20800               ret 8
// copied from an identical function in another client (function ?FloatEqual@@YGHMM@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O1 /GS- /EHsc /MD /Oy- /hotpatch /fp:fast
#define FLT_EPSILON 1.192092896e-07F
int __stdcall FloatEqual(float a, float b)
{
    float d = a - b; return d >= -FLT_EPSILON && d <= FLT_EPSILON;
}