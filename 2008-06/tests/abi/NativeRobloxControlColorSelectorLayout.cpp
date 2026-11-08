#include <stddef.h>
#include "CRobloxControlColorSelector.h"
// Size from CRuntimeClass 00931c34 and the operator new(0x184) in CreateObject 0044edf0; member
// offsets from constructor 0044ec60, OnExecute 0044e310, GetColor 0044de00 and OnSetSelected
// 0044dde0; base end from CXTPControl (XTP 11.2.2 headers, members end at 0x174).
typedef char RobloxControlColorSelectorSize[sizeof(CRobloxControlColorSelector) == 0x184 ? 1 : -1];
typedef char XTPControlSize[sizeof(CXTPControl) == 0x174 ? 1 : -1];
typedef char ColorInfoSize[sizeof(CRobloxControlColorSelector::CColorInfo) == 12 ? 1 : -1];
struct RobloxControlColorSelectorLayout : CRobloxControlColorSelector {
    static void check()
    {
        typedef char Selected[offsetof(RobloxControlColorSelectorLayout, m_nSelected) == 0x174 ? 1 : -1];
        typedef char Pressed[offsetof(RobloxControlColorSelectorLayout, m_nPressed) == 0x178 ? 1 : -1];
        typedef char Picked[offsetof(RobloxControlColorSelectorLayout, m_bColorPicked) == 0x17c ? 1 : -1];
        typedef char Color[offsetof(RobloxControlColorSelectorLayout, m_clr) == 0x180 ? 1 : -1];
    }
};
