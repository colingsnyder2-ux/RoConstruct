// from server: 100% by auto
// roc 2009-12 0049a940  unit: RBX::MeshFileKey  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0049a940
//
// 0049a940  51                   push ecx
// 0049a941  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0049a945  56                   push esi
// 0049a946  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0049a94a  56                   push esi
// 0049a94b  c744240800000000     mov dword ptr [esp + 8], 0
// 0049a953  e8f8fcffff           call 0x49a650
// 0049a958  8bc6                 mov eax, esi
// 0049a95a  5e                   pop esi
// 0049a95b  59                   pop ecx
// 0049a95c  c20800               ret 8
// library ogre-1.6.4/OgreBorderPanelOverlayElement.cpp (function ?doGet@CmdBorderBottomLeftUV@BorderPanelOverlayElement@Ogre@@UBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBorderPanelOverlayElement.cpp
