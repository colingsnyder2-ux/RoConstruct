// from server: 34% by colin
// Forward declarations of external functions and types used by the target.

// std::string-like object layout (MSVC 8.0 basic_string, 0x1c bytes).
namespace std {
    template<class T> class allocator {};
    template<class T> struct char_traits {};
    template<class E, class T, class A> class basic_string {
    public:
        basic_string();
        basic_string(const char*);
        ~basic_string();
    private:
        void* _Myproxy;
        union {
            char _Buf[16];
            char* _Ptr;
        } _Bx;
        unsigned int _Mysize;
        unsigned int _Myres;
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

// External imported functions (addresses are symbolic placeholders).
extern "C" {
    void __stdcall string_ctor(void* self, const char* s);
    void __stdcall string_dtor(void* self);
    int __stdcall string_compare(void* self, const void* other);
    void __stdcall string_assign(void* dst, const void* src);
    void __stdcall string_dtor2(void* self);
}

// Internal functions (addresses are symbolic placeholders).
void __stdcall sub_44A900(void* arg);
void __stdcall sub_429B20(void* dst, const void* src);
void __stdcall sub_630880(void* self, const void* a, const void* b, const void* c);

// The class reconstructed from RTTI: CRobloxCommandLineInfo.
struct CRobloxCommandLineInfo {
    char _pad[0x24];
    bool m_bNo3D;
    bool m_bScript;
    bool m_bBrowser;
    bool m_bBaseUrl;
    std::string m_sBaseUrl;

    void ParseParam(const char* pszParam, bool bFlag, bool bLast);
};

void CRobloxCommandLineInfo::ParseParam(const char* pszParam, bool bFlag, bool bLast) {
    if (m_bNo3D) {
        std::string tmp(pszParam);
        sub_44A900(&tmp);
        m_bNo3D = false;
        return;
    }
    if (m_bScript) {
        std::string tmp;
        string_assign(&tmp, pszParam);
        sub_429B20(&m_sBaseUrl, &tmp);
        string_dtor2(&tmp);
        m_bScript = false;
        return;
    }
    if (bFlag) {
        std::string tmp("BaseUrl");
        if (string_compare(&tmp, pszParam) == 0) {
            m_bBaseUrl = true;
            string_dtor(&tmp);
            return;
        }
        string_dtor(&tmp);

        std::string tmp2("Browser");
        if (string_compare(&tmp2, pszParam) == 0) {
            m_bBrowser = true;
            string_dtor(&tmp2);
            return;
        }
        string_dtor(&tmp2);

        std::string tmp3("No3D");
        if (string_compare(&tmp3, pszParam) == 0) {
            m_bNo3D = true;
            string_dtor(&tmp3);
            return;
        }
        string_dtor(&tmp3);

        std::string tmp4("Script");
        if (string_compare(&tmp4, pszParam) == 0) {
            m_bScript = true;
            string_dtor(&tmp4);
            return;
        }
        string_dtor(&tmp4);
    }
    sub_630880(this, pszParam, (const void*)bFlag, (const void*)bLast);
}
