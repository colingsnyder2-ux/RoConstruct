// from server: 100% by Xemicl
// roc 2012-06 006ff450  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006ff450
//
// 006ff450  8b442404             mov eax, dword ptr [esp + 4]
// 006ff454  8b00                 mov eax, dword ptr [eax]
// 006ff456  3d2ca4e200           cmp eax, 0xe2a42c
// 006ff45b  7409                 je 0x6ff466
// 006ff45d  89442404             mov dword ptr [esp + 4], eax
// 006ff461  e90affffff           jmp 0x6ff370
// 006ff466  c20400               ret 4
// copied from an identical function in another client (function ?check@ns_ROCX000011@@YGXPAPAX@Z)

namespace ns_ROCX000011 {
extern char sentinel;
extern void __stdcall forward(void *);

void __stdcall check(void **value)
{
    void *p = *value;
    if (p != &sentinel)
        forward(p);
}
}
