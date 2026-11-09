// from server: 89% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/CharacterAppearance.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/CharacterAppearance.h"

namespace RBX {

const char sSkin[] = "Skin";

const char sBodyColors[] = "BodyColors";

const char sShirt[] = "Shirt";

const char sShirtGraphic[] = "ShirtGraphic";

} // namespace RBX

template class RBX::FactoryProduct<RBX::BodyColors, RBX::CharacterAppearance, RBX::sBodyColors>;
template class RBX::Reflection::Described<
	RBX::BodyColors,
	RBX::sBodyColors,
	RBX::FactoryProduct<RBX::BodyColors, RBX::CharacterAppearance, RBX::sBodyColors> >;
template class RBX::DescribedCreatable<RBX::BodyColors, RBX::CharacterAppearance, RBX::sBodyColors>;

template class RBX::FactoryProduct<RBX::ShirtGraphic, RBX::CharacterAppearance, RBX::sShirtGraphic>;
template class RBX::Reflection::Described<
	RBX::ShirtGraphic,
	RBX::sShirtGraphic,
	RBX::FactoryProduct<RBX::ShirtGraphic, RBX::CharacterAppearance, RBX::sShirtGraphic> >;
template class RBX::DescribedCreatable<RBX::ShirtGraphic, RBX::CharacterAppearance, RBX::sShirtGraphic>;

template class RBX::FactoryProduct<RBX::Skin, RBX::CharacterAppearance, RBX::sSkin>;
template class RBX::Reflection::
	Described<RBX::Skin, RBX::sSkin, RBX::FactoryProduct<RBX::Skin, RBX::CharacterAppearance, RBX::sSkin> >;
template class RBX::DescribedCreatable<RBX::Skin, RBX::CharacterAppearance, RBX::sSkin>;

template class RBX::FactoryProduct<RBX::Shirt, RBX::ShirtGraphic, RBX::sShirt>;
template class RBX::Reflection::
	Described<RBX::Shirt, RBX::sShirt, RBX::FactoryProduct<RBX::Shirt, RBX::ShirtGraphic, RBX::sShirt> >;
template class RBX::DescribedCreatable<RBX::Shirt, RBX::ShirtGraphic, RBX::sShirt>;
