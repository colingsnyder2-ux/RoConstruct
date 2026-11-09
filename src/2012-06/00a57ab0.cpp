// roc 2012-06 00a57ab0  unit: VCEdit::?$CXTMaskEditT  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a57ab0
//
// 00a57ab0  c701f838c200         mov dword ptr [ecx], 0xc238f8
// 00a57ab6  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a57ab9  85c9                 test ecx, ecx
// 00a57abb  7407                 je 0xa57ac4
// 00a57abd  51                   push ecx
// 00a57abe  e8f7a8f2ff           call 0x9823ba
// 00a57ac3  59                   pop ecx
// 00a57ac4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a57ab0(void*);
struct S_func_00a57ab0 {
    virtual ~S_func_00a57ab0();
    void* m_p;
};
S_func_00a57ab0::~S_func_00a57ab0()
{
    if (m_p)
        G1_func_00a57ab0(m_p);
}
