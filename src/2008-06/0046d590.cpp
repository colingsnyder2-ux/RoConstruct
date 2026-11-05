// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>

template <class T> class bstr {
public:
    __declspec(noinline) bstr() { _Mysize = 0; }
    __declspec(noinline) bstr(const bstr& r) { _Mysize = r._Mysize; }
    __declspec(noinline) ~bstr() { _Mysize = 0; }
    __declspec(noinline) bool operator<(const bstr& r) const { return _Mysize < r._Mysize; }
    void* _Myaux;
    T _Buf[16];
    unsigned int _Mysize;
    unsigned int _Myres;
};
extern template class __declspec(dllimport) bstr<char>;
typedef bstr<char> Str;

namespace RBX {
namespace LDraw2Lua {

class Color {
public:
    virtual ~Color();
};

class LDraw2RobloxColorMap {
public:
    virtual ~LDraw2RobloxColorMap();
    Str name;
    Str fileName;
    std::map<int, Color*> colors;
    std::map<Str, Color*> namedColors;
};

LDraw2RobloxColorMap::~LDraw2RobloxColorMap()
{
    std::map<int, Color*>::iterator it;
    for (it = colors.begin(); it != colors.end(); ++it)
        delete it->second;
    std::map<Str, Color*>::iterator it2;
    for (it2 = namedColors.begin(); it2 != namedColors.end(); ++it2)
        delete it2->second;
}

}
}
