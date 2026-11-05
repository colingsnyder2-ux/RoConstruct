// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /MD
// roc-lib: rbxgs-render roc_g3d_ptr_debug_fbb0c4ed74b7271b.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
#include <GLG3D/Texture.h>
#include <G3D/ReferenceCount.h>
template class std::vector<G3D::ReferenceCountedPointer<G3D::Texture> >;
void fill_pointers(G3D::ReferenceCountedPointer<G3D::Texture>* begin,G3D::ReferenceCountedPointer<G3D::Texture>* end,const G3D::ReferenceCountedPointer<G3D::Texture>& value) { std::fill(begin,end,value); }
