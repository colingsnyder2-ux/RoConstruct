// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct A { virtual ~A(); };
struct B { virtual void b(); char pad[0x3c]; };
struct C { virtual void c(); };
struct Base : public A, public B, public C
{
	virtual ~Base();
};
struct Tool : public Base
{
	virtual ~Tool();
};
Tool::~Tool()
{
}
