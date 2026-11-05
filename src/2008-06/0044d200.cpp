// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: scintilla-mfc-1.20-shared-rtm roc_command_line_parse_94a6fc0d83a45822.cpp

// Candidate translation unit (score above; library headers required).
#include <afxwin.h>
#include <string>
struct ContentId { void operator=(const std::string&); };
void handleNo3D(CStringA);
struct FakeCommandLineInfo { char data[0x28]; void ParseLast(int); void ParseParam(const char*,int,int); };
struct CRobloxCommandLineInfo : FakeCommandLineInfo {
 bool no3D, script; char pad[4]; bool browser, baseUrl; ContentId id;
 void ParseParam(const char*, int, int);
};
void CRobloxCommandLineInfo::ParseParam(const char* pszParam, int bFlag, int bLast) {
 if (no3D) { handleNo3D(pszParam); no3D=false; ParseLast(bLast); return; }
 if (script) { { std::string tmp(pszParam); id=tmp; } script=false; ParseLast(bLast); return; }
 if (bFlag) {
  if (CStringA("No3D").CompareNoCase(pszParam)==0) { baseUrl=true; ParseLast(bLast); return; }
  if (CStringA("Browser").CompareNoCase(pszParam)==0) { browser=true; ParseLast(bLast); return; }
  if (CStringA("BaseUrl").CompareNoCase(pszParam)==0) { no3D=true; ParseLast(bLast); return; }
  if (CStringA("Script").CompareNoCase(pszParam)==0) { script=true; ParseLast(bLast); return; }
 }
 FakeCommandLineInfo::ParseParam(pszParam,bFlag,bLast);
}







