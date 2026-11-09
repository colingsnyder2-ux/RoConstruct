// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct T;
struct Vec { void push_back(T* const& v); };
class X
{
	char pad[0x60];
	T* item;
public:
	void collect(Vec& v) const;
};
void X::collect(Vec& v) const
{
	T* p = item;
	v.push_back(p);
}
