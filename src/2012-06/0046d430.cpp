// from server: 100% by Xemicl
// roc 2012-06 0046d430  unit: CRobloxApp  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046d430
//
// 0046d430  6aff                 push -1
// 0046d432  68dbfea900           push 0xa9fedb
// 0046d437  64a100000000         mov eax, dword ptr fs:[0]
// 0046d43d  50                   push eax
// 0046d43e  64892500000000       mov dword ptr fs:[0], esp
// 0046d445  81ec30010000         sub esp, 0x130
// 0046d44b  6a00                 push 0
// 0046d44d  8d4c2404             lea ecx, [esp + 4]
// 0046d451  e84a40f9ff           call 0x4014a0
// 0046d456  8d0c24               lea ecx, [esp]
// 0046d459  c784243801000000000000 mov dword ptr [esp + 0x138], 0
// 0046d464  e8794e5100           call 0x9822e2
// 0046d469  8d0c24               lea ecx, [esp]
// 0046d46c  c7842438010000ffffffff mov dword ptr [esp + 0x138], 0xffffffff
// 0046d477  e8243cf9ff           call 0x4010a0
// 0046d47c  8b8c2430010000       mov ecx, dword ptr [esp + 0x130]
// 0046d483  64890d00000000       mov dword ptr fs:[0], ecx
// 0046d48a  81c43c010000         add esp, 0x13c
// 0046d490  c3                   ret 
// copied from an identical function in another client (function ?OnAppAbout@CIDEDocManager@ns_ROCX000000@@QAEXXZ)

namespace ns_ROCX000000 {
struct Dialog {
    char storage[0x12c];

    Dialog(void* parent);
    virtual ~Dialog();
    virtual int DoModal();
};

struct CIDEDocManager {
    void OnAppAbout();
};

void CIDEDocManager::OnAppAbout()
{
    Dialog dialog(0);
    dialog.DoModal();
}
}