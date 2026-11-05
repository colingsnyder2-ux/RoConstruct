// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: xtp-11.2.2-lib-strlen roc_about_native_dhtml_html_79ce9ad77dc69b53.cpp

// Candidate translation unit (score above; library headers required).
#include <XTToolkitPro.h>
#include <afxdhtml.h>
#include <afxpriv.h>
#include <string>
#include <gl/gl.h>
// Native exact0046a200 establishes this external file-version object's20B
// member layout. Its constructor, Create and destructor stay external.
class FileVersionInfo {
 WORD language,codePage;LPBYTE versionData;LPVOID translation;UINT translations;VS_FIXEDFILEINFO* fixedInfo;
 public: FileVersionInfo();~FileVersionInfo();BOOL Create(const CString&);CString productVersion()const;
};
typedef char VersionExtent[(sizeof(FileVersionInfo)==20)?1:-1];
void __cdecl systemDescription(std::string&);
const std::string& __cdecl glVersion();
const std::string& __cdecl driverVersion();
const std::string& __cdecl vendor();
const std::string& __cdecl renderer();
// Target imports the native CRT member through IAT802464.
extern const char* (__thiscall* native_c_str)(const std::string*);
// RTTI confirms CDHtmlDialog primary base at0. This method uses no unknown
// CRobloxDHtmlDialog fields and does not allocate the complete dialog.
class AboutDialogEntry:public CDHtmlDialog {public:virtual void DoDataExchange(CDataExchange*);};
void AboutDialogEntry::DoDataExchange(CDataExchange* pDX) {
 if(!pDX->m_bSaveAndValidate) {
  FileVersionInfo version;
  CString filename;
  AfxGetModuleShortFileName(AfxGetApp()->m_hInstance,filename);
  version.Create(filename);
  CString product=version.productVersion();
  DDX_DHtml_ElementText(pDX,"Version",DISPID_IHTMLELEMENT_INNERHTML,product);
  std::string info;
  systemDescription(info);
  DDX_DHtml_ElementText(pDX,"systemInfo",DISPID_IHTMLELEMENT_INNERHTML,CString(native_c_str(&info)));
  if(glGetString(GL_VENDOR)) {
   CString gl=native_c_str(&glVersion());
   DDX_DHtml_ElementText(pDX,"glVersion",DISPID_IHTMLELEMENT_INNERHTML,gl);
   CString driver=native_c_str(&driverVersion());
   DDX_DHtml_ElementText(pDX,"driverVersion",DISPID_IHTMLELEMENT_INNERHTML,driver);
   CString vendorText=native_c_str(&vendor());
   DDX_DHtml_ElementText(pDX,"vendor",DISPID_IHTMLELEMENT_INNERHTML,vendorText);
   CString rendererText=native_c_str(&renderer());
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
