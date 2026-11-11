// 2008-06 native class-name template instances of the application range 00400000..0040c000 (inactive). Verified by
// tests/record_native_app_unit400_2008.py. All headers are read-only here.
//
// Name::doDeclare<sC>() (101 B, `static const Name& n = declare(sC, -1)`) and Name::callDoDeclare<sC>() (5 B, a tail
// jump) are inline in native util/Name.h; they are instantiated here through Name::declare<sC>(). The original rows lie
// in the COMDAT run of the unit whose static initializers 007ee760..007eebe0 call them (one initializer per name):
//   doDeclare  00401a00 RunService, 00406770 RenderSettings, 004067e0 Team, 00406850 Player, 004068c0 Selection,
//              004099c0..00409cd0 ReflectionMetadata, ...Classes, ...Class, ...Properties, ...Functions, ...Events,
//              ...Member, Authoring, and 0040b790 ReflectionMetadataItem;
//   callDoDeclare 00406e90..00406ec0, 00409fd0..0040a040 and 0040b800 (each a jmp to its doDeclare row).
// >>> native-status (generated) -- do not edit >>>
// AppUnit400_2008Names | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src f2199fa3 | roc native-status --write
#include "util/RunStateOwner.h"
#include "CRenderSettings.h"
#include "v8datamodel/Team.h"
#include "Network/Player.h"
#include "v8datamodel/Selection.h"
#include "reflection/Metadata.h"
#include "AuthoringSettings.h"

namespace RBX
{
	template const Name& Name::declare<sRunService>();
	template const Name& Name::declare<sRenderSettings>();
	template const Name& Name::declare<sTeam>();
	template const Name& Name::declare<Network::sPlayer>();
	template const Name& Name::declare<sSelection>();
	template const Name& Name::declare<Metadata::sReflection>();
	template const Name& Name::declare<Reflection::Metadata::sClasses>();
	template const Name& Name::declare<Reflection::Metadata::sClass>();
	template const Name& Name::declare<Reflection::Metadata::sProperties>();
	template const Name& Name::declare<Reflection::Metadata::sFunctions>();
	template const Name& Name::declare<Reflection::Metadata::sEvents>();
	template const Name& Name::declare<Reflection::Metadata::sMember>();
	template const Name& Name::declare<sAuthoringSettings>();
	template const Name& Name::declare<Reflection::Metadata::sItem>();
}
