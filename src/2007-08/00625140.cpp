// from server: 100% by colin
// roc 2007-08 00625140  unit: RBX::ArrowButton  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00625140
//
// 00625140  d9442404             fld dword ptr [esp + 4]
// 00625144  d80d00b57900         fmul dword ptr [0x79b500]
// 0062514a  c3                   ret 
// copied from an identical function in another client (function ?scaleBy20@RBX@@YAMM@Z)

// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX {
float scaleBy20(float x) { return x * 20.0f; }
}