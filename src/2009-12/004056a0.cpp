// from server: 100% by colin
// roc 2009-12 004056a0  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004056a0
//
// 004056a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004056a4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004056a8  8b542404             mov edx, dword ptr [esp + 4]
// 004056ac  50                   push eax
// 004056ad  51                   push ecx
// 004056ae  684cfa9900           push 0x99fa4c
// 004056b3  52                   push edx
// 004056b4  e8a7feffff           call 0x405560
// 004056b9  c20c00               ret 0xc
// copied from an identical function in another client (function ?sub_404880@ns_ROCX000009@@YGHHHH@Z)

namespace ns_ROCX000009 {
extern "C" int __stdcall sub_4022a0(int, void*, int, int);

extern int G_784f68;

int __stdcall sub_404880(int a1, int a2, int a3)
{
    return sub_4022a0(a1, &G_784f68, a2, a3);
}
}
