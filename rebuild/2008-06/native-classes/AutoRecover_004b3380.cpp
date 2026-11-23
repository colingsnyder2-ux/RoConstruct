// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <vector>
#include <boost/shared_ptr.hpp>

namespace RBX {
class Instance;
class Name;
}

// INFERRED: 0x4b3380 is the cached lookup of the Decal service in ServiceProvider
// (index from doGetClassIndex, slot filled via findServiceByClassName(Name::sDecal)).
extern "C" int fn_004ab470();                      // doGetClassIndex<Decal>
extern "C" const RBX::Name& fn_004ab0f0();         // Name::doDeclare<sDecal>
extern "C" void __fastcall fn_00572a90(void* self, int unusedEdx,
                                       boost::shared_ptr<RBX::Instance>* out,
                                       const RBX::Name& className); // findServiceByClassName

struct ServiceProviderLike {
    char pad[0x190];
    std::vector<boost::shared_ptr<RBX::Instance> > services; // INFERRED: at +0x190
};

extern "C" RBX::Instance* __fastcall fn_004b3380(ServiceProviderLike* self, int unusedEdx)
{
    unsigned index = (unsigned)fn_004ab470();
    if (index + 1 > self->services.size())
        self->services.resize(index + 1);
    else if (self->services[index])
        return self->services[index].get();

    boost::shared_ptr<RBX::Instance> found;
    fn_00572a90(self, 0, &found, fn_004ab0f0());
    RBX::Instance* raw = found.get();
    if (!raw)
        return 0;
    self->services[index] = found;
    return raw;
}
