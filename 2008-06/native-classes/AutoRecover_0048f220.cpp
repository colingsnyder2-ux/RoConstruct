// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>
#include <new>

// INFERRED: no headers were provided, so the minimal declarations are local.
namespace boost {
    template<class T> class shared_ptr {
    public:
        T* px;
        void* pn;
        template<class Y, class D> shared_ptr(Y* p, D d);
    };
}

namespace RBX {

class Instance {};

// INFERRED: the callee at 0x5d30c0 is named SpawnerService::SpawnerService in
// the disassembly, so DebrisService is constructed through that symbol.
// INFERRED: a class-level operator new calling malloc gives the EH state
// around the new-expression seen in the original.
class DebrisService : public Instance {
public:
    char data[0x14c];
    DebrisService();
    static void* operator new(size_t n) { return malloc(n); }
    static void operator delete(void* p) { free(p); }
};

template<class Base>
class Creatable {
public:
    // INFERRED: Deleter is a 4-byte by-value object whose constructor zeroes
    // the full dword and then the first byte (the original emits both stores
    // before the malloc call).
    struct Deleter {
        union { int i; char c; } u;
        Deleter() { u.i = 0; u.c = 0; }
    };

    template<class T>
    static boost::shared_ptr<T> create();
};

template<>
template<>
boost::shared_ptr<DebrisService> Creatable<Instance>::create<DebrisService>()
{
    Deleter d;
    return boost::shared_ptr<DebrisService>(new DebrisService(), d);
}

} // namespace RBX
