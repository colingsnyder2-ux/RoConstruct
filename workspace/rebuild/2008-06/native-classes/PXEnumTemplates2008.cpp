// native-flags: /O2 /Ob1 /GS- /EHsc /MD /D_AFXDLL /D_DLL /D_LIB /D_XTP_STATICLINK /I{headers}/../../../work/native-client/xtp-shadow /I{headers}/../../../tools/libs/xtp-11.2.2/Source /FICommon/XTPDLLExports.h /FIXTToolkitPro.h /I{headers}/../../../tools/libs/xtp-11.2.2/Source/Calendar /I{headers}/../../../tools/libs/xtp-11.2.2/Source/TaskPanel
// 2008-06 native Codejock PX_Enum<TEnum> instances (inactive): vendor Common/XTPPropExchange.h template (read-only,
// xtp-11.2.2), a tail call into PX_Int(pPX, name, (int&)value, (int)default); the exe keeps one 5-byte jmp thunk each.
//   XTPCalendarPatternEnd 00417b30, XTPTaskPanelItemLayout 00445b50, XTPTaskPanelItemType 00447e00
#include "Common/XTPPropExchange.h"
#include "Calendar/XTPCalendarDefines.h"
#include "TaskPanel/XTPTaskPanelDefines.h"

template BOOL AFX_CDECL PX_Enum<XTPCalendarPatternEnd>(CXTPPropExchange*, LPCTSTR, XTPCalendarPatternEnd&, XTPCalendarPatternEnd);
template BOOL AFX_CDECL PX_Enum<XTPTaskPanelItemLayout>(CXTPPropExchange*, LPCTSTR, XTPTaskPanelItemLayout&, XTPTaskPanelItemLayout);
template BOOL AFX_CDECL PX_Enum<XTPTaskPanelItemType>(CXTPPropExchange*, LPCTSTR, XTPTaskPanelItemType&, XTPTaskPanelItemType);
