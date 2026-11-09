// roc 2009-12 008b4a80  unit: CXTPDockingPaneSplitterContainer  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b4a80
//
// 008b4a80  56                   push esi
// 008b4a81  8b742408             mov esi, dword ptr [esp + 8]
// 008b4a85  57                   push edi
// 008b4a86  8bf9                 mov edi, ecx
// 008b4a88  85f6                 test esi, esi
// 008b4a8a  750f                 jne 0x8b4a9b
// 008b4a8c  8b442410             mov eax, dword ptr [esp + 0x10]
// 008b4a90  50                   push eax
// 008b4a91  e8fa3dffff           call 0x8a8890
// 008b4a96  5f                   pop edi
// 008b4a97  5e                   pop esi
// 008b4a98  c20800               ret 8
// 008b4a9b  8b4e04               mov ecx, dword ptr [esi + 4]
// 008b4a9e  56                   push esi
// 008b4a9f  51                   push ecx
// 008b4aa0  8bcf                 mov ecx, edi
// 008b4aa2  e839e00000           call 0x8c2ae0
// 008b4aa7  8b542410             mov edx, dword ptr [esp + 0x10]
// 008b4aab  895008               mov dword ptr [eax + 8], edx
// 008b4aae  8b4e04               mov ecx, dword ptr [esi + 4]
// 008b4ab1  85c9                 test ecx, ecx
// 008b4ab3  740a                 je 0x8b4abf
// 008b4ab5  8901                 mov dword ptr [ecx], eax
// 008b4ab7  5f                   pop edi
// 008b4ab8  894604               mov dword ptr [esi + 4], eax
// 008b4abb  5e                   pop esi
// 008b4abc  c20800               ret 8
// 008b4abf  894704               mov dword ptr [edi + 4], eax
// 008b4ac2  5f                   pop edi
// 008b4ac3  894604               mov dword ptr [esi + 4], eax
// 008b4ac6  5e                   pop esi
// 008b4ac7  c20800               ret 8
// copied from an identical function in another client (function ?AddPane@CXTPDockingPaneSplitterContainer@ns_ROCX000001@ns_ROCX000008@@QAEXPAXH@Z)

namespace ns_ROCX000001 {
namespace ns_ROCX000008 {
struct CObj {
    char pad[0xe8];
    int m_flag;
};

struct CXTPDockingPane {
    int m_unused[6];
    int m_kind;
    CObj* GetRelated();

    int IsActive();
};

int CXTPDockingPane::IsActive() {
    if (m_kind == 4) {
        CObj* p = GetRelated();
        if (p->m_flag != 0)
            return 1;
    }
    return 0;
}
}
}
