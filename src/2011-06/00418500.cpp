// from server: 100% by auto
// roc 2011-06 00418500  unit: RBX::Reflection::VValue::$$CBV?$vector::$$A6AXV?$shared_ptr::V?$function::V?$shared_ptr::?$holder  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00418500
//
// 00418500  56                   push esi
// 00418501  8bf1                 mov esi, ecx
// 00418503  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00418507  33c0                 xor eax, eax
// 00418509  51                   push ecx
// 0041850a  8bce                 mov ecx, esi
// 0041850c  668906               mov word ptr [esi], ax
// 0041850f  e8acfcffff           call 0x4181c0
// 00418514  8bc6                 mov eax, esi
// 00418516  5e                   pop esi
// 00418517  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
