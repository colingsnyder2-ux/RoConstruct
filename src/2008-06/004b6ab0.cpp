// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net-dll roc_replicator_property_native_offset_91d34afc4bce4141.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include "roc_replicator_native_reader_header_c2bb2f74a3b996f5.cpp"
#include "v8datamodel/PartInstance.h"
namespace RBX { namespace Network {
void Replicator::serializeValue(const Reflection::ConstProperty& property, bool useDictionary, RakNet::BitStream& stream) {
 if(property.getDescriptor().type==Reflection::Type::singleton<std::string>())
  getSharedDictionary(property.getDescriptor()).serializeString(property,stream);
 else if(property.getDescriptor().type==Reflection::Type::singleton<bool>())
  stream << property.getValue<bool>();
 else if(property.getDescriptor().type==Reflection::Type::singleton<int>())
  stream << property.getValue<int>();
 else if(property.getDescriptor().type==Reflection::Type::singleton<float>())
  stream << property.getValue<float>();
 else if(property.getDescriptor().type==Reflection::Type::singleton<double>())
  serialize<double>(property,stream);
 else if(property.getDescriptor().type==Reflection::Type::singleton<BrickColor>())
  serialize<BrickColor>(property,stream);
 else if(property.getDescriptor().type==Reflection::Type::singleton<G3D::Color3>())
  serialize<G3D::Color3>(property,stream);
 else if(property.getDescriptor().type==Reflection::Type::singleton<G3D::Vector3>()) {
  if(property.getDescriptor()==PartInstance::prop_Size)
   writeBrickVector(stream,property.getValue<G3D::Vector3>());
  else serialize<G3D::Vector3>(property,stream);
 }
 else if(property.getDescriptor().type==Reflection::Type::singleton<G3D::CoordinateFrame>())
  serialize<G3D::CoordinateFrame>(property,stream);
 else if(dynamic_cast<const Reflection::EnumPropertyDescriptor*>(&property.getDescriptor()))
  serializeEnum(property,stream);
 else if(dynamic_cast<const Reflection::RefPropertyDescriptor*>(&property.getDescriptor()))
  serializeRef(property,stream);
 else if(property.getDescriptor().type==Reflection::Type::singleton<ContentId>())
  serialize<ContentId>(property,stream);
}
} }

#include "../App/roc_genuine_scoped_assign_header_e786e6fff97592d1.cpp"

namespace RBX { namespace Network {
void Replicator::deserializeValue(RakNet::BitStream& stream, Reflection::Property& property) {
 ScopedAssign<const Reflection::Property*> assign(*reinterpret_cast<const Reflection::Property**>(reinterpret_cast<char*>(this)+0x2cd4),&property);
 if(property.getDescriptor().type==Reflection::Type::singleton<std::string>())
  getSharedDictionary(property.getDescriptor()).deserializeString(property,stream);
 else if(property.getDescriptor().type==Reflection::Type::singleton<bool>()) {
  bool value;stream>>value;if(property.getInstance())property.setValue(value);
 }
 else if(property.getDescriptor().type==Reflection::Type::singleton<int>()) {
  int value;stream>>value;if(property.getInstance())property.setValue(value);
 }
 else if(property.getDescriptor().type==Reflection::Type::singleton<float>())
  deserialize<float>(property,stream);
 else if(property.getDescriptor().type==Reflection::Type::singleton<double>())
  deserialize<double>(property,stream);
 else if(property.getDescriptor().type==Reflection::Type::singleton<BrickColor>())
  deserialize<BrickColor>(property,stream);
 else if(property.getDescriptor().type==Reflection::Type::singleton<G3D::Color3>())
  deserialize<G3D::Color3>(property,stream);
 else if(property.getDescriptor().type==Reflection::Type::singleton<G3D::Vector3>()) {
  if(property.getDescriptor()==PartInstance::prop_Size) {
   G3D::Vector3 value;readBrickVector(stream,value);
   if(property.getInstance())property.setValue(value);
  }
  else deserialize<G3D::Vector3>(property,stream);
 }
 else if(property.getDescriptor().type==Reflection::Type::singleton<G3D::CoordinateFrame>())
  deserialize<G3D::CoordinateFrame>(property,stream);
 else if(dynamic_cast<const Reflection::EnumPropertyDescriptor*>(&property.getDescriptor()))
  deserializeEnum(property,stream);
 else if(dynamic_cast<const Reflection::RefPropertyDescriptor*>(&property.getDescriptor()))
  deserializeRef(property,stream);
 else if(property.getDescriptor().type==Reflection::Type::singleton<ContentId>())
  deserialize<ContentId>(property,stream);
}
} }
