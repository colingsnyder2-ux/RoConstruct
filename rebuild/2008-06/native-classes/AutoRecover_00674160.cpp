// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <string>

namespace Ogre {
class SceneManager;
// INFERRED: minimal SceneNode stand-in; real layout is in the Ogre 1.4.5 client-import headers.
// The derived map member sits at +0x228, so the base is that large.
class __declspec(dllimport) SceneNode {
public:
    SceneNode(SceneManager* creator, const std::string& name);
    virtual ~SceneNode();
private:
    char pad[0x228 - 4];
};
}

// 0x446110: std::_Tree<_Tmap_traits<int, LDraw2RobloxColorMap*, less<int>, ...>> ctor (thiscall, 2 stack args)
extern "C" void* __fastcall fn_00446110(void* self, int unusedEdx, void* pred, void* alloc);

// INFERRED: class name unknown; SceneNode subclass holding an int -> LDraw2RobloxColorMap* map at +0x228
class Fn00674160Node : public Ogre::SceneNode {
public:
    Fn00674160Node(Ogre::SceneManager* creator, const std::string& name)
        : Ogre::SceneNode(creator, name)
    {
        char pred, alloc;
        fn_00446110(mapStorage, 0, &pred, &alloc);
    }
    virtual ~Fn00674160Node() {}
    char mapStorage[0x10];
};

extern "C" void* __fastcall fn_00674160(void* self, int unusedEdx, Ogre::SceneManager* creator, const std::string& name)
{
    return new (self) Fn00674160Node(creator, name);
}
