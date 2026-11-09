// roc 2009-12 0086d5e0  unit: CXTCaption  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086d5e0
//
// 0086d5e0  53                   push ebx
// 0086d5e1  55                   push ebp
// 0086d5e2  56                   push esi
// 0086d5e3  57                   push edi
// 0086d5e4  8bf9                 mov edi, ecx
// 0086d5e6  e88582c6ff           call 0x4d5870
// 0086d5eb  8bd8                 mov ebx, eax
// 0086d5ed  33f6                 xor esi, esi
// 0086d5ef  85db                 test ebx, ebx
// 0086d5f1  7e15                 jle 0x86d608
// 0086d5f3  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0086d5f7  56                   push esi
// 0086d5f8  8bcf                 mov ecx, edi
// 0086d5fa  e8b1ffffff           call 0x86d5b0
// 0086d5ff  3bc5                 cmp eax, ebp
// 0086d601  740f                 je 0x86d612
// 0086d603  46                   inc esi
// 0086d604  3bf3                 cmp esi, ebx
// 0086d606  7cef                 jl 0x86d5f7
// 0086d608  5f                   pop edi
// 0086d609  5e                   pop esi
// 0086d60a  5d                   pop ebp
// 0086d60b  83c8ff               or eax, 0xffffffff
// 0086d60e  5b                   pop ebx
// 0086d60f  c20400               ret 4
// 0086d612  5f                   pop edi
// 0086d613  8bc6                 mov eax, esi
// 0086d615  5e                   pop esi
// 0086d616  5d                   pop ebp
// 0086d617  5b                   pop ebx
// 0086d618  c20400               ret 4
// copied from an identical function in another client (function ?Find@CXTPReportRow_Batch@ns_ROCX00001f@@QAEHH@Z)

namespace ns_ROCX00001f {
struct CXTPReportRow_Batch {
    int GetCount();
    int FindRow(int row);
    int Find(int row);
};

int CXTPReportRow_Batch::Find(int row)
{
    int count = GetCount();
    int i = 0;
    if (count > 0) {
        do {
            if (FindRow(i) == row)
                return i;
            ++i;
        } while (i < count);
    }
    return -1;
}
}
