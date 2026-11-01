// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct Workspace;
struct A12 { int a, b, c; };
struct B18 { int x[6]; ~B18(); };
class INamed { public: virtual const char* name() const = 0; };
class IRenderable { public: virtual void render() = 0; };
class MouseCommand : public INamed, public IRenderable { public: int pad[5]; };
class GroupDragTool : public MouseCommand {
public:
    GroupDragTool(Workspace* w, const A12& a, const B18& b, int d);
    virtual void render();
};
extern char* sGroupDropTool;
template<class Base, char** N> class Named : public Base {
public:
    Named(Workspace* w, A12 a, B18 b, int d) : Base(w, a, b, d) {}
    virtual const char* name() const { return *N; }
};
template class Named<GroupDragTool, &sGroupDropTool>;
}
