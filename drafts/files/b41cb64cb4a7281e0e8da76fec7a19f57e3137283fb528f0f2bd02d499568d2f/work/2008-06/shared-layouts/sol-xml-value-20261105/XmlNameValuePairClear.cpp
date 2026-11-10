// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Authentic donor: tools/rbxgs/Client/App/v8xml/XmlElement.cpp clearValue.
#include "v8xml/XmlElement.h"
void XmlNameValuePair::clearValue() const
{
    switch (valueType)
    {
    case HANDLE: delete handleValue; break;
    case STRING: delete stringValue; break;
    case CONTENTID: delete contentIdValue; break;
    }
    valueType = NONE;
}
