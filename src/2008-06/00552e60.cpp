// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /MD
// roc-lib: rbxgs-render roc_g3d_array_debug_89494c2c4f78369c.cpp

// Candidate translation unit (score above; library headers required).
#include <GLG3D/Texture.h>
#include <G3D/ReferenceCount.h>
#include <G3D/Array.h>
template class G3D::Array<G3D::Texture*>;
void use_array(G3D::Array<G3D::ReferenceCountedPointer<G3D::Texture> >& a,const G3D::ReferenceCountedPointer<G3D::Texture>& v,int size) { a.append(v); a.resize(size); a.clear(); }
