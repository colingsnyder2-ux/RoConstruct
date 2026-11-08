#include <stddef.h>
#include "CPatchedControlComboBox.h"
// Size from CRuntimeClass 0092ecc8 and operator new(0x1e0) in CreateObject 0042fd50; the base is
// CXTPControlComboBox (XTP 11.2.2 headers) whose members end at 0x1e0; the secondary
// CXTPAccessible subobject sits at +0x20 (RTTI base descriptor, ctor vptr store).
typedef char PatchedControlComboBoxSize[sizeof(CPatchedControlComboBox) == 0x1e0 ? 1 : -1];
typedef char XTPControlComboBoxSize[sizeof(CXTPControlComboBox) == 0x1e0 ? 1 : -1];
// CXTPControl : CXTPCmdTarget, CXTPAccessible, so the CXTPAccessible subobject starts at sizeof(CXTPCmdTarget).
typedef char AccessibleOffset[sizeof(CXTPCmdTarget) == 0x20 ? 1 : -1];
