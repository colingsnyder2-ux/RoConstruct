// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
struct Inner { Inner(const Inner&); ~Inner(); char pad[0x18]; };
struct CountedBase { void* vptr; long use_count; long weak_count; };
struct SharedCount {
	CountedBase* pi;
	SharedCount(const SharedCount& o) : pi(o.pi) { if (pi) _InterlockedIncrement(&pi->use_count); }
	~SharedCount();
};
struct Ptr { void* px; SharedCount pn; };
struct Record {
	int kind;
	std::string name;
	Inner inner;
	Ptr ptr;
	Record(const Record& o);
};
Record::Record(const Record& o) : kind(o.kind), name(o.name), inner(o.inner), ptr(o.ptr) {}
