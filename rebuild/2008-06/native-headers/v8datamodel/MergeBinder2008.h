#pragma once
// >>> native-status (generated) -- do not edit >>>
// MergeBinder2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src e3f192d3 | roc native-status --write
// 2008-06 native RBX::IReferenceBinder / RBX::MergeBinder (inactive). Verified by tests/record_native_misc_leaves.py.
//
// The donor declares both in v8xml/SerializerV2.h; this header must not be combined with that one.
//
// MergeBinder vtable 0081593c (RTTI .?AVMergeBinder@RBX@@, bases MergeBinder, IReferenceBinder; no virtual base)
// has exactly 5 slots and no destructor slot:
//   0 announceID      0063fad0 (folded COMDAT: mov eax,[ecx]; jmp [eax+0xc] = processID)
//   1 announceIDREF   00443eb0 (mov eax,[ecx]; jmp [eax+0x10] = processIDREF)
//   2 resolveRefs     00443d60
//   3 processID       004440a0
//   4 processIDREF    00444a70
//
// Layout (sizeof 0x1c; ArchiveBinder::ArchiveBinder 00592940 calls this constructor and builds its own map at +0x1c):
//   +0x00 vfptr (constructor 00443e50 stores 0081593c)
//   +0x04 std::vector<IDREFItem> deferredIDREFItems, VS2008 checked vector of 0x18: the constructor allocates the
//         aux proxy with new(4) into +0x04 and zeroes first/last/end at +0x10/+0x14/+0x18; resolveRefs reads
//         first/last at this+4+0xc / +0x10; ~vector 00443cf0 frees +0xc then the proxy at +0.
// IDREFItem is 0x10 (resolveRefs steps by 0x10): idref +0, propertyOwner +4, InstanceHandle value +8
// (resolveRefs calls idref->assignIDREF(propertyOwner, &value) through slot 0; the 2008 loop binds value before
// propertyOwner: lea edx,[edi+8] is computed before mov edx,[edi+4] at 00443ddc..00443de0).
#include "v8xml/XmlElement.h"
#include "v8tree/Instance.h"
#include "reflection/reflection.h"
#include <vector>

namespace RBX
{
	class IReferenceBinder
	{
	public:
		virtual void announceID(const XmlNameValuePair* valueID, Instance* target) = 0;
		virtual void announceIDREF(const XmlNameValuePair* valueIDREF, Reflection::DescribedBase* propertyOwner, const IIDREF* idref) = 0;
	};

	class MergeBinder : public IReferenceBinder
	{
	private:
		struct IDREFItem
		{
			const IIDREF* idref;                       // +0x00
			Reflection::DescribedBase* propertyOwner;  // +0x04
			InstanceHandle value;                      // +0x08
		};

	private:
		std::vector<IDREFItem> deferredIDREFItems;   // +0x04 (0x18)

	public:
		MergeBinder();   // 00443e50 (out of line in the original)

		virtual void announceID(const XmlNameValuePair* valueID, Instance* target)
		{
			processID(valueID, target);
		}
		virtual void announceIDREF(const XmlNameValuePair* valueIDREF, Reflection::DescribedBase* propertyOwner, const IIDREF* idref)
		{
			processIDREF(valueIDREF, propertyOwner, idref);
		}
		virtual bool resolveRefs()
		{
			for (std::vector<IDREFItem>::iterator iter = deferredIDREFItems.begin(); iter != deferredIDREFItems.end(); iter++)
			{
				const IIDREF*& idref = iter->idref;
				InstanceHandle& value = iter->value;
				Reflection::DescribedBase*& propertyOwner = iter->propertyOwner;

				idref->assignIDREF(propertyOwner, value);
			}

			deferredIDREFItems.clear();

			return true;
		}

	protected:
		virtual bool processID(const XmlNameValuePair* valueID, Instance* source)
		{
			InstanceHandle h;
			if (valueID->getValue(h))
			{
				h.linkTo(shared_from(source));
				return true;
			}
			else if (valueID->isValueEqual(&value_IDREF_nil))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		virtual bool processIDREF(const XmlNameValuePair* valueIDREF, Reflection::DescribedBase* propertyOwner, const IIDREF* idref)
		{
			InstanceHandle h;
			if (valueIDREF->getValue(h))
			{
				if (!h.empty())
				{
					idref->assignIDREF(propertyOwner, h);
				}
				else
				{
					IDREFItem item = {idref, propertyOwner, h};
					deferredIDREFItems.push_back(item);
				}
				return true;
			}
			else if (valueIDREF->isValueEqual(&value_IDREF_nil))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	};
}
