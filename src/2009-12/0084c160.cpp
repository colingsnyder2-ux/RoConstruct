// roc 2009-12 0084c160  unit: CXTPDrawHelpers  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084c160
//
// 0084c160  56                   push esi
// 0084c161  8b742408             mov esi, dword ptr [esp + 8]
// 0084c165  85f6                 test esi, esi
// 0084c167  7441                 je 0x84c1aa
// 0084c169  837e2000             cmp dword ptr [esi + 0x20], 0
// 0084c16d  743b                 je 0x84c1aa
// 0084c16f  57                   push edi
// 0084c170  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0084c174  833f25               cmp dword ptr [edi], 0x25
// 0084c177  7517                 jne 0x84c190
// 0084c179  8bce                 mov ecx, esi
// 0084c17b  e8f8a20d00           call 0x926478
// 0084c180  a900004000           test eax, 0x400000
// 0084c185  7409                 je 0x84c190
// 0084c187  c70727000000         mov dword ptr [edi], 0x27
// 0084c18d  5f                   pop edi
// 0084c18e  5e                   pop esi
// 0084c18f  c3                   ret 
// 0084c190  833f27               cmp dword ptr [edi], 0x27
// 0084c193  7514                 jne 0x84c1a9
// 0084c195  8bce                 mov ecx, esi
// 0084c197  e8dca20d00           call 0x926478
// 0084c19c  a900004000           test eax, 0x400000
// 0084c1a1  7406                 je 0x84c1a9
// 0084c1a3  c70725000000         mov dword ptr [edi], 0x25
// 0084c1a9  5f                   pop edi
// 0084c1aa  5e                   pop esi
// 0084c1ab  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00000b@ns_ROCX00000b@ns_ROCX000022@@YAXPAUCXTPDrawHelpers@12@PAH@Z)

namespace ns_ROCX00000b {
struct S_func_00666490 {
    char pad0[48];
    int m_x;
    void f();
};
void S_func_00666490::f()
{
    m_x = (int)1;
}
}
