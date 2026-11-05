// roc 2012-06 00998110  unit: CXTPPropertyGridItemConstraint  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00998110
//
// 00998110  c701dce6c000         mov dword ptr [ecx], 0xc0e6dc
// 00998116  8b4904               mov ecx, dword ptr [ecx + 4]
// 00998119  85c9                 test ecx, ecx
// 0099811b  7407                 je 0x998124
// 0099811d  51                   push ecx
// 0099811e  e897a2feff           call 0x9823ba
// 00998123  59                   pop ecx
// 00998124  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00998110(void*);
struct S_func_00998110 {
    virtual ~S_func_00998110();
    void* m_p;
};
S_func_00998110::~S_func_00998110()
{
    if (m_p)
        G1_func_00998110(m_p);
}
