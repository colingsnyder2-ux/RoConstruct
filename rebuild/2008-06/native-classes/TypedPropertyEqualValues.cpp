// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /fp:fast /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// TypedPropertyDescriptor<T>::equalValues for the class-typed properties std::string 00443490, TextureId 005861f0,
// G3D::CoordinateFrame 005846d0 and G3D::Vector3 0059b2a0 (registry decorated names
// ?equalValues@?$TypedPropertyDescriptor@...@Reflection@RBX@@UBE_NPBVDescribedBase@23@0@Z).
// Flags/includes: TPD_ids.cpp (TextureId through the donor util/TextureId.h) plus /fp:fast, which the x87 fcomp
// compares of 005846d0 / 0059b2a0 need (TypedPropertyScalarMembers.cpp float sibling).
// Evidence: all four targets read getValue(b) before getValue(a), as BrickColor 0048bb40 does: the comparison is
// getValue(a) == getValue(b) with a class operator== that evaluates its argument (or, for the free std::string /
// ContentId operator==, its right operand) first; the read-only in-class reflection/property.h body
// (getValue(b) == getValue(a)) reads a first for these types. Each unit therefore specializes the body inline, like
// AppUnit480_2008Player.cpp (BrickColor) and TypedPropertyScalarMembers.cpp (float), before the explicit class
// instantiation emits the vtable (header proposal: the generic body as getValue(a) == getValue(b) for class types).
#include "util/TextureId.h"
#include "reflection/property.h"
#include "G3D/Vector3.h"
#include "G3D/CoordinateFrame.h"
#include <string>

namespace RBX {
namespace Reflection {

// 00443490 (146 B): two getValue copies (0061a7b0), MSVCP90 operator==(string, string), both strings destroyed.
template<>
inline bool TypedPropertyDescriptor<std::string>::equalValues(const DescribedBase* a, const DescribedBase* b) const
{
	return getValue(a) == getValue(b);
}

// 005861f0 (145 B): the same shape with the string operator== copy at 0055bd70 on the TextureId copies.
template<>
inline bool TypedPropertyDescriptor<TextureId>::equalValues(const DescribedBase* a, const DescribedBase* b) const
{
	return getValue(a) == getValue(b);
}

// 005846d0 (114 B): out-of-line getValue 004acb30 twice, translation fcomp chain, then Matrix3::operator== 00513280.
template<>
inline bool TypedPropertyDescriptor<G3D::CoordinateFrame>::equalValues(const DescribedBase* a, const DescribedBase* b) const
{
	return getValue(a) == getValue(b);
}

// 0059b2a0 (111 B): getset (+0x18) slot 2 into two stack Vector3s, three fcomp compares.
template<>
inline bool TypedPropertyDescriptor<G3D::Vector3>::equalValues(const DescribedBase* a, const DescribedBase* b) const
{
	return getValue(a) == getValue(b);
}

template class TypedPropertyDescriptor<std::string>;
template class TypedPropertyDescriptor<TextureId>;
template class TypedPropertyDescriptor<G3D::CoordinateFrame>;
template class TypedPropertyDescriptor<G3D::Vector3>;

}
}
