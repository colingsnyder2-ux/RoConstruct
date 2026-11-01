// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Workspace;
class INamed { public: virtual const char* name() const; };
class IRenderable { public: virtual void render3dAdorn(void* adorn); };
class MouseCommand : public INamed, public IRenderable {
public:
	virtual ~MouseCommand();
	int a, b, c; bool d;
};
class ToolMouseCommand : public MouseCommand {
public:
	ToolMouseCommand(Workspace* workspace);
	Workspace* workspace;
};
class CloneTool : public ToolMouseCommand {
public:
	CloneTool(Workspace* workspace) : ToolMouseCommand(workspace) {}
	virtual ~CloneTool();
	struct P { void* p; P() : p(0) {} } first;
	P second;
};
class CloneVerb {
	char pad[0x18];
	Workspace* workspace;
public:
	MouseCommand* createTool();
};
MouseCommand* CloneVerb::createTool()
{
	return new CloneTool(workspace);
}
}
