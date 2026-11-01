// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct Base { Base(); };
struct V16 { int a, b, c, d; };
struct Pair : Base {
	V16 first;
	V16 second;
	Pair(const V16& a, const V16& b);
};
Pair::Pair(const V16& a, const V16& b) : first(a), second(b) {}
