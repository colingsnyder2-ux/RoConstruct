// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_74998b13fc66ee74.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/thread/mutex.hpp>
#include <string>
class CScintillaCtrl {
public:
    int GetModify(int bDirect = 1);
    int GetLength(int bDirect = 1);
    void GetText(int length, char* text);
    void SetSavePoint(int bDirect = 1);
};
class CStringA {
    char* m_pszData;
public:
    __declspec(dllimport) CStringA() throw();
    __declspec(dllimport) ~CStringA() throw();
    __declspec(dllimport) char* GetBuffer(int nMinBufferLength, int flag);
    __declspec(dllimport) void ReleaseBuffer(int nNewLength = -1);
    __declspec(dllimport) operator const char*() const throw();
};
class Script {
public:
    void setSource(const std::string& source);
};
class CScriptDoc {
    char padding0[0x138];
    boost::mutex* mutex;
    char padding1[8];
    Script* script;
    char padding2[12];
    bool busy;
public:
    CScintillaCtrl& GetCtrl();
    void f();
};
void CScriptDoc::f()
{
    if (GetCtrl().GetModify() && !busy) {
        if (script) {
            boost::mutex::scoped_lock lock(*mutex);
            int length = GetCtrl().GetLength();
            CStringA text;
            GetCtrl().GetText(length + 1, text.GetBuffer(length + 1, 1));
            text.ReleaseBuffer();
            std::string source(text);
            script->setSource(source);
        }
        GetCtrl().SetSavePoint();
    }
}
