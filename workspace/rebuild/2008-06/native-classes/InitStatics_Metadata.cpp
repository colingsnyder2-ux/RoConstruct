// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 Reflection::Metadata reflection statics: dynamic initializers 007ef310, 007ef340, 007ef370, 007ef3a0 (Item) and
// 007ef3d0, 007ef400 (Class): name strings, category "Reflection", member offsets +0x130 / +0x131 / +0x132 / +0x134 / +0x150 / +0x154
// read from the initializers; constructors by RTTI (BoundProp<T,1>::BoundPropGetSet<Item / Class>).
#include "reflection/Metadata.h"
#include "reflection/reflection.h"

namespace RBX {
	namespace Reflection {
		namespace Metadata {
			static BoundProp<bool, 1> prop_Browsable("Browsable", "Reflection", &Item::unknown_130, PropertyDescriptor::STANDARD);   // 0096d2ac
			static BoundProp<bool, 1> prop_Deprecated("Deprecated", "Reflection", &Item::unknown_131, PropertyDescriptor::STANDARD);   // 0096d2c8
			static BoundProp<bool, 1> prop_Preliminary("Preliminary", "Reflection", &Item::unknown_132, PropertyDescriptor::STANDARD);   // 0096d2e4
			static BoundProp<std::string, 1> prop_summary("summary", "Reflection", &Item::unknown_134, PropertyDescriptor::STANDARD);   // 0096d300
			static BoundProp<int, 1> prop_ExplorerOrder("ExplorerOrder", "Reflection", &Class::unknown_150, PropertyDescriptor::STANDARD);   // 0096d31c
			static BoundProp<int, 1> prop_ExplorerImageIndex("ExplorerImageIndex", "Reflection", &Class::unknown_154, PropertyDescriptor::STANDARD);   // 0096d338

			void initMetadataStatics() {
				(void)&prop_Browsable;
				(void)&prop_Deprecated;
				(void)&prop_Preliminary;
				(void)&prop_summary;
				(void)&prop_ExplorerOrder;
				(void)&prop_ExplorerImageIndex;
			}
		}
	}
}
