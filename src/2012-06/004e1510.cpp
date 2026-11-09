// from server: 100% by auto
// roc 2012-06 004e1510  unit: Ogre::RbxTextureCompositorSceneManager  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004e1510
//
// 004e1510  6aff                 push -1
// 004e1512  681890ad00           push 0xad9018
// 004e1517  64a100000000         mov eax, dword ptr fs:[0]
// 004e151d  50                   push eax
// 004e151e  64892500000000       mov dword ptr fs:[0], esp
// 004e1525  51                   push ecx
// 004e1526  56                   push esi
// 004e1527  8bf1                 mov esi, ecx
// 004e1529  89742404             mov dword ptr [esp + 4], esi
// 004e152d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004e1535  e856fdffff           call 0x4e1290
// 004e153a  8b06                 mov eax, dword ptr [esi]
// 004e153c  50                   push eax
// 004e153d  e8d20b4a00           call 0x982114
// 004e1542  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004e1546  83c404               add esp, 4
// 004e1549  5e                   pop esi
// 004e154a  64890d00000000       mov dword ptr fs:[0], ecx
// 004e1551  83c410               add esp, 0x10
// 004e1554  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
