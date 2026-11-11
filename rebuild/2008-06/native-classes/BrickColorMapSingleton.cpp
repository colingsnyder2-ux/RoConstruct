// >>> native-status (generated) -- do not edit >>>
// BrickColorMapSingleton | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 3f8c4587 | roc native-status --write
#include "v8datamodel/BrickColor.h"

namespace RBX {
BrickColor::BrickMap& BrickColor::BrickMap::singleton()
{
    static BrickMap map;
    return map;
}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::BrickColor> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<enum RBX::BrickColor::Number const ,G3D::Color4> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<enum RBX::BrickColor::Number const ,G3D::Color4uint8> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<enum RBX::BrickColor::Number const ,int> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<enum RBX::BrickColor::Number const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >;
template class std::_Vector_val<RBX::BrickColor,std::allocator<RBX::BrickColor> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<enum RBX::BrickColor::Number,G3D::Color4,std::less<enum RBX::BrickColor::Number>,std::allocator<std::pair<enum RBX::BrickColor::Number const ,G3D::Color4> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<enum RBX::BrickColor::Number,G3D::Color4uint8,std::less<enum RBX::BrickColor::Number>,std::allocator<std::pair<enum RBX::BrickColor::Number const ,G3D::Color4uint8> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<enum RBX::BrickColor::Number,int,std::less<enum RBX::BrickColor::Number>,std::allocator<std::pair<enum RBX::BrickColor::Number const ,int> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<enum RBX::BrickColor::Number,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::less<enum RBX::BrickColor::Number>,std::allocator<std::pair<enum RBX::BrickColor::Number const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,0> >::_Node *>;
template class std::map<enum RBX::BrickColor::Number,G3D::Color4,std::less<enum RBX::BrickColor::Number>,std::allocator<std::pair<enum RBX::BrickColor::Number const ,G3D::Color4> > >;
template class std::map<enum RBX::BrickColor::Number,int,std::less<enum RBX::BrickColor::Number>,std::allocator<std::pair<enum RBX::BrickColor::Number const ,int> > >;
