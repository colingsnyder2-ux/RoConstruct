// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void __cdecl operator delete(void*) throw();
struct Holder2009 {
	void* p;
	~Holder2009() { operator delete(p); }
};
struct Vec2009 {
	void* first;
	void* last;
	void* end;
	~Vec2009() { if (first) operator delete(first); first = 0; last = 0; end = 0; }
};
struct Arr2009 {
	void* h;
	int a, b;
	void* first;
	void* last;
	void* end;
	~Arr2009() { if (first) operator delete(first); first = 0; last = 0; end = 0; operator delete(h); }
};
struct Elem2009 {
	char pad[0x34];
	~Elem2009() throw();
};
extern int count2009;
class Base2009 {
public:
	virtual ~Base2009() {}
};
class Obj2009 : public Base2009 {
public:
	int x;
	Elem2009 e0, e1, e2;
	Arr2009 arr;
	virtual ~Obj2009();
};
Obj2009::~Obj2009() { --count2009; }
