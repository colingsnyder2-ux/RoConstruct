// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: base QueuedRenderableVisitor is a dllimport class from rgmain.dll (its vtable is loaded via the import slot).
// INFERRED: derived dtor is trivial; the compiler-generated vector deleting dtor stores own vtable, then base vtable, then conditionally deletes.
namespace Ogre {

class Renderable;

class __declspec(dllimport) QueuedRenderableVisitor {
public:
    virtual ~QueuedRenderableVisitor() {}
    virtual void visit(Renderable *r, unsigned short group, bool onlyIfPassed) = 0;
};

class RbxSceneManager {
public:
    class SceneMgrQueuedRenderableVisitor : public QueuedRenderableVisitor {
    public:
        SceneMgrQueuedRenderableVisitor();
        virtual ~SceneMgrQueuedRenderableVisitor() {}
        virtual void visit(Renderable *r, unsigned short group, bool onlyIfPassed);
    };
};

// INFERRED: out-of-line ctor so the vtable (and its deleting dtor) is emitted in this file.
RbxSceneManager::SceneMgrQueuedRenderableVisitor::SceneMgrQueuedRenderableVisitor()
{
}

void RbxSceneManager::SceneMgrQueuedRenderableVisitor::visit(Renderable *, unsigned short, bool)
{
}

}
