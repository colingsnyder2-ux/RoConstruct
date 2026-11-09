// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: g3d-6.09 roc_unit_624aff18becba205.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Array.h>
namespace RBX {
struct Vector3int32 {int x,y,z; Vector3int32(const int& a,const int& b,const int& c):x(a),y(b),z(c){} };
class SpatialNode;
class Contact;
class Primitive {
public:
    char prefix[0x64];
    SpatialNode* spatialNodes;
    Vector3int32 oldSpatialMin;
    Vector3int32 oldSpatialMax;
    Contact* getFirstContact();
    Contact* getNextContact(Contact*);
};
class Contact {
public:
    char prefix[0xc];
    Primitive* prim0;
    Primitive* prim1;
    Primitive* otherPrimitive(const Primitive* p) const { return p == prim0 ? prim1 : prim0; }
};
class ContactManager { public: void onReleasePair(Primitive*, Primitive*); };
class SpatialHash {
public:
    char prefix[8];
    ContactManager* contactManager;
    char beforeScratch[0x80 - 0xc];
    G3D::Array<Primitive*> scratch;
    void destroyNode(SpatialNode*);
    void onPrimitiveRemoved(Primitive*);
};
void SpatialHash::onPrimitiveRemoved(Primitive* p) {
    while (p->spatialNodes) destroyNode(p->spatialNodes);
    p->oldSpatialMin = Vector3int32(0x7fffffff,0x7fffffff,0x7fffffff);
    p->oldSpatialMax = Vector3int32(-0x7fffffff,-0x7fffffff,-0x7fffffff);
    scratch.clear();
    Contact* contact = p->getFirstContact();
    while (contact) {
        Primitive* other = contact->otherPrimitive(p);
        contact = p->getNextContact(contact);
        scratch.append(other);
    }
    for (int i = 0; i < scratch.size(); ++i) contactManager->onReleasePair(p, scratch[i]);
}
}
