// roc 2012-06 00a70830  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a70830
//
// 00a70830  56                   push esi
// 00a70831  6a00                 push 0
// 00a70833  8bf1                 mov esi, ecx
// 00a70835  e8a6ffffff           call 0xa707e0
// 00a7083a  a900000001           test eax, 0x1000000
// 00a7083f  7414                 je 0xa70855
// 00a70841  6a01                 push 1
// 00a70843  8bce                 mov ecx, esi
// 00a70845  e896ffffff           call 0xa707e0
// 00a7084a  a840                 test al, 0x40
// 00a7084c  7407                 je 0xa70855
// 00a7084e  b801000000           mov eax, 1
// 00a70853  5e                   pop esi
// 00a70854  c3                   ret 
// 00a70855  33c0                 xor eax, eax
// 00a70857  5e                   pop esi
// 00a70858  c3                   ret 
// copied from an identical function in another client (function ?IsSomething@CXTPRibbonTabContextHeader@ns_ROCX00000b@@QAEHXZ)

namespace ns_ROCX00000b {
struct CXTPRibbonTabContextHeader
{
    int GetFlag(int index);
    int IsSomething();
};

int CXTPRibbonTabContextHeader::IsSomething()
{
    if ((GetFlag(0) & 0x1000000) != 0)
    {
        if ((GetFlag(1) & 0x40) != 0)
            return 1;
    }
    return 0;
}
}
