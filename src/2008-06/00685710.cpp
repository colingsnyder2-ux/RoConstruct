// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_sub_transform_2a4870813417745d.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <OgreSubEntity.h>
#include <OgreMatrix4.h>
namespace Ogre { class RbxSubEntity : public SubEntity { public: __declspec(align(16)) Matrix4 transform; void getWorldTransforms(Matrix4* out) const; };
void RbxSubEntity::getWorldTransforms(Matrix4* out) const { *out = transform; } }
