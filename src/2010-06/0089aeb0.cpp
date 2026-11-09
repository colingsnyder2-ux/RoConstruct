// from server: 100% by auto
// roc 2010-06 0089aeb0  unit: CXTCaptionPopupWnd  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089aeb0
//
// 0089aeb0  56                   push esi
// 0089aeb1  8bf1                 mov esi, ecx
// 0089aeb3  ff1580ba9e00         call dword ptr [0x9eba80]
// 0089aeb9  8d4e60               lea ecx, [esi + 0x60]
// 0089aebc  85c9                 test ecx, ecx
// 0089aebe  7403                 je 0x89aec3
// 0089aec0  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0089aec3  3bc1                 cmp eax, ecx
// 0089aec5  7460                 je 0x89af27
// 0089aec7  8d8ef0010000         lea ecx, [esi + 0x1f0]
// 0089aecd  85c9                 test ecx, ecx
// 0089aecf  7403                 je 0x89aed4
// 0089aed1  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0089aed4  3bc1                 cmp eax, ecx
// 0089aed6  744f                 je 0x89af27
// 0089aed8  85f6                 test esi, esi
// 0089aeda  7504                 jne 0x89aee0
// 0089aedc  33c9                 xor ecx, ecx
// 0089aede  eb03                 jmp 0x89aee3
// 0089aee0  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0089aee3  3bc1                 cmp eax, ecx
// 0089aee5  7440                 je 0x89af27
// 0089aee7  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 0089aeea  85c9                 test ecx, ecx
// 0089aeec  7403                 je 0x89aef1
// 0089aeee  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0089aef1  3bc1                 cmp eax, ecx
// 0089aef3  7432                 je 0x89af27
// 0089aef5  8b4654               mov eax, dword ptr [esi + 0x54]
// 0089aef8  85c0                 test eax, eax
// 0089aefa  7403                 je 0x89aeff
// 0089aefc  8b4020               mov eax, dword ptr [eax + 0x20]
// 0089aeff  50                   push eax
// 0089af00  ff1528bc9e00         call dword ptr [0x9ebc28]
// 0089af06  85c0                 test eax, eax
// 0089af08  741d                 je 0x89af27
// 0089af0a  8b4654               mov eax, dword ptr [esi + 0x54]
// 0089af0d  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0089af10  6a00                 push 0
// 0089af12  6a00                 push 0
// 0089af14  683f270000           push 0x273f
// 0089af19  51                   push ecx
// 0089af1a  ff1554ba9e00         call dword ptr [0x9eba54]
// 0089af20  b801000000           mov eax, 1
// 0089af25  5e                   pop esi
// 0089af26  c3                   ret 
// 0089af27  33c0                 xor eax, eax
// 0089af29  5e                   pop esi
// 0089af2a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?SendCancelMessage@CXTCaptionPopupWnd@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
