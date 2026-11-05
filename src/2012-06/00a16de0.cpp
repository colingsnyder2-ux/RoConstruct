// roc 2012-06 00a16de0  unit: CXTPCommandBarAnimation::PAUCAnimateInfo::?$CArray  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a16de0
//
// 00a16de0  56                   push esi
// 00a16de1  8bf1                 mov esi, ecx
// 00a16de3  8b06                 mov eax, dword ptr [esi]
// 00a16de5  57                   push edi
// 00a16de6  8b3d7021b200         mov edi, dword ptr [0xb22170]
// 00a16dec  50                   push eax
// 00a16ded  ffd7                 call edi
// 00a16def  8b4e08               mov ecx, dword ptr [esi + 8]
// 00a16df2  51                   push ecx
// 00a16df3  ffd7                 call edi
// 00a16df5  5f                   pop edi
// 00a16df6  8d4e24               lea ecx, [esi + 0x24]
// 00a16df9  5e                   pop esi
// 00a16dfa  e911ffffff           jmp 0xa16d10
// copied from an identical function in another client (function ?Clear@CXTPCommandBarAnimation@ns_ROCX000002@@QAEXXZ)

namespace ns_ROCX000002 {
struct CXTPCommandBarAnimation {
    void* m_pAnimateInfo;
    void* m_pad0;
    void* m_pAnimateInfo2;
    char m_pad[0x18];
    void* m_pCommandBar;
    void Clear();
};

extern "C" int (__stdcall *g_pfnDeleteObject)(void*);

extern "C" void __fastcall sub_6c8fb0(void*);

void CXTPCommandBarAnimation::Clear()
{
    int (__stdcall *pfn)(void*) = g_pfnDeleteObject;
    pfn(m_pAnimateInfo);
    pfn(m_pAnimateInfo2);
    sub_6c8fb0((char*)this + 0x24);
}
}
