// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
#undef _RELEASEASSERT
// 2008-06 native RBX::Surface::readValue (inactive), the legacy per-surface XML reader.
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surface.h"
#include "v8xml/XmlElement.h"
#include "reflection/enumconverter.h"
#include "util/Name.h"

namespace RBX
{
	// 005f17a0 (registry func_005f17a0): Surface::readValue(const XmlElement*, IReferenceBinder&).
	// Identity: it follows Surface::flat 005f1690 in the Surface.cpp address range (005f1290 getSurfaceType ..
	// 005f1690 flat), is a __thiscall with two stack arguments (ret 8, matching v8datamodel/Surface.h), and
	// calls exactly the Surface setters setSurfaceType 005f13e0, setSurfaceInput 005f1430, setParamA 005f14f0 and
	// setParamB 005f15c0. Five guarded function-local statics (guard 0097b5b4 bits 1..0x10) are filled by
	// Name::declare 00553f90 in donor order (Type, SurfaceInput, ParamA, ParamB, Constraint); the child walk uses
	// XmlElement::isXsiNil 0057c810, findAttribute 0057c2b0 (name_name 00975338) and the XmlNameValuePair getValue
	// overloads 0057c360 / 0057c210 (string) / 0057c610 (float). Body follows donor v8datamodel/Surface.cpp.
	// 2008 difference: the string branches look the enum up via Name::lookup(const char*) 00554290 on the
	// string's c_str (not Name::lookup(const std::string&) 00554180) before EnumDesc::convertToValue(const Name&)
	// 005ed300. The Constraint branch instead calls an out-of-line EnumDesc<SurfaceType>::convertToValue taking
	// const char* (005ed800, which itself does lookup + 005ed300): that overload is missing from core
	// reflection/enumconverter.h (proposal), so this branch spells the same lookup inline here.
	void Surface::readValue(const XmlElement* element, IReferenceBinder& binder)
	{
		static const Name& desc_LegacyType = Name::declare("Type", -1);
		static const Name& desc_LegacySurfaceInput = Name::declare("SurfaceInput", -1);
		static const Name& desc_LegacyParamA = Name::declare("ParamA", -1);
		static const Name& desc_LegacyParamB = Name::declare("ParamB", -1);
		static const Name& desc_LegacyConstraint = Name::declare("Constraint", -1);

		const XmlElement* child = element->firstChild();
		while (child)
		{
			const Name* name = NULL;
			if (!child->isXsiNil() && child->findAttributeValue(name_name, name))
			{
				if (name == &desc_LegacyType)
				{
					std::string sValue;
					if (child->getValue(sValue))
					{
						SurfaceType e;
						if (Reflection::EnumDesc<SurfaceType>::singleton().convertToValue(Name::lookup(sValue.c_str()), e))
							setSurfaceType(e);
						else
							setSurfaceType(NO_SURFACE);
					}
				}
				else if (name == &desc_LegacySurfaceInput)
				{
					std::string sValue;
					if (child->getValue(sValue))
					{
						Controller::InputType e;
						if (Reflection::EnumDesc<Controller::InputType>::singleton().convertToValue(Name::lookup(sValue.c_str()), e))
							setSurfaceInput(e);
					}
				}
				else if (name == &desc_LegacyParamA)
				{
					float value;
					if (child->getValue(value))
						setParamA(value);
				}
				else if (name == &desc_LegacyParamB)
				{
					float value;
					if (child->getValue(value))
						setParamB(value);
				}
				else if (name == &desc_LegacyConstraint)
				{
					std::string sValue;
					if (child->getValue(sValue))
					{
						SurfaceType e;
						if (Reflection::EnumDesc<SurfaceType>::singleton().convertToValue(Name::lookup(sValue.c_str()), e) && e != NO_SURFACE)
							setSurfaceType(e);
					}
				}
			}
			child = child->nextSibling();
		}
	}
}
