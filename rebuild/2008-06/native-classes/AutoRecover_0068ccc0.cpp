// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native header supplied; class declared locally. Dtor imported from rgmain.
// INFERRED: the compiler-generated vector deleting dtor is written out by hand with the __thiscall ABI.
#include <new>

namespace Ogre {
    class __declspec(dllimport) DefaultPlaneBoundedVolumeListSceneQuery {
    public:
        virtual ~DefaultPlaneBoundedVolumeListSceneQuery();
    };
}

extern "C" Ogre::DefaultPlaneBoundedVolumeListSceneQuery* __fastcall fn_0068ccc0(
    Ogre::DefaultPlaneBoundedVolumeListSceneQuery* self, int unusedEdx, unsigned int flags) {
    self->Ogre::DefaultPlaneBoundedVolumeListSceneQuery::~DefaultPlaneBoundedVolumeListSceneQuery();
    if (flags & 1)
        operator delete(self);
    return self;
}
