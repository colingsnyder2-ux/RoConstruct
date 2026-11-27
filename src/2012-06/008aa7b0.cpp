// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /GR
namespace RBX {
class PVInstance { public: virtual void v(); };
class PartInstance : public PVInstance { public: char pad[0x194]; int f198; };
struct ConstraintSurfacePair {
    int vtable; char pad4[0x3C]; int field40;
    void func(PVInstance* a1);
};
void ConstraintSurfacePair::func(PVInstance* a1) {
    PartInstance* d = dynamic_cast<PartInstance*>(a1);
    if (d) field40 = d->f198; else field40 = 0;
}
}
