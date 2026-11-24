// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Ogre header is available, so SceneNode is declared locally with an imported dtor (rgmain!??1SceneNode@Ogre@@UAE@XZ).
namespace Ogre {
class __declspec(dllimport) SceneNode {
public:
    virtual ~SceneNode();
};
}

// INFERRED: the vector deleting destructor is compiler-generated, so it is written out as a plain function.
extern "C" Ogre::SceneNode* __fastcall fn_0069a2e0(Ogre::SceneNode* self, int unusedEdx, unsigned int flags)
{
    self->Ogre::SceneNode::~SceneNode();
    if (flags & 1)
        operator delete(self);
    return self;
}
