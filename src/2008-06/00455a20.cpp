// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_31ba03a35f51eb9a.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
namespace rs {
template <class T> class basic_str {
public:
    __declspec(noinline) basic_str(const T* s) { buf[0] = *s; }
    __declspec(noinline) basic_str(const basic_str& s) { buf[0] = s.buf[0]; }
    __declspec(noinline) ~basic_str() { buf[0] = 0; }
    __declspec(noinline) basic_str& operator=(const basic_str& s) { buf[0] = s.buf[0]; return *this; }
    __declspec(noinline) const T* c_str() const { return buf; }
    T buf[0x1c];
};
extern template class __declspec(dllimport) basic_str<char>;
typedef basic_str<char> string;
}

template <class T> class CStringT {
public:
    __declspec(noinline) CStringT() { m_pszData = 0; }
    __declspec(noinline) ~CStringT() throw() { m_pszData = 0; }
    __declspec(noinline) CStringT& operator+=(const T* psz) { m_pszData = (T*)psz; return *this; }
    __declspec(noinline) operator const T*() const { return m_pszData; }
    T* m_pszData;
};
extern template class __declspec(dllimport) CStringT<char>;
typedef CStringT<char> CString;

class CFile {
public:
    enum OpenFlags { modeRead = 0 };
    CFile(const char* lpszFileName, unsigned int nOpenFlags);
    ~CFile();
    unsigned int Read(void* lpBuf, unsigned int nCount);
    void* vtbl;
    void* m_hFile;
    int m_bCloseOnDelete;
    void* m_strFileName;
};

namespace RBX {
class ContentId {
public:
    ContentId(const char* id);
    ~ContentId();
    rs::string id;
    int flags;
};
class ContentProvider {
public:
    static bool isUrl(const rs::string& s);
    rs::string getFile(ContentId id);
};
class DataModel {
public:
    ContentProvider* getContentProvider();
};
template <class T> inline T* find(DataModel* dm) { return dm ? dm->getContentProvider() : 0; }
}

class CRobloxDoc {
public:
    boost::shared_ptr<RBX::DataModel> getDataModel();
    int loadFromString(rs::string contents);
    int loadFile(rs::string path);
};

int CRobloxDoc::loadFile(rs::string path)
{
    if (RBX::ContentProvider::isUrl(path.c_str()))
        path = RBX::find<RBX::ContentProvider>(getDataModel().get())->getFile(path.c_str());
    CString contents;
    {
        CFile file(path.c_str(), CFile::modeRead);
        char buffer[0x1000];
        unsigned int count;
        do {
            count = file.Read(buffer, 0xfff);
            buffer[count] = 0;
            contents += buffer;
        } while (count);
    }
    return loadFromString(rs::string((const char*)contents));
}
