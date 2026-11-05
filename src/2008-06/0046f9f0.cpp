// from server: 100% by EspClaude
// roc 2008-06 0046f9f0  size: 543 bytes
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);
extern "C" __declspec(dllimport) int __cdecl toupper(int c);

namespace rs {
template <class T> class basic_str;

template <class T> class citer {
public:
    typedef basic_str<T> S;
    const S* _Mycont;
    const T* _Myptr;
    citer() { _Myptr = 0; }
    const T& operator*() const
    {
        if (_Mycont != (const S*)-4) {
            if (!(_Mycont != 0)) _invalid_parameter_noinfo();
            if (!(_Myptr < (((S*)_Mycont)->_Myptr() + _Mycont->_Mysize))) _invalid_parameter_noinfo();
        }
        return *_Myptr;
    }
    citer& operator++()
    {
        if (_Mycont != (const S*)-4) {
            if (!(_Mycont != 0)) _invalid_parameter_noinfo();
            if (!(_Myptr < (((S*)_Mycont)->_Myptr() + _Mycont->_Mysize))) _invalid_parameter_noinfo();
        }
        ++_Myptr;
        return *this;
    }
    bool operator==(const citer& r) const
    {
        if (_Mycont != (const S*)-4) {
            if (!(_Mycont != 0 && _Mycont == r._Mycont)) _invalid_parameter_noinfo();
        }
        return _Myptr == r._Myptr;
    }
    bool operator!=(const citer& r) const { return !(*this == r); }
};

template <class T> class basic_str {
public:
    typedef citer<T> const_iterator;
    void* _Myaux;
    union { T _Buf[16]; T* _Ptr; } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    __declspec(noinline) const_iterator begin() const { const_iterator i; i._Mycont = this; i._Myptr = _Bx._Ptr; return i; }
    __declspec(noinline) const_iterator end() const { const_iterator i; i._Mycont = this; i._Myptr = _Bx._Ptr + _Mysize; return i; }
    __declspec(noinline) unsigned int size() const { return _Mysize; }
    __declspec(noinline) T* _Myptr() { return _Bx._Ptr; }
};
extern template class __declspec(dllimport) basic_str<char>;
typedef basic_str<char> string;
}

int stringCompareNoCase(const rs::string& s1, const rs::string& s2)
{
    rs::string::const_iterator it1 = s1.begin();
    rs::string::const_iterator it2 = s2.begin();
    while ((it1 != s1.end()) && (it2 != s2.end())) {
        if (::toupper(*it1) != ::toupper(*it2))
            return (::toupper(*it1) < ::toupper(*it2)) ? -1 : 1;
        ++it1;
        ++it2;
    }
    unsigned int size1 = s1.size(), size2 = s2.size();
    if (size1 == size2)
        return 0;
    return (size1 < size2) ? -1 : 1;
}
