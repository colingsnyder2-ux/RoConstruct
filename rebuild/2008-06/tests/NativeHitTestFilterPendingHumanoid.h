#pragma once
// Declaration-only overlay (copied as out/native-layouts/hit-filters-pending/humanoid/Humanoid.h by
// tests/record_native_hit_filters.py) for the NATIVE_HIT_FILTERS_PENDING build; not a shared header, no layout claimed.
// The PartByLocalCharacter constructor 00660380 calls the static Humanoid::getHeadFromCharacter 005d75a0
// (evidence name ?getHeadFromCharacter@Humanoid@RBX@@SAPAVPartInstance@2@PBVModelInstance@2@@Z). The base list
// follows the RTTI (DescribedCreatable<Humanoid, Instance, sHumanoid>, name mangled $1?sHumanoid@2@3PADA).
#include "v8tree/Instance.h"

namespace RBX
{
	class ModelInstance;
	class PartInstance;

	extern char sHumanoid[];
	class Humanoid : public DescribedCreatable<Humanoid, Instance, sHumanoid>
	{
	public:
		static PartInstance* getHeadFromCharacter(const ModelInstance* character);   // 005d75a0
	};
}
