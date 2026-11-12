// from server: 100% by EspClaude
// from server: 51% by colin
// roc 2007-08 00427db0  unit: MainLogManager  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00427db0
//
// 00427db0  6aff                 push -1
// 00427db2  68b7c97300           push 0x73c9b7
// 00427db7  64a100000000         mov eax, dword ptr fs:[0]
// 00427dbd  50                   push eax
// 00427dbe  81ec14040000         sub esp, 0x414
// 00427dc4  a188518b00           mov eax, dword ptr [0x8b5188]
// 00427dc9  33c4                 xor eax, esp
// 00427dcb  89842410040000       mov dword ptr [esp + 0x410], eax
// 00427dd2  56                   push esi
// 00427dd3  57                   push edi
// 00427dd4  a188518b00           mov eax, dword ptr [0x8b5188]
// 00427dd9  33c4                 xor eax, esp
// 00427ddb  50                   push eax
// 00427ddc  8d842420040000       lea eax, [esp + 0x420]
// 00427de3  64a300000000         mov dword ptr fs:[0], eax
// 00427de9  8bb42438040000       mov esi, dword ptr [esp + 0x438]
// 00427df0  8d4c2410             lea ecx, [esp + 0x10]
// 00427df4  e8cd862000           call 0x6304c6
// 00427df9  c744241024a07800     mov dword ptr [esp + 0x10], 0x78a024
// 00427e01  8bbc2434040000       mov edi, dword ptr [esp + 0x434]
// 00427e08  6a00                 push 0
// 00427e0a  6800040000           push 0x400
// 00427e0f  8d442424             lea eax, [esp + 0x24]
// 00427e13  50                   push eax
// 00427e14  8d4c241c             lea ecx, [esp + 0x1c]
// 00427e18  c784243404000000000000 mov dword ptr [esp + 0x434], 0
// 00427e23  897c2424             mov dword ptr [esp + 0x24], edi
// 00427e27  e8ac862000           call 0x6304d8
// 00427e2c  8d4c240c             lea ecx, [esp + 0xc]
// 00427e30  ff15acdd7700         call dword ptr [0x77ddac]
// 00427e36  8b8c243c040000       mov ecx, dword ptr [esp + 0x43c]
// 00427e3d  51                   push ecx
// 00427e3e  56                   push esi
// 00427e3f  8d542424             lea edx, [esp + 0x24]
// 00427e43  52                   push edx
// 00427e44  57                   push edi
// 00427e45  8d44241c             lea eax, [esp + 0x1c]
// 00427e49  6860a07800           push 0x78a060
// 00427e4e  50                   push eax
// 00427e4f  c684244004000001     mov byte ptr [esp + 0x440], 1
// 00427e57  ff1594dd7700         call dword ptr [0x77dd94]
// 00427e5d  83c418               add esp, 0x18
// 00427e60  8d4c240c             lea ecx, [esp + 0xc]
// 00427e64  ff1598dd7700         call dword ptr [0x77dd98]
// 00427e6a  8b8c2430040000       mov ecx, dword ptr [esp + 0x430]
// 00427e71  50                   push eax
// 00427e72  51                   push ecx
// 00427e73  e8c8fdffff           call 0x427c40
// 00427e78  83c408               add esp, 8
// 00427e7b  8d4c240c             lea ecx, [esp + 0xc]
// 00427e7f  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00427e85  8b8c2420040000       mov ecx, dword ptr [esp + 0x420]
// 00427e8c  64890d00000000       mov dword ptr fs:[0], ecx
// 00427e93  59                   pop ecx
// 00427e94  5f                   pop edi
// 00427e95  5e                   pop esi
// 00427e96  8b8c2410040000       mov ecx, dword ptr [esp + 0x410]
// 00427e9d  33cc                 xor ecx, esp
// 00427e9f  e87a8b2000           call 0x630a1e
// 00427ea4  81c420040000         add esp, 0x420
// 00427eaa  c3                   ret 

// MFC 8.0 (MFC80.DLL) declarations consumed here; CException/COleException
// members are reached through import thunks (no dllimport), CStringT through the IAT.
typedef int BOOL;
typedef unsigned int UINT;
typedef long SCODE;
typedef unsigned short WORD;
typedef char* LPTSTR;
typedef const char* LPCTSTR;
typedef unsigned int* PUINT;

struct CRuntimeClass;
class CArchive;
class CDumpContext;

class __declspec(novtable) CObject {
public:
    virtual CRuntimeClass* GetRuntimeClass() const;
    virtual ~CObject() = 0;
    virtual void Serialize(CArchive& ar);
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
protected:
    CObject() {}
};
inline CObject::~CObject() {}

class __declspec(novtable) CException : public CObject {
public:
    CException();                                                   // MFC80 #380
    virtual BOOL GetErrorMessage(LPTSTR lpszError, UINT nMaxError, PUINT pnHelpContext = 0) const;
    virtual BOOL GetErrorMessage(LPTSTR lpszError, UINT nMaxError, PUINT pnHelpContext = 0);
    virtual int ReportError(UINT nType = 0, UINT nMessageID = 0);
    virtual ~CException() = 0;
    BOOL m_bAutoDelete;
};
inline CException::~CException() {}

class COleException : public CException {
public:
    SCODE m_sc;                                                     // +8
    COleException() { m_sc = 0; }
    virtual ~COleException() {}
    virtual BOOL GetErrorMessage(LPTSTR lpszError, UINT nMaxError, PUINT pnHelpContext = 0) const;  // MFC80 #2706
};

class CString {
public:
    __declspec(dllimport) CString();                                // #310
    __declspec(dllimport) ~CString() throw();                             // #578
    __declspec(dllimport) void __cdecl Format(LPCTSTR pszFormat, ...);   // #2322
    __declspec(dllimport) operator LPCTSTR() const;                 // #876
private:
    char* m_pszData;
};

class LogManager {
public:
    static void ReportEvent(WORD type, LPCTSTR message);            // 00427c40
    static void ReportEvent(WORD type, int hr, LPCTSTR fileName, int lineNumber);
};

void LogManager::ReportEvent(WORD type, int hr, LPCTSTR fileName, int lineNumber)
{
    COleException e;
    e.m_sc = hr;
    char msg[1024];
    e.GetErrorMessage(msg, 1024);

    CString s;
    s.Format("HRESULT = %d: %s\n%s(%d)", hr, msg, fileName, lineNumber);
    ReportEvent(type, s);
}
