#pragma once
// 2008-06: the reflection Type of RBX::TextureId is the ContentId type (inactive; app unit 00594000, Decal unit).
// Evidence: TypedPropertyDescriptor<TextureId>::TypedPropertyDescriptor 005978a0 (vtable 00832494
// .?AV?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@RBX@@) calls Type::singleton<ContentId> 0056cd80
// ("Content", counted by app-unit564-2008-working.json) directly, before it pushes the PropertyDescriptor arguments
// (the schedule of an inlined callee); the TextureId Value helpers 00597cc8 / 00597b31 / 0059782c store or read the
// same 0056cd80 type. A non-inline singleton<TextureId> would be its own Type ("TextureId") and an out-of-line call.
// Proposed for the owner of util/TextureId.h / reflection/type.h; kept here under a non-colliding name.
#include "reflection/type.h"
#include "util/TextureId.h"

namespace RBX
{
	namespace Reflection
	{
		template<>
		inline const Type& Type::singleton<TextureId>()
		{
			return Type::singleton<ContentId>();
		}
	}
}
