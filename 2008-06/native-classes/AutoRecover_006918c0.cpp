// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native Rectangle2D header; the class is declared locally with only its virtual destructor.
namespace Ogre {
class __declspec(dllimport) Rectangle2D {
public:
    virtual ~Rectangle2D();
};
}

extern "C" void* __fastcall fn_006918c0(Ogre::Rectangle2D* self, int unusedEdx, unsigned int flags)
{
    // Qualified call is non-virtual: direct call through the rgmain import.
    self->Ogre::Rectangle2D::~Rectangle2D();
    if (flags & 1)
        operator delete(self);
    return self;
}
