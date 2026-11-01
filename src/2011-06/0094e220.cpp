// from server: 100% by auto
// roc 2011-06 0094e220  unit: RBX::MeshFileKey  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0094e220
//
// 0094e220  51                   push ecx
// 0094e221  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0094e225  56                   push esi
// 0094e226  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0094e22a  56                   push esi
// 0094e22b  c744240800000000     mov dword ptr [esp + 8], 0
// 0094e233  e818feffff           call 0x94e050
// 0094e238  8bc6                 mov eax, esi
// 0094e23a  5e                   pop esi
// 0094e23b  59                   pop ecx
// 0094e23c  c20800               ret 8
// library ogre-1.6.4/OgreBorderPanelOverlayElement.cpp (function ?doGet@CmdBorderBottomLeftUV@BorderPanelOverlayElement@Ogre@@UBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBorderPanelOverlayElement.cpp
