// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <boost/shared_ptr.hpp>

// INFERRED: no class headers were provided, so these are minimal local
// declarations. The template statics are declared but not defined, so they
// link to the mangled symbols named in the disassembly comments.
namespace RBX {
    class Instance;
    class PartInstance;
    namespace Network { class Players; }

    class ServiceProvider {
    public:
        template<class T> static T* find(const Instance* context);
    };

    template<class T> boost::shared_ptr<T> shared_from(T* p);
}

// INFERRED: thiscall on Players with hidden result pointer and a
// shared_ptr<PartInstance> by value (3 stack dwords).
extern "C" void __fastcall fn_00498030(void* self, int unusedEdx,
                                       void* result,
                                       boost::shared_ptr<RBX::PartInstance> part);

#pragma warning(disable: 4700)

extern "C" RBX::Instance* fn_0049acd0(RBX::PartInstance* part)
{
    RBX::Network::Players* players =
        RBX::ServiceProvider::find<RBX::Network::Players>(
            reinterpret_cast<const RBX::Instance*>(part));
    if (players)
    {
        int edxDummy; // INFERRED: edx is not set by the original (thiscall)
        struct Raw { void* a; void* b; } buf;
        fn_00498030(players, edxDummy, &buf, RBX::shared_from<RBX::PartInstance>(part));
        boost::shared_ptr<RBX::Instance>& r =
            *reinterpret_cast<boost::shared_ptr<RBX::Instance>*>(&buf);
        RBX::Instance* p = r.get();
        r.~shared_ptr();
        return p;
    }
    return 0;
}
