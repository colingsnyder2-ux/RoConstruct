// from server: 100% by Xemicl
// roc 2012-06 00508f40  unit: Ogre::RbxSceneUpdater  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00508f40
//
// 00508f40  8d4104               lea eax, [ecx + 4]
// 00508f43  c701ecb8b600         mov dword ptr [ecx], 0xb6b8ec
// 00508f49  85c0                 test eax, eax
// 00508f4b  740d                 je 0x508f5a
// 00508f4d  8d50fc               lea edx, [eax - 4]
// 00508f50  8910                 mov dword ptr [eax], edx
// 00508f52  a19839b200           mov eax, dword ptr [0xb23998]
// 00508f57  8901                 mov dword ptr [ecx], eax
// 00508f59  c3                   ret 
// 00508f5a  33d2                 xor edx, edx
// 00508f5c  8910                 mov dword ptr [eax], edx
// 00508f5e  8b159839b200         mov edx, dword ptr [0xb23998]
// 00508f64  8911                 mov dword ptr [ecx], edx
// 00508f66  c3                   ret 
// copied from an identical function in another client (function ??1Loader@@UAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace Ogre {
class Resource;
class __declspec(dllimport) ManualResourceLoader { public: ManualResourceLoader() {} virtual ~ManualResourceLoader() {} virtual void loadResource(Resource*) = 0; };
}
struct B2 { void* p; };
class Loader : public Ogre::ManualResourceLoader, public B2 { public: ~Loader(); void loadResource(Ogre::Resource*); };
Loader::~Loader() { B2* b = this; b->p = static_cast<Loader*>(b); }