// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
//
// RBX::Reflection::RefPropDescriptor<Class, ReturnType>::readValue / writeValue: XML referent I/O through
// IReferenceBinder. Out-of-class template definitions harvested per class by work/donorfree-route/tmplinst.py --rbx.
// Kept apart from RefPropDescriptorMembers.cpp (other lease). Not a class swap; no match claim.
//
// readValue: byte-proved for <Instance,Instance> at 004914b0 (Inferred_004914b0.cpp):
//   binder.announceIDREF(element, instance, this)   (this converted to the IIDREF base).
// writeValue: 00491760 reads the value via getset->getValue (vtable slot 2), wraps it in an InstanceHandle
//   (shared_ptr add-ref helper) and stores it in the element with XmlNameValuePair::setValue(InstanceHandle).
// INFERRED: setValue(InstanceHandle) is the 004915e0 callee (allocates a handle copy, sets type 8).
// STATUS: readValue and writeValue are both byte-exact for <Instance,Instance> (004914b0 / 00491760).
// INFERRED: the empty inline ~Local_RefIO_Handle makes the handle non-trivial, which reproduces the original's callee-destroyed
// by-value argument bookkeeping (mov [esp+0xc], esp). The element base is reached with a member call (no null test).
#include "v8datamodel/MergeBinder2008.h"
#include "v8tree/Instance.h"
#include "util/Name.h"
#include "v8xml/XmlElement.h"

namespace RBX
{
	// INFERRED: 00491760 builds the InstanceHandle through the out-of-line ctor 00594e00 (thiscall, one stack arg) directly
	// in the outgoing argument slot, and passes it to the out-of-line XmlNameValuePair::setValue(InstanceHandle) 004915e0
	// (callee destroys the by-value handle). Modelled with a file-local 8-byte handle (same layout as InstanceHandle).
	struct Local_RefIO_Handle
	{
		void* ptr;
		void* count;
		Local_RefIO_Handle(Instance*);
		Local_RefIO_Handle(const Local_RefIO_Handle&);   // never defined: elided
		~Local_RefIO_Handle() {}
	};
	struct Local_RefIO_NameValue { void setValue(Local_RefIO_Handle); };   // XmlNameValuePair::setValue(InstanceHandle) 004915e0 (thiscall)
	// INFERRED: 00491760 adds 0x10 (no null test) to reach XmlNameValuePair inside XmlElement before the member call.
	struct Local_RefIO_Pad { char pad[0x10]; };
	struct Local_RefIO_Element : Local_RefIO_Pad, Local_RefIO_NameValue {};
	namespace Reflection
	{
		template<typename Class, typename ReturnType>
		void RefPropDescriptor<Class, ReturnType>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			binder.announceIDREF(element, instance, this);
		}

		template<typename Class, typename ReturnType>
		void RefPropDescriptor<Class, ReturnType>::writeValue(const DescribedBase* instance, XmlElement* element) const
		{
			reinterpret_cast<Local_RefIO_Element*>(element)->setValue(Local_RefIO_Handle(getset->getValue(instance)));
		}

		// 00491760: RefPropDescriptor<Instance, Instance>::writeValue (registry
		// ?writeValue@?$RefPropDescriptor@VInstance@RBX@@V12@@Reflection@RBX@@UBEXPBVDescribedBase@23@PAVXmlElement@3@@Z),
		// emitted by member explicit instantiation as RefPropDescriptorAssignIDREF.cpp does for assignIDREF.
		template void RefPropDescriptor<Instance, Instance>::writeValue(const DescribedBase*, XmlElement*) const;

	}
}

#pragma comment(linker, "/alternatename:??0Local_RefIO_Handle@RBX@@QAE@PAVInstance@1@@Z=_fn_00594e00")
#pragma comment(linker, "/alternatename:?setValue@Local_RefIO_NameValue@RBX@@QAEXULocal_RefIO_Handle@2@@Z=_fn_004915e0")
