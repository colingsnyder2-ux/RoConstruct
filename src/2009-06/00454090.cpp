// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef unsigned int UINT;
class CStringA2009 {
public:
	__declspec(dllimport) CStringA2009() throw();
	__declspec(dllimport) ~CStringA2009() throw();
	__declspec(dllimport) int LoadString(UINT nID);
	__declspec(dllimport) operator const char*() const throw();
	char* m_pszData;
};
int __stdcall AfxMessageBox(UINT nIDPrompt, UINT nType, UINT nIDHelp);
void logMessage2009(int level, const char* msg);
extern bool silentMode2009;
int RobloxMessageBox2009(UINT nIDPrompt, UINT nType, UINT nIDHelp)
{
	if (!silentMode2009)
		return AfxMessageBox(nIDPrompt, nType, nIDHelp);
	CStringA2009 s;
	s.LoadString(nIDPrompt);
	logMessage2009(4, s);
	return 0;
}
