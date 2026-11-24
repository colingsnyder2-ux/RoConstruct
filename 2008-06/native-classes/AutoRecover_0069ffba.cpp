// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is only an import thunk (jmp [__imp_...]) into rgmain's
// Ogre::MovableObject::_notifyManager. Reproduce it as a tail call through a
// dllimport thiscall member with identical signature, which /O2 turns into a jmp.

namespace Ogre {

class SceneManager;

struct NotifyManagerImport
{
    __declspec(dllimport) void notifyManagerImpl(SceneManager* man);
};

class MovableObject
{
public:
    virtual void _notifyManager(SceneManager* man);

protected:
    SceneManager* mManager;
};

void MovableObject::_notifyManager(SceneManager* man)
{
    reinterpret_cast<NotifyManagerImport*>(this)->notifyManagerImpl(man);
}

} // namespace Ogre
