// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// CRobloxWnd::finishAttach (0045ead0) - native 2008-06.
// Layout (native-headers/CRobloxView.h): dataModelPtr at 0x70, adorn (G3D::GWindow*) at 0xa4, slot_b4 at 0xb4.
// Identities (work/2008-06/identity-registry.json): 0096eff4 = G3D::GWindow::m_current, so the first block is the
// inline gWindow->makeCurrent() (vtable +0x98 reallyMakeCurrent); 0041eea0 = ServiceProvider::create<ContentProvider>()
// const (the null test before the call is the inline static create(const ServiceProvider*) of v8tree/Service.h);
// 00974d74 = RBX::guiContentProvider (GuiContentProviderState.cpp); 005756e0 = DataModel::buildGui(Adorn*) on +0x70
// with the +0xb4 word. Caller: CRobloxView::OnInitialUpdate 0045a4a0.
#include "../native-headers/CRobloxView.h"
#include "GLG3D/GWindow.h"
// RBX::ContentProvider: only the name is needed (CRobloxView.h already sees util/ContentProvider.h).
#include "v8datamodel/DataModel.h"

namespace RBX
{
	extern ContentProvider* guiContentProvider;   // 00974d74
	class Adorn;
	class ContentProvider;
}

// 0045ead0
void CRobloxWnd::finishAttach()
{
	adorn->makeCurrent();
	RBX::guiContentProvider = RBX::ServiceProvider::create<RBX::ContentProvider>(dataModelPtr.get());
	// INFERRED: +0xb4 (CRobloxView.h slot_b4) is the Adorn* that 005756e0 DataModel::buildGui takes.
	dataModelPtr->buildGui(static_cast<RBX::Adorn*>(slot_b4));
	RBX::guiContentProvider = NULL;
}
