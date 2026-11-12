// from server: 100% by EspClaude
// roc 2007-08 0045a1f0  unit: RBX::VCamera::?$FactoryProduct::Creator  size: 114 bytes
// Static-local ClassDescriptor getter (Described<...>::classDescriptor shape):
// guard bit at 0x8bc068, base descriptor from 0x418690, ctor 0x570c00(base, "Item"), atexit dtor.
namespace RBX { namespace Reflection {
class ClassDescriptor {
public:
    ClassDescriptor(ClassDescriptor& base, const char* name);
    ~ClassDescriptor();
};
struct BaseDescribed {
    static ClassDescriptor& classDescriptor();
};
struct Item {
    static ClassDescriptor& classDescriptor();
};
ClassDescriptor& Item::classDescriptor()
{
    static ClassDescriptor desc(BaseDescribed::classDescriptor(), "Item");
    return desc;
}
}}
