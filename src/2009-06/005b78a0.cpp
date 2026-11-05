// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
struct Tag {};
int g(int* a, int* b, Tag t);
int f(int* a, int* b)
{
	return g(a, b, Tag());
}
