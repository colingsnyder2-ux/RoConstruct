// roc 2012-06 009d4010  unit: CXTPControlSelector  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d4010
//
// 009d4010  56                   push esi
// 009d4011  8bf1                 mov esi, ecx
// 009d4013  8b4e04               mov ecx, dword ptr [esi + 4]
// 009d4016  85c9                 test ecx, ecx
// 009d4018  741d                 je 0x9d4037
// 009d401a  8b442408             mov eax, dword ptr [esp + 8]
// 009d401e  85c0                 test eax, eax
// 009d4020  7415                 je 0x9d4037
// 009d4022  8b11                 mov edx, dword ptr [ecx]
// 009d4024  50                   push eax
// 009d4025  8b4230               mov eax, dword ptr [edx + 0x30]
// 009d4028  ffd0                 call eax
// 009d402a  837e0800             cmp dword ptr [esi + 8], 0
// 009d402e  7507                 jne 0x9d4037
// 009d4030  85c0                 test eax, eax
// 009d4032  7403                 je 0x9d4037
// 009d4034  894608               mov dword ptr [esi + 8], eax
// 009d4037  5e                   pop esi
// 009d4038  c20400               ret 4
// copied from an identical function in another client (function ?Set@CXTPControlSelector@ns_ROCX000049@@QAEXPAX@Z)

namespace ns_ROCX000049 {
struct CXTPControlSelector {
    int m_nUnknown0;
    void* m_pUnknown4;
    void* m_pUnknown8;
    void Set(void* p);
};

void CXTPControlSelector::Set(void* p)
{
    if (m_pUnknown4 != 0 && p != 0) {
        void* result = ((void* (__thiscall*)(void*, void*))((*(void***)m_pUnknown4)[0x30 / 4]))(m_pUnknown4, p);
        if (m_pUnknown8 == 0 && result != 0) {
            m_pUnknown8 = result;
        }
    }
}
}
