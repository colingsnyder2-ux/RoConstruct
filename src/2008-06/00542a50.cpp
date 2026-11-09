// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// roc-lib: g3d-6.09 roc_g3d_vector_strong_b0beb8bf4f1ef12a.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/ReferenceCount.h>
#include <vector>
typedef G3D::ReferenceCountedPointer<G3D::ReferenceCountedObject> NativeStrongRef;
typedef char StrongRefSize[sizeof(NativeStrongRef)==4?1:-1];
template class std::vector<NativeStrongRef>;
