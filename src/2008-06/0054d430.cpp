// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// roc-lib: rbxgs-render roc_g3d_array_elements_81494bb97fb70122.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Array.h>
#include <G3D/Vector3.h>
#include <G3D/Vector4.h>
void use_array_0(G3D::Array<int> &a,const int&v,int size) { a.append(v); a.resize(size); a.clear(); }
void create_array_0(const int&v) { G3D::Array<int> a; a.append(v); }
void use_array_1(G3D::Array<float> &a,const float&v,int size) { a.append(v); a.resize(size); a.clear(); }
void create_array_1(const float&v) { G3D::Array<float> a; a.append(v); }
void use_array_2(G3D::Array<G3D::Vector3> &a,const G3D::Vector3&v,int size) { a.append(v); a.resize(size); a.clear(); }
void create_array_2(const G3D::Vector3&v) { G3D::Array<G3D::Vector3> a; a.append(v); }
void use_array_3(G3D::Array<G3D::Vector4> &a,const G3D::Vector4&v,int size) { a.append(v); a.resize(size); a.clear(); }
void create_array_3(const G3D::Vector4&v) { G3D::Array<G3D::Vector4> a; a.append(v); }
