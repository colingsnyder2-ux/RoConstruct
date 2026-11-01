// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
class X
{
public:
	int f(int a, double d, int b);
	int g(int a);
};
int X::g(int a)
{
	return f(a, 0.0, 0);
}
