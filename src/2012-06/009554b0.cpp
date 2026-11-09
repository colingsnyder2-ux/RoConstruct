// roc 2012-06 009554b0  unit: RBX::SpatialFilter  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009554b0
//
// 009554b0  d9442404             fld dword ptr [esp + 4]
// 009554b4  d80d1ce6b600         fmul dword ptr [0xb6e61c]
// 009554ba  c3                   ret 
// copied from an identical function in another client (function ?scaleBy20@RBX@@YAMM@Z)

// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX {
float scaleBy20(float x) { return x * 20.0f; }
}