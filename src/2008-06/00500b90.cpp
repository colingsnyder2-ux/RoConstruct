// from server: 100% by king_originala
// from server: 82% by colin
// from server: 81% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_king_originala_filemesh_create_a533ca0c4fde47cf.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include "G3D/ReferenceCount.h"
#include "G3D/Vector3.h"
#include "util/MeshId.h"
namespace RBX { namespace RenderBase {
class Mesh:public G3D::ReferenceCountedObject {
 // Native Mesh ctor writes through offset0x87; FileMesh allocation is0x88.
 // External native Mesh constructor/destructor own these private member bytes.
 char nativeMembers[124];
public:
 Mesh();
 virtual ~Mesh();
};
} namespace ViewNew {
class FileMesh:public RenderBase::Mesh {
public:
 FileMesh(){}
 bool loadFromMeshFile(ContentProvider*,const G3D::Vector3&,MeshId);
 static G3D::ReferenceCountedPointer<RenderBase::Mesh> create(ContentProvider*,const G3D::Vector3&,MeshId);
};
G3D::ReferenceCountedPointer<RenderBase::Mesh> FileMesh::create(ContentProvider* provider,const G3D::Vector3& scale,MeshId id) {
 FileMesh* newMesh=new FileMesh;
 G3D::ReferenceCountedPointer<FileMesh> mesh=newMesh;
 if(!newMesh->loadFromMeshFile(provider,scale,id))return NULL;
 else return mesh;
}
}}
