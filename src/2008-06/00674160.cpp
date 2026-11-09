// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
#include <set>
#include <string>
struct SceneManager;
struct SceneNode {
    virtual ~SceneNode();
    __declspec(dllimport) SceneNode(SceneManager*, const std::string&);
    char storage[0x224];
};
struct AdornRbxGfx : SceneNode {
    std::map<std::string,int> member;
    AdornRbxGfx(SceneManager*, const std::string*);
    virtual ~AdornRbxGfx();
};
AdornRbxGfx::AdornRbxGfx(SceneManager* manager, const std::string* name)
    : SceneNode(manager, *name)
{
}
