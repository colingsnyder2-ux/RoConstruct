// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Material-cache key ordering; identity inferred from 2008 call sites and donor.
#include "ViewNew/MaterialFactory2008.h"

bool RBX::ViewNew::MaterialFactory::Attributes::operator<(const Attributes& other) const
{
    if (color < other.color) return true;
    if (color > other.color) return false;
    if (transparency < other.transparency) return true;
    if (transparency > other.transparency) return false;
    return reflectance < other.reflectance;
}

// The material caches (2007 openrbx RbxView/MaterialFactory.cpp database / megaDatabase, keyed by Attributes and
// holding weak material pointers): map<Attributes, WeakReferenceCountedPointer<MaterialBase> > members 004f08c0 _Lbound,
// 004f0c90 _Buynode, 004f1040 / 004f1500 insert, 004f1180 erase, 004f1470 _Erase, 004f1710 operator[] (called by
// getMegaMaterial 004f1a60 / getMaterial 004f1c60), the pair dtor 004f0b10 and the weak pointer copy ctor 004f0bc0 /
// operator=(const ReferenceCountedPointer&) 004f0c40. Explicit instantiations until those lookups are built here.
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include "RenderLib/Material2008.h"
#include <map>

template class std::map<RBX::ViewNew::MaterialFactory::Attributes, G3D::WeakReferenceCountedPointer<RBX::RenderBase::MaterialBase> >;
// Members only: a class-wide instantiation reaches the donor G3D ReferenceCount.h ordering operators, which do not compile.
template G3D::WeakReferenceCountedPointer<RBX::RenderBase::MaterialBase>::WeakReferenceCountedPointer(const G3D::WeakReferenceCountedPointer<RBX::RenderBase::MaterialBase>&);
template G3D::WeakReferenceCountedPointer<RBX::RenderBase::MaterialBase>& G3D::WeakReferenceCountedPointer<RBX::RenderBase::MaterialBase>::operator=(const G3D::ReferenceCountedPointer<RBX::RenderBase::MaterialBase>&);
