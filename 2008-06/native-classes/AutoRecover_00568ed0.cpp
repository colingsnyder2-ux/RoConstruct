// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers were shown, so the minimal class layout below is
// a local reconstruction. The real hierarchy has several interface bases,
// which is where the extra vtable stores at +0x10..+0x170 come from.

namespace RBX {

extern const char* const sGlobalSettings;
extern const char* const sInstance;

namespace Reflection {
    class DescribedBase;
    class ClassDescriptor;
}

class Instance;
class GlobalSettings;

// INFERRED: Instance-level base that holds the class descriptor pointer at +0x1c.
class ServiceProvider {
public:
    virtual ~ServiceProvider() {}
    int pad04[3];
    void* iface10;
    void* iface14;
    int pad18;
    const Reflection::ClassDescriptor* descriptor; // +0x1c
};

template<class T, const char* const* Name>
class NonFactoryProduct : public T {
public:
    NonFactoryProduct();
};

template<class T, const char* const* Name>
class Described {
public:
    static const Reflection::ClassDescriptor& classDescriptor();
};

template<class T, class Base, const char* const* Name>
class DescribedNonCreatable : public NonFactoryProduct<Base, Name> {
public:
    DescribedNonCreatable();
};

// INFERRED: the descriptor stored is Described<Instance,&sInstance>::classDescriptor()
template<class T, class Base, const char* const* Name>
DescribedNonCreatable<T, Base, Name>::DescribedNonCreatable()
    : NonFactoryProduct<Base, Name>()
{
    this->descriptor = &Described<Instance, &sInstance>::classDescriptor();
}

// explicit instantiation of the target constructor
template class DescribedNonCreatable<GlobalSettings, ServiceProvider, &sGlobalSettings>;

} // namespace RBX
