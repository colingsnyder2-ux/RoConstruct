// INFERRED: Cache member names; member types evidenced by the constructor 004f1990
// (two std::map<BrickColor::Number, Color4> at +0/+0x20, GuidRegistryMutex at +0x40) and operator new(0x4c).
// INFERRED: free function name initialize (registry identity-unlock); stores the Cache at 00972880.
// native-flags: /O2 /EHsc /GS- /MD /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src
#include <map>
#include "v8datamodel/BrickColor.h"
#include "G3D/Color4.h"
#include "util/GuidRegistry.h"

namespace PlayerNativeMaterial {
namespace {

struct Cache
{
	std::map<RBX::BrickColor::Number, G3D::Color4> colors;
	std::map<RBX::BrickColor::Number, G3D::Color4> specular;
	RBX::GuidRegistryMutex mutex;
	Cache();
};

Cache* cache;

}
}

void __cdecl initialize(void)
{
	PlayerNativeMaterial::cache = new PlayerNativeMaterial::Cache;
}
