// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "CRobloxReportView.h"
#include "gui/ScoreHud.h"
#include "v8tree/InstanceEvents.h"
// Reuse the existing ChildRemoved declaration and its proven event ABI.
#include "CRobloxReportView.h"
namespace RBX {
void ScoreHud::onEvent(const Instance*, ChildAdded) {}
void ScoreHud::onEvent(const Instance*, ChildRemoved) {}
}
