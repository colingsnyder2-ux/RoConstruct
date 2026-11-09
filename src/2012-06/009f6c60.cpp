// roc 2012-06 009f6c60  unit: CXTCaption  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f6c60
//
// 009f6c60  56                   push esi
// 009f6c61  8bf1                 mov esi, ecx
// 009f6c63  e838fe0600           call 0xa66aa0
// 009f6c68  8b4c2408             mov ecx, dword ptr [esp + 8]
// 009f6c6c  8b10                 mov edx, dword ptr [eax]
// 009f6c6e  8b5214               mov edx, dword ptr [edx + 0x14]
// 009f6c71  56                   push esi
// 009f6c72  51                   push ecx
// 009f6c73  8bc8                 mov ecx, eax
// 009f6c75  ffd2                 call edx
// 009f6c77  5e                   pop esi
// 009f6c78  c20400               ret 4
// copied from an identical function in another client (function ?method@CSelectionCaption@ns_ROCX000001@@QAEXH@Z)

namespace ns_ROCX000001 {
struct CSelectionCaption;

extern "C" void* __cdecl sub_710F90();

struct CInner {
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014(int, CSelectionCaption*);
};

struct CSelectionCaption {
    void method(int);
};

void CSelectionCaption::method(int arg) {
    CInner* p = (CInner*)sub_710F90();
    p->v014(arg, this);
}
}
