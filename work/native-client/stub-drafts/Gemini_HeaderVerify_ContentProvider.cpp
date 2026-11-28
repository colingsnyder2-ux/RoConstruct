// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8xml/XmlElement.h"
#include "util/ContentProvider.h"
typedef char CheckCPSize[sizeof(RBX::ContentProvider) == 0x19c ? 1 : -1];
typedef char CheckCRSize[sizeof(RBX::ContentRequest) == 0x38 ? 1 : -1];
int gemini_cp_verify_anchor() { return sizeof(RBX::ContentProvider); }
