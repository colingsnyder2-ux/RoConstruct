// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Workspace;
class B0 { public: virtual void a0(); };
class B1 { public: virtual void b0(); };
class GameTool : public B0, public B1 {
public:
	GameTool(Workspace* w);
	char gpad[0x74 - 8];
};
class Tool2009 : public GameTool {
public:
	Tool2009(Workspace* w) : GameTool(w) {}
	virtual void a0();
	virtual void b0();
};
class Verb2009 {
public:
	char vpad[0x18];
	Workspace* workspace;
	GameTool* create();
};
GameTool* Verb2009::create() { return new Tool2009(workspace); }
}
