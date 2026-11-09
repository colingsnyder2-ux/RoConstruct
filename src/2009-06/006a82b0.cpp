// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Obj { int& index(); };
struct Arr {
	Obj** data; int num;
	Obj*& operator[](int i) { return data[i]; }
	int size() const { return num; }
	void resize(int n, bool shrinkIfNecessary);
};
class K { char pad[0xc]; Arr arr; public: void remove(Obj* x); };
void K::remove(Obj* x)
{
	Arr& a = arr;
	int i = x->index();
	Obj* last = a[a.size() - 1];
	a[i] = last;
	last->index() = i;
	a.resize(a.size() - 1, false);
	x->index() = -1;
}
