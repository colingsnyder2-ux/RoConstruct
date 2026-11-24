// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers; minimal local declaration. Base dtor is imported from rgmain (Ogre::DefaultRaySceneQuery::~DefaultRaySceneQuery).
namespace Ogre {
class DefaultRaySceneQuery {
public:
    __declspec(dllimport) virtual ~DefaultRaySceneQuery();
};
}

extern "C" void* __fastcall fn_0068cd70(Ogre::DefaultRaySceneQuery* self, int unusedEdx, unsigned int flags)
{
    self->Ogre::DefaultRaySceneQuery::~DefaultRaySceneQuery();
    if (flags & 1)
        ::operator delete(self);
    return self;
}
