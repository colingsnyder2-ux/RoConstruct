// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_aa41507c7ce2107d.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/Object.h", "roc_espeon_arrowfactoryheader347662b16dc22b66.cpp")
#pragma include_alias("util/IRenderable.h", "roc_espeon_renderableaccessheaderd4d76fdf723bc309.cpp")
#pragma include_alias("reflection/function.h", "roc_espeon_machineheader2f6c7dcf10adead1.cpp")
#pragma include_alias("reflection/signal.h", "roc_espeon_machineheader16e657153fe9fb6e.cpp")
#pragma include_alias("reflection/type.h", "roc_espeon_machineheader4aaa2bdeb1c2b6c3.cpp")
#pragma include_alias("reflection/reflection.h", "roc_espeon_machineheadera6fefc64bf3a6f9e.cpp")
#pragma include_alias("reflection/Reflection.h", "roc_espeon_machineheadera6fefc64bf3a6f9e.cpp")
#pragma include_alias("reflection/enumconverter.h", "roc_espeon_machineheader297ae1c3351d4ab6.cpp")
#pragma include_alias("reflection/object.h", "roc_espeon_machineheadercadaaebe20af2047.cpp")
#pragma include_alias("reflection/member.h", "roc_espeon_machineheader459d66d9acfae4ab.cpp")
#pragma include_alias("reflection/descriptor.h", "roc_espeon_machineheader0acd23dba6f04ff5.cpp")
#pragma include_alias("reflection/property.h", "roc_espeon_machineheadercfb6c68c9dd60df6.cpp")
#pragma include_alias(<v8tree/Verb.h>, <roc_espeon_insertnativeheader1a746c4cc8c6ae06.cpp>)
#pragma include_alias("v8tree/Verb.h", "roc_espeon_insertnativeheader1a746c4cc8c6ae06.cpp")
#pragma include_alias(<util/Name.h>, <roc_espeon_insertnativeheader115b7bccd0a9061e.cpp>)
#pragma include_alias("util/Name.h", "roc_espeon_insertnativeheader115b7bccd0a9061e.cpp")
#pragma include_alias(<util/Debug.h>, <roc_espeon_insertnativeheader5fe96130a83d2e88.cpp>)
#pragma include_alias("util/Debug.h", "roc_espeon_insertnativeheader5fe96130a83d2e88.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_espeon_nativeinstanceguidportablea1682bda32c99cd2.cpp")
#pragma include_alias("Network/Player.h", "roc_espeon_playernamedpositionheader83d6618d03dc20d6.cpp")
#pragma include_alias("security/SecurityContext.h", "roc_espeon_playersecurityheaderb6e3b120ba6105e5.cpp")
#undef _RELEASEASSERT
#include "Network/Player.h"
#include "security/SecurityContext.h"
#include <G3D/Vector2.h>
namespace RBX {namespace Network {
struct PlayerIdleBox {G3D::Vector2 low,high;PlayerIdleBox(const G3D::Vector2& l,const G3D::Vector2& h):low(l),high(h){}};
}}
namespace RBX {namespace Network {
Player::Player():teamColor(BrickColor::lego_1),neutral(true),under13(false),superSafeChat(false),userId(0),lastActivityTime(0.0) {
 Security::Context::current().requirePermission(Security::Administrator,"create a Player");
 setName("Player");
 const G3D::Vector2& center=G3D::Vector2::zero();
 PlayerIdleBox box(G3D::Vector2(center.x-0.5f,center.y-0.5f),G3D::Vector2(center.x+0.5f,center.y+0.5f));
 G3D::Vector2& low=box.low;G3D::Vector2& high=box.high;
 { G3D::Vector2int16 packed(low); idle0=packed; }
 { G3D::Vector2int16 packed(high); idle1=packed; }
 { G3D::Vector2int16 packed(low); idle2=packed; }
 { G3D::Vector2int16 packed(high); idle3=packed; }
 { G3D::Vector2int16 packed(low); idle4=packed; }
 { G3D::Vector2int16 packed(high); idle5=packed; }
}
void Player::setName(const std::string& value) {
 Security::Context::current().requirePermission(Security::Administrator,"set a Player's name");
 Instance::setName(value);
}
}}
