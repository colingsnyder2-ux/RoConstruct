// from server: 100% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>

template <class T> class bstr {
public:
    __declspec(noinline) bstr() { _Mysize = 0; }
    __declspec(noinline) bstr(const T* s) { _Mysize = 0; }
    __declspec(noinline) bstr(const bstr& r) { _Mysize = r._Mysize; }
    __declspec(noinline) ~bstr() { _Mysize = 0; }
    __declspec(noinline) bstr& operator=(const bstr& r) { _Mysize = r._Mysize; return *this; }
    __declspec(noinline) const T* c_str() const { return _Buf; }
    __declspec(noinline) bstr substr(unsigned int off, unsigned int count) const { return *this; }
    void* _Myaux;
    T _Buf[16];
    unsigned int _Mysize;
    unsigned int _Myres;
};
extern template class __declspec(dllimport) bstr<char>;
typedef bstr<char> string_;
__declspec(dllimport) string_ operator+(const string_&, const char*);

template <class T> class CStringT_ {
public:
    __declspec(noinline) CStringT_() { m_pszData = 0; }
    __declspec(noinline) ~CStringT_() throw() { m_pszData = 0; }
    __declspec(noinline) operator const T*() const throw() { return m_pszData; }
    __declspec(noinline) int GetLength() const { return 0; }
    __declspec(noinline) T* GetBuffer(int n) { return m_pszData; }
    __declspec(noinline) void ReleaseBuffer(int n = -1) { }
    T* m_pszData;
};
extern template class __declspec(dllimport) CStringT_<char>;
typedef CStringT_<char> CString;
CString operator+(const CString& a, const char* b);

typedef void* HANDLE;
struct FILETIME { unsigned long lo, hi; };
struct WIN32_FIND_DATAA {
    unsigned long dwFileAttributes;
    FILETIME ftCreationTime, ftLastAccessTime, ftLastWriteTime;
    unsigned long nFileSizeHigh, nFileSizeLow, dwReserved0, dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};
extern "C" __declspec(dllimport) HANDLE __stdcall FindFirstFileA(const char*, WIN32_FIND_DATAA*);
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(HANDLE, WIN32_FIND_DATAA*);
extern "C" __declspec(dllimport) char* __stdcall PathAddBackslashA(char*);
#define INVALID_HANDLE_VALUE ((HANDLE)(long)-1)
#define FILE_ATTRIBUTE_DIRECTORY 0x10

string_ archiveFile(const char* file, string_ folder);

class LogManager { public: CString getLogPath(); };

class RobloxCrashReporter {
public:
    void* vptr;
    LogManager logManager;
    std::vector<string_> getDumpFiles();
};

std::vector<string_> RobloxCrashReporter::getDumpFiles()
{
    std::vector<string_> files;
    CString path = logManager.getLogPath();
    PathAddBackslashA(path.GetBuffer(path.GetLength() + 1));
    path.ReleaseBuffer();
    WIN32_FIND_DATAA findData;
    HANDLE h = FindFirstFileA(path + "*.dmp", &findData);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                files.push_back(archiveFile(path + findData.cFileName, "archive\\"));
                string_ prefix(findData.cFileName);
                prefix = prefix.substr(0, 9) + "*.*";
                WIN32_FIND_DATAA findData2;
                HANDLE h2 = FindFirstFileA(path + prefix.c_str(), &findData2);
                if (h2 != INVALID_HANDLE_VALUE) {
                    do {
                        if (!(findData2.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
                            files.push_back(archiveFile(path + findData2.cFileName, "archive\\"));
                    } while (FindNextFileA(h2, &findData2));
                }
            }
        } while (FindNextFileA(h, &findData));
    }
    return files;
}
