// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: class body unknown; only the vector deleting destructor is defined.
namespace Ogre {
class __declspec(dllimport) DefaultSphereSceneQuery {
public:
    virtual ~DefaultSphereSceneQuery();
};
}

void operator delete(void*);

extern "C" void* __fastcall fn_0068cc10(Ogre::DefaultSphereSceneQuery* self, int unusedEdx, unsigned int flags)
{
    // Qualified call is non-virtual: matches the direct import call in the original.
    self->Ogre::DefaultSphereSceneQuery::~DefaultSphereSceneQuery();
    if (flags & 1)
        operator delete(self);
    return self;
}
