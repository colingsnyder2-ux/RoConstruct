// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: disassembly builds a 0x16c-byte object via malloc + ctor and hands it to
// shared_ptr(p, Deleter). Types below are local stand-ins; Deleter needs operator()
// because boost 1.34 shared_count calls d(p).
#include <stdlib.h>
#include <new>
#include <boost/shared_ptr.hpp>

namespace RBX {
    class Instance { public: virtual ~Instance() {} };
    class BodyVelocity : public Instance { char pad[0x168]; public: BodyVelocity(); };

    template<class T> struct Creatable {
        struct Deleter {
            template<class U> void operator()(U* p) const { delete p; }
        };
        template<class U> static boost::shared_ptr<U> create();
    };

    template<> template<>
    boost::shared_ptr<BodyVelocity> Creatable<Instance>::create<BodyVelocity>()
    {
        Creatable<Instance>::Deleter d;
        void* mem = malloc(0x16c);
        BodyVelocity* p = mem ? new (mem) BodyVelocity() : 0;
        return boost::shared_ptr<BodyVelocity>(p, d);
    }
}
