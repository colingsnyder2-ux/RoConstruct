// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class PolyPair {
public:
    int a, b, c, d, e;
    virtual PolyPair* allocateClone();
};
class FaceFacePair : public PolyPair {
public:
    int f, g;
    virtual PolyPair* allocateClone();
};
PolyPair* FaceFacePair::allocateClone()
{
    return new FaceFacePair(*this);
}
}