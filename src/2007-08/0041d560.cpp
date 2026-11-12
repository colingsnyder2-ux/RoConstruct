// from server: 100% by EspClaude
// from server: 58% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: openrbx-client roc_claude_62718e8df79c6344.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog for 2007-08 0041d560, CInsertObjectDialog(CWnd *pParent):
//   CDialog(0x6b, pParent) by direct call (MFC80 import thunk 00630418),
//   vtable store, then a CString member at +0x74 constructed from a string
//   through MFC80's IAT (ordinal 354). MFC headers are not on this recipe's
//   include path, so stand-ins declare only what those bytes show: a
//   polymorphic CDialog base whose members end at +0x74 (first own member
//   offset) and a dllimported CString with a const char * constructor.
class CWnd;

class CDialog
{
public:
	CDialog(unsigned int nIDTemplate, CWnd *pParentWnd);
	virtual ~CDialog();
private:
	char m_rocBaseBody[0x74 - 4];
};

class __declspec(dllimport) CString
{
public:
	CString(const char *psz);
	~CString();
private:
	char *m_pszData;
};

class CInsertObjectDialog : public CDialog
{
public:
	enum { IDD = 0x6b };
	CInsertObjectDialog(CWnd *pParent = 0);
	CString m_className;
};

CInsertObjectDialog::CInsertObjectDialog(CWnd *pParent)
	: CDialog(IDD, pParent), m_className("")
{
}
