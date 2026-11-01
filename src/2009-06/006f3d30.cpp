// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class A { public: virtual ~A(); };
class B { public: virtual void b0(); };
class Base : public A, public B {
public:
	Base(int x, int y);
	virtual ~Base();
	void setFlag(bool f);
};
class Derived : public Base {
public:
	Derived(int x, int y);
	virtual void b0();
};
Derived::Derived(int x, int y) : Base(x, y)
{
	setFlag(true);
}
