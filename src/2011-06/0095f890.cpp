// from server: 100% by auto
// roc 2011-06 0095f890  unit: Ogre::RbxSceneUpdater  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0095f890
//
// 0095f890  56                   push esi
// 0095f891  8bf1                 mov esi, ecx
// 0095f893  e8e8feffff           call 0x95f780
// 0095f898  8b06                 mov eax, dword ptr [esi]
// 0095f89a  50                   push eax
// 0095f89b  e8b8a7eaff           call 0x80a058
// 0095f8a0  83c404               add esp, 4
// 0095f8a3  5e                   pop esi
// 0095f8a4  c3                   ret 
// standard library list<ptr> (function ??1?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
