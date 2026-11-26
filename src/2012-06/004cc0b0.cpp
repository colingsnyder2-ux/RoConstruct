// from server: 100% by Xemicl
// roc 2012-06 004cc0b0  unit: Ogre::RbxSceneManagerFactory  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004cc0b0
//
// 004cc0b0  8b442404             mov eax, dword ptr [esp + 4]
// 004cc0b4  83e800               sub eax, 0
// 004cc0b7  740e                 je 0x4cc0c7
// 004cc0b9  83e802               sub eax, 2
// 004cc0bc  7514                 jne 0x4cc0d2
// 004cc0be  c70102000000         mov dword ptr [ecx], 2
// 004cc0c4  c20400               ret 4
// 004cc0c7  833901               cmp dword ptr [ecx], 1
// 004cc0ca  7506                 jne 0x4cc0d2
// 004cc0cc  c70100000000         mov dword ptr [ecx], 0
// 004cc0d2  c20400               ret 4
// copied from an identical function in another client (function ?f@C@@QAEXH@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct C { int state; void f(int e); };
void C::f(int e)
{
    switch (e) {
    case 0: if (state == 1) state = 0; break;
    case 2: state = 2; break;
    }
}