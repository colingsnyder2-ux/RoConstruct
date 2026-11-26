// from server: 100% by Xemicl
// roc 2012-06 006f8030  unit: RBX::TrackCameraCommand  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f8030
//
// 006f8030  8b442404             mov eax, dword ptr [esp + 4]
// 006f8034  56                   push esi
// 006f8035  50                   push eax
// 006f8036  83ec1c               sub esp, 0x1c
// 006f8039  8bf1                 mov esi, ecx
// 006f803b  8bcc                 mov ecx, esp
// 006f803d  89642428             mov dword ptr [esp + 0x28], esp
// 006f8041  687ceab500           push 0xb5ea7c
// 006f8046  ff154826b200         call dword ptr [0xb22648]
// 006f804c  8bce                 mov ecx, esi
// 006f804e  e8bdf7ffff           call 0x6f7810
// 006f8053  c70624c8b900         mov dword ptr [esi], 0xb9c824
// 006f8059  8bc6                 mov eax, esi
// 006f805b  5e                   pop esi
// 006f805c  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("WatchCamera",p){}