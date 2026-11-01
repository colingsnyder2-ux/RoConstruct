// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct SV { SV(); float x, y, z; int i; };
struct Y { SV m; Y(const SV& s); };
Y::Y(const SV& s) { m = s; }
