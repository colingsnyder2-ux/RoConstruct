#include "CBrowserDoc.h"

// CNullDoc: CRuntimeClass 00812410 (GetRuntimeClass 004332e0, CreateObject 00433310). The constructor is inline in
// the header; the scalar deleting destructor 0040e4d0 is emitted with the vtable.
IMPLEMENT_DYNCREATE(CNullDoc, CDocument)

// Message map 0081242c: three CN_UPDATE_COMMAND_UI entries (0081243x) sharing handler 004332f0.
// 0x80B6 is an observed resource command ID (Roblox-defined); its symbolic name is unknown.
BEGIN_MESSAGE_MAP(CNullDoc, CDocument)
    ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateDisabledCommand)
    ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateDisabledCommand)
    ON_UPDATE_COMMAND_UI(0x80B6, OnUpdateDisabledCommand)
END_MESSAGE_MAP()

// 004332f0: pCmdUI->vtbl[0](FALSE) = CCmdUI::Enable(FALSE). Original name unknown.
void CNullDoc::OnUpdateDisabledCommand(CCmdUI* command)
{
    command->Enable(FALSE);
}
