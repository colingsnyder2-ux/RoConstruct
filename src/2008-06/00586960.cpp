// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_scriptsharedinitialization7af41201e29c6a78.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/shared_ptr.hpp>
typedef std::string String;
struct Name;
extern Name* __cdecl getLocalScope();
extern void __cdecl initializeScriptName();
extern void __cdecl initializeOnce(void (__cdecl *)(), void*);
extern char scriptNameState;
extern Name* scriptName;

extern const char table00[], table10[], table14[], table20[], table24[];
extern const char table44[], table64[], table84[], tableA4[], tableC4[];

struct NamePtr { Name* pointer; boost::detail::shared_count count;
 NamePtr(Name* p) : pointer(p), count() {}
 NamePtr& operator=(const NamePtr& b) { pointer=b.pointer; count=b.count; return *this; }
};
extern NamePtr scriptNameRef;

struct Base {
    char storage[0x130];
    Base(const char*);
};

struct Product : Base {
    Product();
    ~Product();
};

__forceinline Product::Product() : Base("Script")
{

}

struct Guid {
    String text;
    Name* scope;
    Guid();
    ~Guid();
};

__forceinline Guid::Guid() : scope(getLocalScope()) {}

struct S : Product {
    NamePtr nameRef;
    Guid guid;
    bool enabled;
    unsigned int value;
    S();
    Name* initializeTables() {
    *reinterpret_cast<const void**>(reinterpret_cast<char*>(this) + 0x00) = table00;
    *reinterpret_cast<const void**>(reinterpret_cast<char*>(this) + 0x10) = table10;
    *reinterpret_cast<const void**>(reinterpret_cast<char*>(this) + 0x14) = table14;
    *reinterpret_cast<const void**>(reinterpret_cast<char*>(this) + 0x20) = table20;
    *reinterpret_cast<const void**>(reinterpret_cast<char*>(this) + 0x24) = table24;
    *reinterpret_cast<const void**>(reinterpret_cast<char*>(this) + 0x44) = table44;
    *reinterpret_cast<const void**>(reinterpret_cast<char*>(this) + 0x64) = table64;
    *reinterpret_cast<const void**>(reinterpret_cast<char*>(this) + 0x84) = table84;
    *reinterpret_cast<const void**>(reinterpret_cast<char*>(this) + 0xa4) = tableA4;
    *reinterpret_cast<const void**>(reinterpret_cast<char*>(this) + 0xc4) = tableC4;
return 0;
}
};

S::S()
    : Product(),
      nameRef(initializeTables()),
      guid(),
      enabled(false),
      value(0)
{
    initializeOnce(initializeScriptName, &scriptNameState);
    nameRef = scriptNameRef;
}
