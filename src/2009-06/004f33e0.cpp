// from server: 90% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class __multiple_inheritance Target;
struct Arg { int a; };
struct Holder {
	void (Target::*pmf)(Arg*);
	Target* obj;
	int pad;
	Arg arg;
};
void invoke(Holder** h){ Holder* p=*h; ((*p).obj->*(*p).pmf)(&(*p).arg); }
