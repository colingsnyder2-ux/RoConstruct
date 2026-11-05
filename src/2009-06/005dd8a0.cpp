// from server: 100% by EspClaude
// from server: 73% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_6d86f883379a502c.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <string>
#include <stdexcept>
// from server: 75% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

typedef std::string String;
typedef boost::shared_ptr<void> Shared;
typedef int (__stdcall *PathPredicate)(const char*);
extern PathPredicate pathIsRelative;
extern PathPredicate pathIsDirectory;
extern String assetFolder;
struct Header;

struct Allocator {
    virtual void unused() = 0;
    virtual void release(Header*) = 0;
};

struct Header {
    Allocator* allocator;
    long length;
    long capacity;
    volatile long references;
};

struct Path {
    char* text;
    Path(const char*);
    ~Path();
    void normalize();
};

Path::~Path()
{
    Header* p = reinterpret_cast<Header*>(text) - 1;
    if (_InterlockedExchangeAdd(&p->references, -1) - 1 <= 0)
        p->allocator->release(p);
}

struct Exception : std::exception { String text; Exception(const String& s):text(s) {} virtual ~Exception() throw() {} virtual const char* what() const throw() {return text.c_str();} };

extern String __cdecl construct();
extern Shared __cdecl getLogger();
extern void __cdecl logMessage(void*, int, const char*, ...);
extern std::runtime_error __cdecl format(const char*, ...);

void __cdecl setAssetFolder(const char* folder)
{
    construct();

    {
        logMessage(getLogger().get(), 1, "setAssetFolder %s", folder);
    }

    Path path(folder);

    if (pathIsRelative(path.text))
        throw format("The path '%s' is a relative path", path.text);

    if (!pathIsDirectory(path.text))
        throw format("The path '%s' does not exist", path.text);

    path.normalize();
    assetFolder = path.text;
}

