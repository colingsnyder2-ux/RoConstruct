// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// CMainFrameMemoryLabels | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | 3 referenced strings (not rechecked) | by colin
// <<< native-status | src cccf0af9 | roc native-status --write
#include "CMainFrame.h"
#include "util/Log.h"
#include <GLG3D/Texture.h>
#include <GLG3D/VARArea.h>

void CMainFrame::handle_42ed20(CCmdUI* ui)
{
    std::string value = RBX::Log::formatMem(G3D::VARArea::sizeOfAllVARAreasInMemory());
    CString text;
    text.Format("VAR %s", value.c_str());
    ui->SetText(text);
}

void CMainFrame::handle_42edd0(CCmdUI* ui)
{
    std::string value = RBX::Log::formatMem(G3D::Texture::sizeOfAllTexturesInMemory());
    CString text;
    text.Format("TEX %s", value.c_str());
    ui->SetText(text);
}
