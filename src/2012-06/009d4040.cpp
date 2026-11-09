// roc 2012-06 009d4040  unit: CXTPControlSelector  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d4040
//
// 009d4040  56                   push esi
// 009d4041  8bf1                 mov esi, ecx
// 009d4043  8b4e04               mov ecx, dword ptr [esi + 4]
// 009d4046  85c9                 test ecx, ecx
// 009d4048  741a                 je 0x9d4064
// 009d404a  8b442408             mov eax, dword ptr [esp + 8]
// 009d404e  83f8ff               cmp eax, -1
// 009d4051  7411                 je 0x9d4064
// 009d4053  8b11                 mov edx, dword ptr [ecx]
// 009d4055  50                   push eax
// 009d4056  8b4238               mov eax, dword ptr [edx + 0x38]
// 009d4059  ffd0                 call eax
// 009d405b  837e0cff             cmp dword ptr [esi + 0xc], -1
// 009d405f  7503                 jne 0x9d4064
// 009d4061  89460c               mov dword ptr [esi + 0xc], eax
// 009d4064  5e                   pop esi
// 009d4065  c20400               ret 4
// copied from an identical function in another client (function ?SetValue@CXTPControlSelector@ns_ROCX00004a@@QAEXH@Z)

namespace ns_ROCX00004a {
struct CXTPControlSelector {
    int unknown0;
    void* unknown4;
    int unknown8;
    int unknownC;
    void SetValue(int nValue);
};

void CXTPControlSelector::SetValue(int nValue) {
    if (unknown4 != 0 && nValue != -1) {
        int result = (*(int (__thiscall**)(void*, int))(*(int*)unknown4 + 0x38))(unknown4, nValue);
        if (unknownC == -1) {
            unknownC = result;
        }
    }
}
}
