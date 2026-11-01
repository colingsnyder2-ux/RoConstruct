// from server: 100% by EspClaude
// from server: 81% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef unsigned long DWORD;
typedef void* HANDLE;
typedef int BOOL;
struct FILETIME { DWORD dwLowDateTime; DWORD dwHighDateTime; };
struct WIN32_FIND_DATAA {
	DWORD dwFileAttributes;
	FILETIME ftCreationTime;
	FILETIME ftLastAccessTime;
	FILETIME ftLastWriteTime;
	DWORD nFileSizeHigh;
	DWORD nFileSizeLow;
	DWORD dwReserved0;
	DWORD dwReserved1;
	char cFileName[260];
	char cAlternateFileName[14];
};
#define INVALID_HANDLE_VALUE ((HANDLE)(long)-1)
#define FILE_ATTRIBUTE_DIRECTORY 0x10
extern "C" {
__declspec(dllimport) HANDLE __stdcall FindFirstFileA(const char*, WIN32_FIND_DATAA*);
__declspec(dllimport) BOOL __stdcall FindNextFileA(HANDLE, WIN32_FIND_DATAA*);
__declspec(dllimport) BOOL __stdcall DeleteFileA(const char*);
__declspec(dllimport) BOOL __stdcall PathAppendA(char*, const char*);
__declspec(dllimport) char* __stdcall PathAddBackslashA(char*);
}
#include <list>

template <class T> class CStringT_ {
public:
    __declspec(noinline) CStringT_() { m_pszData = 0; }
    __declspec(noinline) ~CStringT_() throw() { m_pszData = 0; }
    __declspec(noinline) operator const T*() const throw() { return m_pszData; }
    __declspec(noinline) int GetLength() const { return 0; }
    __declspec(noinline) T* GetBuffer(int n) { return m_pszData; }
    __declspec(noinline) void ReleaseBuffer(int n = -1) { }
    static __declspec(noinline) int __cdecl StringLength(const T* psz) { return 0; }
    T* m_pszData;
};
extern template class __declspec(dllimport) CStringT_<char>;
typedef CStringT_<char> CString;
CString operator+(const CString& str1, const char* psz2);

class LogDirectory
{
public:
	CString getPath();
};

class ThreadLogManager
{
public:
	int pad;
	LogDirectory logDirectory;
	void deleteOldLogs(const char* subdir, unsigned int keep);
};

class FileList : public std::list<WIN32_FIND_DATAA>
{
public:
	__declspec(noinline) FileList() {}

};
#include <algorithm>
struct OlderThan
{
	DWORD low, high;
	OlderThan(const FILETIME& t) : low(t.dwLowDateTime), high(t.dwHighDateTime) {}
	bool operator()(const WIN32_FIND_DATAA& data) const
	{
		return data.ftCreationTime.dwHighDateTime < high || (data.ftCreationTime.dwHighDateTime == high && data.ftCreationTime.dwLowDateTime < low);
	}
};
void insertAt(FileList&, FileList::iterator, const WIN32_FIND_DATAA&);
namespace std { template<> FileList::iterator find_if(FileList::iterator, FileList::iterator, OlderThan); }


void ThreadLogManager::deleteOldLogs(const char* subdir, unsigned int keep)
{
	CString path = logDirectory.getPath();
	char* buffer = path.GetBuffer(path.GetLength() + CString::StringLength(subdir) + 1);
	PathAppendA(buffer, subdir);
	path.ReleaseBuffer();
	PathAddBackslashA(path.GetBuffer(path.GetLength() + 1));
	path.ReleaseBuffer();

	FileList files;
	WIN32_FIND_DATAA findData;
	HANDLE hFind = FindFirstFileA(path + "*.*", &findData);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
				files.std::list<WIN32_FIND_DATAA>::insert(std::find_if(files.begin(), files.end(), OlderThan(findData.ftCreationTime)), findData);
		} while (FindNextFileA(hFind, &findData));
	}

	FileList::iterator iter = files.begin();
	for (unsigned int i = keep; i < files.size(); ++i)
	{
		DeleteFileA(path + iter->cFileName);
		++iter;
	}
}
