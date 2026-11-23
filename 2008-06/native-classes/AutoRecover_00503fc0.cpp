// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: compiler-generated scalar/vector deleting destructor; defined via a virtual dtor and operator delete.
namespace RBX {
namespace Render {
class RenderScene {
public:
    virtual ~RenderScene();
};
RenderScene::~RenderScene() {}
}
}
