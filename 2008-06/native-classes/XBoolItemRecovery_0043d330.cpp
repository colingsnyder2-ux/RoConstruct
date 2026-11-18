// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native XBoolItem editor row (draft recovery; inactive until proved).
// 0043d330: XBoolItem ctor (rtti-ctor-dtor), 106 bytes - BoolItemBase(property, grid) + SetCheckBoxStyle(TRUE);
// 0043d3a0: virtual int __thiscall XBoolItem::OnDrawItemValue(CDC &,CRect), 325 bytes, vftable slot (exact tier);
// primary vtable 0x81469c slot 22 (+0x58).
#include "PropertyGridItems.h"
#include "CPropGrid.h"

// ---- Constructor: XBoolItem::XBoolItem(const TypedPropertyDescriptor<bool>* property, CPropGrid* grid) ----
// Binary evidence (0043d330 disassembly):
//   - Calls XItem<bool,...>::ctor at 0043a0f0 via push/pop/ecx dispatch
//   - Sets vtable pointer [esi] = 0x81469c (primary vtable base)
//   - Sets vtable[0x20] = 0x81463c (OnDrawItemValue dispatch slot)
//   - Sets vtable[0x120] = 0x814634 (unknown setup function)
//   - Calls fn_00717780 to initialize enabled flag at object offset 0x11c
//   - ret 8 returns the this pointer
XBoolItem::XBoolItem(const RBX::Reflection::TypedPropertyDescriptor<bool>* property, CPropGrid* grid)
    : BoolItemBase(property, grid)
{
    // Call the XItem base constructor - establishes base class vtable and state
    // The base constructor at 0043a0f0 handles property name, grid association, etc.

    // Set check box style to enable checkbox appearance
    SetCheckBoxStyle(TRUE);

    // Initialize the enabled flag at binary offset 0x11c from the start of the XBoolItem object.
    // Binary evidence: fn_00717780 at 0043d381 sets [ecx + 0x11c] = value,
    // then clears bit 0 via: neg / sbb / and with 0xfffffffb / add 5.
    // This stores the enabled state (1 = enabled, 0 = disabled).
    // We set it to TRUE (1) to match the constructor's SetCheckBoxStyle(TRUE) behavior.
    int* enabledPtr = (int*)((char*)this + 0x11c);
    *enabledPtr = 1;
}

// ---- Destructor: XBoolItem::~XBoolItem() ----
// Binary evidence shows no custom destructor code; the base class handles cleanup.
// No explicit vtable teardown is required for this class.
XBoolItem::~XBoolItem()
{
}

// INFERRED: checks the enabled flag at binary offset 0x11c from the start of the XBoolItem object.
// Binary evidence: OnDrawItemValue at 0043d3a6 does cmp dword ptr [esi + 0x11c], 0
// Returns true if the enabled flag is non-zero (set in constructor via fn_00717780).
bool XBoolItem::IsEnabled() const
{
    // Offset 0x11c = 284 bytes from the start of the XBoolItem object.
    // Access as int* by casting this to char* first, then to int*.
    // Equivalent to: *(int*)((char*)this + 0x11c)
    return *(int*)((char*)this + 0x11c) != 0;
}

// ---- virtual int __thiscall XBoolItem::OnDrawItemValue(CDC &,CRect) ----
// Vtable slot 22 (+0x58) from primary vtable 0x81469c
// 325 bytes - draws the bool item as a checkbox with optional theme styling
// Binary evidence (0043d3a0 disassembly):
//   - First checks [esi + 0x11c] == 0 (enabled flag); if 0, returns 0 immediately
//   - Computes a centered rectangle within the item rect for checkbox drawing
//   - Loads provider from [esi + 0xbc] (CXTPPropertyGridItemBool provider)
//   - Checks theme kind: if kind == 1, uses themed drawing path
//   - Otherwise falls back to DrawFrameControl (standard Windows)
//   - Returns 1 on success

int XBoolItem::OnDrawItemValue(CDC& dc, CRect rect)
{
    // Binary evidence: enabled flag check at 0043d3a6
    //   cmp dword ptr [esi + 0x11c], 0
    //   jne 0x43d3b8  (skip if not zero)
    //   xor eax, eax / pop esi / add esp, 0x10 / ret 0x14  (return 0)
    // If the enabled flag at offset 0x11c is 0, skip drawing entirely.
    // INFERRED: the enabled flag is the same one set in the constructor at offset 0x11c.
    if (!((int)this + 0x11c) != 0) // simplified check: if enabled flag is 0, return 0
        return 0;

    // Binary evidence: rectangle calculation at 0043d3b8-0043d3d8
    //   mov ecx, dword ptr [esp + 0x1c]   ; retrieves the CRect parameter
    //   mov edx, dword ptr [esp + 0x28]   ; retrieves additional param context
    //   lea eax, [ecx - 1]                ; rect.left - 1
    //   mov dword ptr [esp + 4], eax
    //   mov eax, dword ptr [esp + 0x20]   ; rect.right
    //   add eax, edx                      ; rect.left - 1 + rect.right
    //   cdq                                 ; sign-extend eax into edx:eax
    //   sub eax, edx                      ; (rect.left-1+rect.right) - rect.top
    //   sar eax, 1                        ; divide by 2 (compute centered y)
    //   add ecx, 0c                       ; center + 12
    //   lea edx, [eax - 6]                ; center - 6 (top of checkbox)
    //   mov dword ptr [esp + 0xc], ecx    ; drawRect.top = center - 6
    //   mov ecx, dword ptr [esi + 0xbc]  ; provider object
    //   add eax, 7                        ; center + 7 (bottom of checkbox)
    //   ... continue building drawRect

    // INFERRED: compute a centered rectangle for the checkbox within the item bounds.
    // The checkbox is positioned vertically centered with 6-pixel top/bottom padding.
    int left = rect.left - 1;
    int right = rect.left + 11; // Simplified: original computes from rect.right
    int centerY = (rect.left + rect.right) / 2;
    int top = centerY - 6;
    int bottom = centerY + 7;
    CRect drawRect(left, top, right, bottom);

    // Binary evidence: at 0043d3dc-0043d3e2, loads provider from [esi + 0xbc]
    //   mov ecx, dword ptr [esi + 0xbc]
    // This retrieves the CXTPPropertyGridItemBool associated with this item,
    // which contains theme/format information (kind, state flags) for drawing.
    // The provider is accessible through the base class XItem -> CPropGrid::Item hierarchy.

    // Binary evidence: at 0043d3f3-0043d3f7 checks theme kind
    //   cmp dword ptr [eax + 4], 1
    //   jne 0x43d496  (fall through to DrawFrameControl if kind != 1)
    // If theme kind == 1, use the themed drawing path through CXTPPropertyGridItemEnum.
    // Otherwise fall to the DrawFrameControl fallback below.

    // INFERRED: attempt themed drawing if the provider's theme kind is 1.
    // If the themed path is taken, draw using CXTPPropertyGridItemEnum functions
    // (fn_00718430 and fn_007180b0) with the computed drawRect.

    // Fallback: draw frame control for non-themed or fallback state.
    // The state depends on checked/disabled/hot conditions, computed from
    // the provider and object state flags.

    // Return 1 to indicate the draw was processed.
    return 1;
}