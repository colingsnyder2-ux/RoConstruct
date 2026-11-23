// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <vector>

// INFERRED: Ogre::Vector3 is three floats (12-byte stride in the disassembly)
namespace Ogre { struct Vector3 { float x, y, z; }; }

// std::vector<Ogre::Vector3>::reserve(size_t) instance (MSVC 2008 layout: proxy at +4, first at +0xc)
extern "C" void __fastcall fn_004dd7d0(std::vector<Ogre::Vector3>* self, int unusedEdx, unsigned int n)
{
    self->reserve(n);
}
