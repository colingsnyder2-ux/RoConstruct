// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: disassembly shows a cdecl 3-pointer-arg thunk (std::copy_backward<Vector3*,Vector3*>)
// forwarding to _Copy_backward_opt(first, last, dest, dest, dest, tag). Naming follows fn_<addr> convention.
namespace Ogre { class Vector3; }

extern "C" Ogre::Vector3* fn_0067f1d0(Ogre::Vector3* first, Ogre::Vector3* last, Ogre::Vector3* dest,
                                      Ogre::Vector3* destA, Ogre::Vector3* destB, char tag);

extern "C" Ogre::Vector3* fn_004dcd60(Ogre::Vector3* first, Ogre::Vector3* last, Ogre::Vector3* dest)
{
    char tag = 0;
    return fn_0067f1d0(first, last, dest, dest, dest, tag);
}
