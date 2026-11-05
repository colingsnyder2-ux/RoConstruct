// roc 2012-06 009e76b0  unit: CXTPStatusBar  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e76b0
//
// 009e76b0  e8dbf9ffff           call 0x9e7090
// 009e76b5  85c0                 test eax, eax
// 009e76b7  7503                 jne 0x9e76bc
// 009e76b9  c20800               ret 8
// 009e76bc  8b4068               mov eax, dword ptr [eax + 0x68]
// 009e76bf  c20800               ret 8
// copied from an identical function in another client (function ?GetValue@CXTPStatusBar@ns_ROCX000002@@QAEHHH@Z)

namespace ns_ROCX000002 {
struct CXTPStatusBar;

struct Helper
{
    CXTPStatusBar* GetStatusBar();
};

struct CXTPStatusBar
{
    char pad[0x68];
    int value;
    int GetValue(int a, int b);
};

int CXTPStatusBar::GetValue(int a, int b)
{
    Helper* h = (Helper*)this;
    CXTPStatusBar* p = h->GetStatusBar();
    if (p == 0)
        return 0;
    return p->value;
}
}
