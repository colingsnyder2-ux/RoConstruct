// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

namespace Ogre {
    // INFERRED: minimal stand-in for the real class; the destructor is imported from rgmain.
    class __declspec(dllimport) DefaultIntersectionSceneQuery {
    public:
        virtual ~DefaultIntersectionSceneQuery();
    };
}

// INFERRED: the compiler-generated deleting destructor cannot be written by name in C++,
// so it is emitted as an extern "C" __fastcall function (ecx = this, edx unused).
extern "C" void* __fastcall fn_0068ce10(Ogre::DefaultIntersectionSceneQuery* self, int unusedEdx, unsigned int flags)
{
    self->Ogre::DefaultIntersectionSceneQuery::~DefaultIntersectionSceneQuery();
    if (flags & 1)
        ::operator delete(self);
    return self;
}
