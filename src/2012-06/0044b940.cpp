// from server: 100% by Xemicl
// roc 2012-06 0044b940  unit: CDeclarationView  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044b940
//
// 0044b940  8b89b0000000         mov ecx, dword ptr [ecx + 0xb0]
// 0044b946  85c9                 test ecx, ecx
// 0044b948  741a                 je 0x44b964
// 0044b94a  8b442404             mov eax, dword ptr [esp + 4]
// 0044b94e  8b505c               mov edx, dword ptr [eax + 0x5c]
// 0044b951  52                   push edx
// 0044b952  e8c9f9ffff           call 0x44b320
// 0044b957  8b442408             mov eax, dword ptr [esp + 8]
// 0044b95b  c70000000000         mov dword ptr [eax], 0
// 0044b961  c20800               ret 8
// 0044b964  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044b968  c70100000000         mov dword ptr [ecx], 0
// 0044b96e  c20800               ret 8
// copied from an identical function in another client (function ?f@CDeclarationView@ns_ROCX000007@@QAEXPAXPAPAX@Z)

namespace ns_ROCX000007 {
// from server: 100% by atomic.potato
struct CDeclarationView
{
    char padding[0xb0];
    void *fieldB0;
    void f(void *, void **);
};

struct Helper
{
    void f(void *);
};

void CDeclarationView::f(void *arg1, void **arg2)
{
    if (fieldB0 != 0)
        ((Helper *)fieldB0)->f(*(void **)((char *)arg1 + 0x5c));
    *arg2 = 0;
}
}