// from server: 100% by auto
// roc 2010-06 008edf70  unit: RBX::MeshFileKey  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008edf70
//
// 008edf70  51                   push ecx
// 008edf71  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008edf75  56                   push esi
// 008edf76  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008edf7a  56                   push esi
// 008edf7b  c744240800000000     mov dword ptr [esp + 8], 0
// 008edf83  e828feffff           call 0x8eddb0
// 008edf88  8bc6                 mov eax, esi
// 008edf8a  5e                   pop esi
// 008edf8b  59                   pop ecx
// 008edf8c  c20800               ret 8
// library ogre-1.6.4/OgreBorderPanelOverlayElement.cpp (function ?doGet@CmdBorderBottomLeftUV@BorderPanelOverlayElement@Ogre@@UBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBorderPanelOverlayElement.cpp
