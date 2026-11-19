// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::ChangeHistoryService::sub_0058c540 (placeholder name for 0058c540 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "v8datamodel/ChangeHistoryService.h"

void RBX::ChangeHistoryService::sub_0058c540(std::string name)
{
	commit(name.c_str());
}
