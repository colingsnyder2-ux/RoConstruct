// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2008-06 native XmlNameValuePair::isValueType<RBX::ContentId>() (inactive). v8xml/XmlElement.h declares the member
// template without a body; flags line copied from XmlNameValuePair.cpp. The original sits in the XmlElement object
// (0057c1b0..0057c250, between getValue overloads 0057c1b0 / 0057c210 and findFirstChildByTag 0057c230 of
// XmlElement.cpp), which is not this batch's file, so the specialization is kept in its own unit.
#include "v8xml/XmlElement.h"

// 0057c1f0 ??$isValueType@VContentId@RBX@@@XmlNameValuePair@@QBE_NXZ (registry; callers 0058ecd6 / 0058f29e in the
// XmlSerializer ContentId read path, AppUnit58CXmlSerializer.cpp): valueType (+4) == CONTENTID (3).
template<>
bool XmlNameValuePair::isValueType<RBX::ContentId>() const
{
	return valueType == CONTENTID;
}
