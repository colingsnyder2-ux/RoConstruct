// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers shown; minimal local declarations below.
namespace RBX {
class Instance;
extern const char* const sInstance;
namespace Reflection {
class DescribedBase;
class ClassDescriptor {
public:
    ClassDescriptor(ClassDescriptor& base, const char* name);
    ~ClassDescriptor(); // INFERRED: atexit dtor stub at 0x7fba80
    char data[1];       // INFERRED: real size unknown
};
template <class T, const char* const* Name, class B>
struct Described {
    static ClassDescriptor& classDescriptor();
};
} // namespace Reflection
} // namespace RBX

// INFERRED: 0x40ad80 is the parent Described<> classDescriptor (base class descriptor)
extern "C" RBX::Reflection::ClassDescriptor& fn_0040ad80();

namespace RBX {
namespace Reflection {
template <>
ClassDescriptor& Described<Instance, &sInstance, DescribedBase>::classDescriptor()
{
    static ClassDescriptor descriptor(fn_0040ad80(), "ServiceProvider");
    return descriptor;
}
} // namespace Reflection
} // namespace RBX
