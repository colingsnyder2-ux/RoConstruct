// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <vector>
#include <algorithm>

namespace RBX {
    class Name {
    public:
        static int __cdecl compare(Name& a, Name& b);
    };
}

namespace boost {
    void __cdecl call_once(void (__cdecl *func)(), long& flag);
}

// INFERRED: descriptor layout (name at +4, category descriptor at +0xc whose name is at +4)
struct Descriptor {
    void* vtbl;
    RBX::Name* name;
    int pad8;
    Descriptor* category;
};

// INFERRED: container layout: descriptors vector at +0, derived containers vector at +0x18
struct DescriptorContainer {
    std::vector<Descriptor*> descriptors;            // +0x00
    std::vector<DescriptorContainer*> derived;       // +0x18
};

struct ContainerMutex;

// INFERRED: mutex getter (ICF-folded with G3D::Shape::axes)
extern "C" ContainerMutex* __fastcall fn_0056be10(DescriptorContainer* self, int unusedEdx);
// INFERRED: lock/unlock (ICF-folded with GuidRegistryMutex::lock/unlock)
extern "C" void __fastcall fn_00563090(ContainerMutex* self, int unusedEdx);
extern "C" void __fastcall fn_005630e0(ContainerMutex* self, int unusedEdx);
// INFERRED: descriptor comparison predicate passed to lower_bound
extern "C" bool __cdecl fn_0056b500(const Descriptor* a, const Descriptor* b);
// INFERRED: once-init function for the static mutex
extern "C" void __cdecl fn_004a7d00();
extern "C" long g_00971004;

extern "C" int __fastcall fn_0056c170(DescriptorContainer* self, int unusedEdx, Descriptor* d);

namespace {

struct ScopedLock {
    ContainerMutex* m;
    explicit ScopedLock(ContainerMutex* mm) : m(mm) { fn_00563090(m, 0); }
    ~ScopedLock() { fn_005630e0(m, 0); }
};

// INFERRED: global list of all descriptors (function static guarded by call_once)
static std::vector<Descriptor*>& allDescriptors()
{
    boost::call_once(&fn_004a7d00, g_00971004);
    static std::vector<Descriptor*> all;
    return all;
}

}

extern "C" int __fastcall fn_0056c170(DescriptorContainer* self, int unusedEdx, Descriptor* d)
{
    ScopedLock lock(fn_0056be10(self, 0));

    std::vector<Descriptor*>::iterator it =
        std::lower_bound(self->descriptors.begin(), self->descriptors.end(), d, fn_0056b500);
    if (it == self->descriptors.end() || *it != d)
        self->descriptors.insert(it, d);

    for (std::vector<DescriptorContainer*>::iterator c = self->derived.begin();
         c != self->derived.end(); ++c)
        fn_0056c170(*c, 0, d);

    std::vector<Descriptor*>::iterator iter = allDescriptors().begin();
    for (; iter != allDescriptors().end(); ++iter)
    {
        Descriptor* other = *iter;
        if (other == d)
            return 0;
        int cmp = RBX::Name::compare(*d->name, *other->name);
        if (cmp < 0)
            break;
        if (cmp == 0)
        {
            if (RBX::Name::compare(*d->category->name, *other->category->name) < 0)
                break;
        }
    }
    allDescriptors().insert(iter, d);
    return 0;
}
