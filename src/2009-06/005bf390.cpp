// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
class Base {
public:
	Base();
	virtual ~Base();
	int a, b;
};
class Member {
public:
	Member();
	~Member();
	void init();
	int x;
};
class Derived : public Base, public Member {
public:
	Derived();
};
Derived::Derived()
{
	init();
}
