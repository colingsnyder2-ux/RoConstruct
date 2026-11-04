#include <stddef.h>
#include "CWrapperView.h"

typedef char WrapperViewBaseSize[sizeof(CView) == 0x58 ? 1 : -1];
typedef char WrapperViewTreeSize[sizeof(CSelectionTreeCtrl) == 0x130 ? 1 : -1];
typedef char WrapperViewTreeOffset[offsetof(CWrapperView, tree) == 0x58 ? 1 : -1];
typedef char WrapperViewHandleOffset[offsetof(CWnd, m_hWnd) == 0x20 ? 1 : -1];
typedef char WrapperViewSize[sizeof(CWrapperView) == 0x188 ? 1 : -1];
