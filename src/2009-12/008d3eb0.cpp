// from server: 100% by auto
// roc 2009-12 008d3eb0  unit: CXTPTabPaintManager  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d3eb0
//
// 008d3eb0  8b442418             mov eax, dword ptr [esp + 0x18]
// 008d3eb4  83f803               cmp eax, 3
// 008d3eb7  0f8786000000         ja 0x8d3f43
// 008d3ebd  ff2485443f8d00       jmp dword ptr [eax*4 + 0x8d3f44]
// 008d3ec4  8b442404             mov eax, dword ptr [esp + 4]
// 008d3ec8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d3ecc  8b542408             mov edx, dword ptr [esp + 8]
// 008d3ed0  294804               sub dword ptr [eax + 4], ecx
// 008d3ed3  2910                 sub dword ptr [eax], edx
// 008d3ed5  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d3ed9  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d3edd  01480c               add dword ptr [eax + 0xc], ecx
// 008d3ee0  015008               add dword ptr [eax + 8], edx
// 008d3ee3  c3                   ret 
// 008d3ee4  8b442404             mov eax, dword ptr [esp + 4]
// 008d3ee8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d3eec  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d3ef0  2908                 sub dword ptr [eax], ecx
// 008d3ef2  01500c               add dword ptr [eax + 0xc], edx
// 008d3ef5  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d3ef9  8b542408             mov edx, dword ptr [esp + 8]
// 008d3efd  014808               add dword ptr [eax + 8], ecx
// 008d3f00  295004               sub dword ptr [eax + 4], edx
// 008d3f03  c3                   ret 
// 008d3f04  8b442404             mov eax, dword ptr [esp + 4]
// 008d3f08  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d3f0c  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d3f10  01480c               add dword ptr [eax + 0xc], ecx
// 008d3f13  015008               add dword ptr [eax + 8], edx
// 008d3f16  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d3f1a  8b542408             mov edx, dword ptr [esp + 8]
// 008d3f1e  294804               sub dword ptr [eax + 4], ecx
// 008d3f21  2910                 sub dword ptr [eax], edx
// 008d3f23  c3                   ret 
// 008d3f24  8b442404             mov eax, dword ptr [esp + 4]
// 008d3f28  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d3f2c  8b542408             mov edx, dword ptr [esp + 8]
// 008d3f30  014808               add dword ptr [eax + 8], ecx
// 008d3f33  295004               sub dword ptr [eax + 4], edx
// 008d3f36  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d3f3a  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d3f3e  2908                 sub dword ptr [eax], ecx
// 008d3f40  01500c               add dword ptr [eax + 0xc], edx
// 008d3f43  c3                   ret 
// 008d3f44  c43e                 les edi, ptr [esi]
// 008d3f46  8d00                 lea eax, [eax]
// 008d3f48  e43e                 in al, 0x3e
// 008d3f4a  8d00                 lea eax, [eax]
// 008d3f4c  043f                 add al, 0x3f
// 008d3f4e  8d00                 lea eax, [eax]
// 008d3f50  243f                 and al, 0x3f
// 008d3f52  8d00                 lea eax, [eax]
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?InflateRectEx@CXTPTabPaintManagerAppearanceSet@@SAXAAVCRect@@V2@W4XTPTabPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
