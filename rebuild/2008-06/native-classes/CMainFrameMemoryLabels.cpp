// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
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
