// from server: 100% by auto
// roc 2009-12 00516e60  unit: RBX::VInstance::?$NonFactoryProduct  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00516e60
//
// 00516e60  56                   push esi
// 00516e61  8b7110               mov esi, dword ptr [ecx + 0x10]
// 00516e64  85f6                 test esi, esi
// 00516e66  742b                 je 0x516e93
// 00516e68  8d4604               lea eax, [esi + 4]
// 00516e6b  83c9ff               or ecx, 0xffffffff
// 00516e6e  f00fc108             lock xadd dword ptr [eax], ecx
// 00516e72  751f                 jne 0x516e93
// 00516e74  8b16                 mov edx, dword ptr [esi]
// 00516e76  8b4204               mov eax, dword ptr [edx + 4]
// 00516e79  8bce                 mov ecx, esi
// 00516e7b  ffd0                 call eax
// 00516e7d  8d4e08               lea ecx, [esi + 8]
// 00516e80  83caff               or edx, 0xffffffff
// 00516e83  f00fc111             lock xadd dword ptr [ecx], edx
// 00516e87  750a                 jne 0x516e93
// 00516e89  8b06                 mov eax, dword ptr [esi]
// 00516e8b  8b5008               mov edx, dword ptr [eax + 8]
// 00516e8e  8bce                 mov ecx, esi
// 00516e90  5e                   pop esi
// 00516e91  ffe2                 jmp edx
// 00516e93  5e                   pop esi
// 00516e94  c3                   ret 
// library templates-boost-1_34_1/set_sp.cpp (function ??1_Node@?$_Tree_nod@V?$_Tset_traits@V?$shared_ptr@UT@@@boost@@U?$less@V?$shared_ptr@UT@@@boost@@@std@@V?$allocator@V?$shared_ptr@UT@@@boost@@@4@$0A@@std@@@std@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 set_sp.cpp
