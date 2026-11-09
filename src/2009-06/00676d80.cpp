// from server: 90% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class __declspec(novtable) IPipelined {
public:
	IPipelined() : stage(0) {}
	virtual ~IPipelined();
	int stage;
};
class IndexedMesh {
public:
	IndexedMesh();
	virtual ~IndexedMesh();
	char pad[0x24];
};
struct ListHook {
	void* next_;
	void* prev_;
	ListHook() : next_(0), prev_(0) {}
};
struct Triple {
	void* a; void* b; void* c;
	Triple() { b = 0; c = 0; a = 0; }
};
struct Range {
	int count; int lo; int hi;
	Range() { lo = -1; hi = -1; count = 0; }
};
class Assembly : public IPipelined, public IndexedMesh, public ListHook {
public:
	struct Hdr { bool flagA; bool flagB; void* p0; void* p1; Hdr() : flagA(false), flagB(false), p0(0), p1(0) {} } hdr;
	Triple t0;
	Triple t1;
	Range range;
	int unused68;
	bool enabled;
	Assembly* owner;
	int unused74;
	void (Assembly::*callback)();
	bool flagC;
	int unused84;
	float value;
	Assembly();
	void onStep();
	virtual ~Assembly();
};
Assembly::Assembly()
	: callback(&Assembly::onStep), flagC(false)
{
	enabled = true;
	owner = this;
	value = 0.0f;
}
}
