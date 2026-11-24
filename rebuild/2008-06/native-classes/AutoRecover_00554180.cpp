// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <map>
#include <string>

namespace RBX { class Name; }

struct Mutex;

// INFERRED: callee signatures from the disassembly; lookup key is a std::string passed by reference.
extern "C" void fn_00557330(void (*once)(), long& flag);
extern "C" void fn_00553970();
extern "C" void fn_00554160();
extern "C" std::map<std::string, const RBX::Name*>& fn_00553f20();
extern "C" Mutex& fn_00553910();
extern "C" void __fastcall fn_00594ce0(Mutex* m, int unusedEdx);
extern "C" void __fastcall fn_00594d00(Mutex* m, int unusedEdx);

extern long g_00973a2c;
extern long g_009739d4;
extern const RBX::Name* g_009739d0;

// INFERRED: scoped lock over the boost::mutex returned by moo2()
struct ScopedLock {
    Mutex* m;
    ScopedLock(Mutex& mm) : m(&mm) { fn_00594ce0(m, 0); }
    ~ScopedLock() { fn_00594d00(m, 0); }
};

extern "C" const RBX::Name* fn_00554180(const std::string& key)
{
    fn_00557330(fn_00553970, g_009739d4);
    ScopedLock lock(fn_00553910());

    typedef std::map<std::string, const RBX::Name*> Map;
    Map::iterator it = fn_00553f20().find(key);
    if (it == fn_00553f20().end()) {
        fn_00557330(fn_00554160, g_00973a2c);
        return g_009739d0;
    }
    return it->second;
}
