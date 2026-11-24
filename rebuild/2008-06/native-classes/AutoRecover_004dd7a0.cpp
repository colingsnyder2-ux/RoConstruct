// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace Ogre {
struct Vector3 {
    float x, y, z;
};
}

// INFERRED: empty tag struct passed by value (std::_Scalar_ptr_iterator_tag style)
struct UninitCopyTag {};

// INFERRED: std::_Uninit_copy<const Vector3*, Vector3*, allocator<Vector3>> argument layout from the push sequence
extern "C" Ogre::Vector3* __cdecl fn_004dc670(const Ogre::Vector3* first,
                                              const Ogre::Vector3* last,
                                              Ogre::Vector3* dest,
                                              void* alloc,
                                              Ogre::Vector3* dest2,
                                              UninitCopyTag tag);

// INFERRED: object is a vector-like container with its allocator at offset 8
extern "C" Ogre::Vector3* __fastcall fn_004dd7a0(void* self, int unusedEdx,
                                                 const Ogre::Vector3* first,
                                                 const Ogre::Vector3* last,
                                                 Ogre::Vector3* dest)
{
    UninitCopyTag tag;
    return fn_004dc670(first, last, dest, (char*)self + 8, dest, tag);
}
