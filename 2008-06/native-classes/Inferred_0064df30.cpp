// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::ToolMouseCommand::sub_0064df30 (placeholder name for 0064df30 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "v8datamodel/ToolMouseCommand.h"
#include "v8datamodel/Tool.h"

RBX::MouseCommand* RBX::ToolMouseCommand::sub_0064df30(const UIEvent& uiEvent)
{
    updateTargetPoint(uiEvent);
    tool->deactivate();
    return ScriptMouseCommand::onMouseUp(uiEvent);
}
