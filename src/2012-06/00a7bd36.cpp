// from server: 100% by Xemicl
// roc 2012-06 00a7bd36  unit: CXTIconHandle  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7bd36
//
// 00a7bd36  8bff                 mov edi, edi
// 00a7bd38  55                   push ebp
// 00a7bd39  8bec                 mov ebp, esp
// 00a7bd3b  837d0800             cmp dword ptr [ebp + 8], 0
// 00a7bd3f  740e                 je 0xa7bd4f
// 00a7bd41  ff7508               push dword ptr [ebp + 8]
// 00a7bd44  6a00                 push 0
// 00a7bd46  ff7104               push dword ptr [ecx + 4]
// 00a7bd49  ff15a822b200         call dword ptr [0xb222a8]
// 00a7bd4f  5d                   pop ebp
// 00a7bd50  c20400               ret 4
// copied from an identical function in another client (function ?Free@CWin32Heap@ATL@@UAEXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlstr.obj