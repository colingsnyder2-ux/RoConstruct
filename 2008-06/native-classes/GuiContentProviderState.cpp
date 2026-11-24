#include "util/NativeContentProvider.h"

namespace RBX {
// 00974d74: the ContentProvider used while the GUI is built (set and cleared by CRobloxWnd::finishAttach 0045ead0)
ContentProvider* guiContentProvider = NULL;
}
