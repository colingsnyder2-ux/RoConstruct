// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_nativecubewideindicesef28fe8efd62f246.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector3.h>
#include <vector>
// Target004de1d0 appends triangles (a,b,c) and (a,c,d); callee004ddf10 is vector<short>::push_back.
static __declspec(noinline) void appendQuad(std::vector<short>& output,unsigned a,unsigned b,unsigned c,unsigned d){
 output.push_back((unsigned short)a);output.push_back((unsigned short)b);output.push_back((unsigned short)c);output.push_back((unsigned short)a);output.push_back((unsigned short)c);output.push_back((unsigned short)d);
}
void __cdecl buildCube(const G3D::Vector3* half, std::vector<G3D::Vector3>* vertices,
                       std::vector<short>* indices)
{
    vertices->reserve(8);
    indices->reserve(36);
    vertices->push_back(G3D::Vector3(-half->x, -half->y, -half->z));
    vertices->push_back(G3D::Vector3(-half->x, -half->y, half->z));
    vertices->push_back(G3D::Vector3(-half->x, half->y, -half->z));
    vertices->push_back(G3D::Vector3(-half->x, half->y, half->z));
    vertices->push_back(G3D::Vector3(half->x, -half->y, -half->z));
    vertices->push_back(G3D::Vector3(half->x, -half->y, half->z));
    vertices->push_back(G3D::Vector3(half->x, half->y, -half->z));
    vertices->push_back(G3D::Vector3(half->x, half->y, half->z));
    appendQuad(*indices,7, 5, 4, 6);
    appendQuad(*indices,2, 0, 1, 3);
    appendQuad(*indices,7, 6, 2, 3);
    appendQuad(*indices,1, 0, 4, 5);
    appendQuad(*indices,3, 1, 5, 7);
    appendQuad(*indices,6, 4, 0, 2);
}
