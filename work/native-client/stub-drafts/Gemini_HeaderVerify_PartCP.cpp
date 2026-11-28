// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8xml/XmlElement.h"
#include "util/ContentProvider.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Seat.h"
typedef char CheckCP[sizeof(RBX::ContentProvider) == 0x19c ? 1 : -1];
typedef char CheckPart[sizeof(RBX::PartInstance) == 0x404 ? 1 : -1];
int gemini_partcp_anchor() { return sizeof(RBX::PartInstance) + sizeof(RBX::ContentProvider); }
