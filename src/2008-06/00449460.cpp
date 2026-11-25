// from server: 100% by Xemicl
﻿// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
class CString {
public:
    __declspec(dllimport) CString();
    __declspec(dllimport) ~CString();
    __declspec(dllimport) void __cdecl Format(const char* format, ...);
    __declspec(dllimport) operator const char*() const;
private:
    char* m_pszData;
};

class CException {
public:
    virtual void* GetRuntimeClass() const;
    virtual ~CException();
    virtual void Serialize(void*);
    virtual void Slot3();
    virtual void Slot4();
    virtual int GetErrorMessage(char* lpszError, unsigned int nMaxError, unsigned int* pnHelpContext = 0);
};

class CWinApp {
public:
    void EndWaitCursor();
};

struct AFX_MODULE_STATE {
    void* m_pClassInit;
    CWinApp* m_pCurrentWinApp;
};

AFX_MODULE_STATE* __stdcall AfxGetModuleState();
int __stdcall AfxMessageBox(const char* lpszText, unsigned int nType = 0, unsigned int nIDHelp = 0);

inline CWinApp* AfxGetApp() { return AfxGetModuleState()->m_pCurrentWinApp; }

class CWaitCursor {
public:
    ~CWaitCursor();
};

CWaitCursor::~CWaitCursor()
{
    try {
        AfxGetApp()->EndWaitCursor();
    } catch (CException* pException) {
        do {
            CString strMsg;
            char szErrorMessage[512];
            if (pException->GetErrorMessage(szErrorMessage, sizeof(szErrorMessage) / sizeof(*szErrorMessage), 0))
                strMsg.Format("%s (%s:%d)\n%s", "Exception thrown in destructor",
                    "C:\\Program Files\\Microsoft Visual Studio 9.0\\VC\\atlmfc\\include\\afxwin2.inl", 1175, szErrorMessage);
            else
                strMsg.Format("%s (%s:%d)", "Exception thrown in destructor",
                    "C:\\Program Files\\Microsoft Visual Studio 9.0\\VC\\atlmfc\\include\\afxwin2.inl", 1175);
            AfxMessageBox(strMsg);
        } while (0);
        delete pException;
    }
}
