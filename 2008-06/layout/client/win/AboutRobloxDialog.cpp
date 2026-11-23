// =============================================================================
// AboutRobloxDialog.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/AboutRobloxDialog.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "CAboutRobloxDialog.h"
#include "CFileVersionInfo.h"
#include <afxpriv.h>
#include <G3D/System.h>
#include <GLG3D/GLCaps.h>
#include <gl/gl.h>

// Adopted existing native data-exchange recovery with typed shared dependencies.
void CAboutRobloxDialog::DoDataExchange(CDataExchange* pDX) {
 if(!pDX->m_bSaveAndValidate) {
  CFileVersionInfo version;
  CString filename;
  AfxGetModuleShortFileName(AfxGetApp()->m_hInstance,filename);
  version.Create(filename);
  CString product=version.GetFileVersion();
  DDX_DHtml_ElementText(pDX,"Version",DISPID_IHTMLELEMENT_INNERHTML,product);
  std::string info;
  G3D::System::describeSystem(info);
  DDX_DHtml_ElementText(pDX,"systemInfo",DISPID_IHTMLELEMENT_INNERHTML,CString(info.c_str()));
  if(glGetString(GL_VENDOR)) {
   CString gl=G3D::GLCaps::glVersion().c_str();
   DDX_DHtml_ElementText(pDX,"glVersion",DISPID_IHTMLELEMENT_INNERHTML,gl);
   CString driver=G3D::GLCaps::driverVersion().c_str();
   DDX_DHtml_ElementText(pDX,"driverVersion",DISPID_IHTMLELEMENT_INNERHTML,driver);
   CString vendorText=G3D::GLCaps::vendor().c_str();
   DDX_DHtml_ElementText(pDX,"vendor",DISPID_IHTMLELEMENT_INNERHTML,vendorText);
   CString rendererText=G3D::GLCaps::renderer().c_str();
   DDX_DHtml_ElementText(pDX,"renderer",DISPID_IHTMLELEMENT_INNERHTML,rendererText);
  }else {
   CComPtr<IHTMLElement> element;
   if(GetElement("glInfo",&element)==S_OK) {
    CComPtr<IHTMLStyle> style;
    element->get_style(&style);
    style->put_display(CComBSTR("none"));
   }
  }
 }
}

IMPLEMENT_DYNCREATE(CAboutRobloxDialog, CRobloxDHtmlDialog)

BEGIN_MESSAGE_MAP(CAboutRobloxDialog, CRobloxDHtmlDialog)
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(CAboutRobloxDialog)
    DHTML_EVENT_ONCLICK("ButtonOK", OnClickedButtonOK)
END_DHTML_EVENT_MAP()

CAboutRobloxDialog::CAboutRobloxDialog(CWnd* parent)
    : CRobloxDHtmlDialog(117, 118, parent)
{
    SetHostFlags(m_dwHostFlags | 0x01844007);
}

CAboutRobloxDialog::~CAboutRobloxDialog()
{
}

BOOL CAboutRobloxDialog::OnInitDialog()
{
    CRobloxDHtmlDialog::OnInitDialog();
    return TRUE;
}

void CAboutRobloxDialog::OnDocumentComplete(LPDISPATCH browser, LPCTSTR location)
{
    CDHtmlDialog::OnDocumentComplete(browser, location);
    UpdateData(FALSE);
}

HRESULT CAboutRobloxDialog::OnClickedButtonOK(IHTMLElement*)
{
    OnOK();
    return S_OK;
}
