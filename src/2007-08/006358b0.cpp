// from server: 63% by colin
// roc 2007-08 006358b0  unit: MyXTPCommandBars  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006358b0
//
// 006358b0  0000                 add byte ptr [eax], al
// 006358b2  005368               add byte ptr [ebx + 0x68], dl
// 006358b5  c0527c00             rcl byte ptr [edx + 0x7c], 0
// 006358b9  56                   push esi
// 006358ba  e861fe0400           call 0x685720
// 006358bf  83c420               add esp, 0x20
// 006358c2  837e2400             cmp dword ptr [esi + 0x24], 0
// 006358c6  740a                 je 0x6358d2
// 006358c8  8b13                 mov edx, dword ptr [ebx]
// 006358ca  52                   push edx
// 006358cb  8bcf                 mov ecx, edi
// 006358cd  e88ec2ffff           call 0x631b60
// 006358d2  5f                   pop edi
// 006358d3  5e                   pop esi
// 006358d4  5d                   pop ebp
// 006358d5  5b                   pop ebx
// 006358d6  59                   pop ecx
// 006358d7  c20800               ret 8
// library xtp-11.2.2-vc8/Source\CommandBars\XTPCommandBars.cpp (function ?OnUpdateCmdUI@MyXTPCommandBars@@...)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-11.2.2-vc8 Source/CommandBars/XTPCommandBars.cpp

extern "C" void __stdcall sub_685720();
extern "C" void __stdcall sub_631b60();

struct MyXTPCommandBars {
    void OnUpdateCmdUI(int, int);
};

void MyXTPCommandBars::OnUpdateCmdUI(int a, int b) {
    sub_685720();
    if (*(int*)((char*)this + 0x24) != 0) {
        sub_631b60();
    }
}
