// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Workspace;
class B0 { public: virtual void a0(); };
class B1 { public: virtual void b0(); };
class PartTool : public B0, public B1 {
public:
	PartTool(Workspace* w);
	char gpad[0x24 - 8];
};
class Tool2009 : public PartTool {
public:
	Tool2009(Workspace* w) : PartTool(w) {}
	virtual void a0();
	virtual void b0();
};
class Verb2009 {
public:
	char vpad[0x18];
	Workspace* workspace;
	PartTool* create();
};
PartTool* Verb2009::create() { return new Tool2009(workspace); }
}
