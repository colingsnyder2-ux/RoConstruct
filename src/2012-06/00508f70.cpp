// from server: 100% by Xemicl
// roc 2012-06 00508f70  unit: Ogre::RbxManualResourceLoaderChain  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00508f70
//
// 00508f70  56                   push esi
// 00508f71  8bf1                 mov esi, ecx
// 00508f73  8d4604               lea eax, [esi + 4]
// 00508f76  c706ecb8b600         mov dword ptr [esi], 0xb6b8ec
// 00508f7c  85c0                 test eax, eax
// 00508f7e  7405                 je 0x508f85
// 00508f80  8d48fc               lea ecx, [eax - 4]
// 00508f83  eb02                 jmp 0x508f87
// 00508f85  33c9                 xor ecx, ecx
// 00508f87  f644240801           test byte ptr [esp + 8], 1
// 00508f8c  8908                 mov dword ptr [eax], ecx
// 00508f8e  a19839b200           mov eax, dword ptr [0xb23998]
// 00508f93  8906                 mov dword ptr [esi], eax
// 00508f95  7409                 je 0x508fa0
// 00508f97  56                   push esi
// 00508f98  e877914700           call 0x982114
// 00508f9d  83c404               add esp, 4
// 00508fa0  8bc6                 mov eax, esi
// 00508fa2  5e                   pop esi
// 00508fa3  c20400               ret 4
// copied from an identical function in another client (function ??_GLoader@@UAEPAXI@Z)

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