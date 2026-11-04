#include <stddef.h>
#include "CPropertyGridItemBrickColor.h"
// Size: XItem<RBX::BrickColor, CPropertyGridItemBrickColor, ...> constructor 0043b400 builds its
// CPropGrid::Item base at +0x118 right after constructor 00437ae0, so the row ends at 0x118 (no own
// fields). Offsets: constructor 00437ae0 (CXTPAccessible vptr 008135e4 at +0x20, +0x8c flags, +0xa4/+0xa8 strings, +0x10c color),
// GetColor 0043a1c0 (+0x10c), OnInplaceButtonDown 004382b0 (+0xbc grid view).
typedef char BrickColorSize[sizeof(CPropertyGridItemBrickColor) == 0x118 ? 1 : -1];
typedef char ColorItemSize[sizeof(CXTPPropertyGridItemColor) == 0x118 ? 1 : -1];
struct PropertyGridItemBrickColorLayout : CPropertyGridItemBrickColor {
    static void check()
    {
        typedef char Flags[offsetof(PropertyGridItemBrickColorLayout, m_nFlags) == 0x8c ? 1 : -1];
        typedef char Value[offsetof(PropertyGridItemBrickColorLayout, m_strValue) == 0xa4 ? 1 : -1];
        typedef char Default[offsetof(PropertyGridItemBrickColorLayout, m_strDefaultValue) == 0xa8 ? 1 : -1];
        typedef char Grid[offsetof(PropertyGridItemBrickColorLayout, m_pGrid) == 0xbc ? 1 : -1];
        typedef char Color[offsetof(PropertyGridItemBrickColorLayout, m_clrValue) == 0x10c ? 1 : -1];
    }
};
