// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct A;
struct B;
struct S {
	int pad0;
	int m4;
	static void helper(S* self, int* m, A* a, B* b);
	void f(A* a, B* b);
};
void S::f(A* a, B* b)
{
	helper(this, &m4, a, b);
}
