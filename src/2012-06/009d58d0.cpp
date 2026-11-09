// roc 2012-06 009d58d0  unit: CXTPBitmapDC  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d58d0
//
// 009d58d0  8b442404             mov eax, dword ptr [esp + 4]
// 009d58d4  56                   push esi
// 009d58d5  8bf1                 mov esi, ecx
// 009d58d7  8d4e08               lea ecx, [esi + 8]
// 009d58da  51                   push ecx
// 009d58db  894604               mov dword ptr [esi + 4], eax
// 009d58de  ff15903ab200         call dword ptr [0xb23a90]
// 009d58e4  c70600000000         mov dword ptr [esi], 0
// 009d58ea  8bc6                 mov eax, esi
// 009d58ec  5e                   pop esi
// 009d58ed  c20400               ret 4
// copied from an identical function in another client (function ?Init@CXTPBitmapDC@ns_ROCX000064@@QAEPAU12@H@Z)

namespace ns_ROCX000064 {
struct CXTPBitmapDC {
    int m_nType;
    int m_hBitmap;
    int m_rect[4];
    CXTPBitmapDC* Init(int hBitmap);
};

extern "C" int (__stdcall *SetRectEmpty)(int* rect);

CXTPBitmapDC* CXTPBitmapDC::Init(int hBitmap)
{
    m_hBitmap = hBitmap;
    SetRectEmpty(m_rect);
    m_nType = 0;
    return this;
}
}
