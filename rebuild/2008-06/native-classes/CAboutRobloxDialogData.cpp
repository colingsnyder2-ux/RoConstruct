// >>> native-status (generated) -- do not edit >>>
// CAboutRobloxDialogData | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (deepseek:deepseek-chat)
// <<< native-status | src ce144ce4 | roc native-status --write
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
