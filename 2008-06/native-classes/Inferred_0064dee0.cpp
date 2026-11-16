// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::ToolMouseCommand::sub_0064dee0 (placeholder name for 0064dee0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "v8datamodel/ToolMouseCommand.h"
#include "V8DataModel/Tool.h"

RBX::MouseCommand* RBX::ToolMouseCommand::sub_0064dee0(const RBX::UIEvent& uiEvent)
{
    updateTargetPoint(uiEvent);
    tool->activate();
    return ScriptMouseCommand::onMouseDown(uiEvent);
}
