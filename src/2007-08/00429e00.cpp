// from server: 24% by colin
// roc 2007-08 00429e00  unit: ThreadLogManager  size: 873 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00429e00

extern "C" {
typedef unsigned long DWORD;
typedef void* HANDLE;
typedef const char* LPCSTR;
typedef char* LPSTR;
typedef unsigned int UINT;

struct _WIN32_FIND_DATAA {
    DWORD dwFileAttributes;
    DWORD ftCreationTime[2];
    DWORD ftLastAccessTime[2];
    DWORD ftLastWriteTime[2];
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};
typedef struct _WIN32_FIND_DATAA WIN32_FIND_DATAA;
typedef WIN32_FIND_DATAA* LPWIN32_FIND_DATAA;

HANDLE __stdcall FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData);
int __stdcall FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData);
DWORD __stdcall GetCurrentThreadId();
}

namespace std {
class string {
public:
    string();
    string(const char*);
    string(const string&);
    ~string();
    string& operator=(const string&);
    const char* c_str() const;
    string substr(unsigned int, unsigned int) const;
    string& insert(unsigned int, const string&);
    unsigned int size() const;
};
string operator+(const string&, const char*);
}

extern "C" {
void* __stdcall PathAddBackslashA(char* pszPath);
}

struct LogManager {
    void* log;
    DWORD threadID;
    std::string name;
    LogManager(const char* n);
    virtual ~LogManager();
    virtual std::string getLogFileName();
};

struct ThreadLogManager : LogManager {
    ThreadLogManager();
    virtual ~ThreadLogManager();
    virtual std::string getLogFileName();
};

extern LogManager* mainLogManager;

std::string ThreadLogManager::getLogFileName()
{
    std::string fileName = mainLogManager->getLogFileName();
    char id[64];
    id[0] = '_';
    const char* n = name.c_str();
    int i = 1;
    while (*n) { id[i++] = *n++; }
    id[i++] = '_';
    DWORD t = threadID;
    char tmp[16];
    int j = 0;
    if (t != 0) { tmp[j++] = '0'; }
    else {
        while (t) { tmp[j++] = (char)('0' + (t % 10)); t /= 10; }
    }
    while (j) { id[i++] = tmp[--j]; }
    id[i] = 0;
    std::string sid(id);
    fileName.insert(fileName.size() - 4, sid);
    return fileName;
}
