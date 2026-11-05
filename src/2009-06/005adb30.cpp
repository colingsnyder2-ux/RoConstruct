// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
namespace RBX {
struct Part3 { Part3(); ~Part3(); int d[3]; };
struct Pair { Part3 a; Part3 b; Pair(); };
Pair::Pair() {}
}
