// from server: 100% by EspClaude
// roc 2007-08 004b0240  unit: RBX::Network::VReplicator::?$SignalDesc  size: 114 bytes
// Storage size not visible in these bytes; left undeclared.
// Rewritten: function-local static ClassDescriptor(base classDescriptor(), "NetworkReplicator").
// ctor 0x570c00 = ClassDescriptor::ClassDescriptor(ClassDescriptor&, const char*) (ret 8)
// base getter 0x418690 = Described<Instance,...>::classDescriptor() (no args, ret)
namespace RBX { namespace Reflection {
class ClassDescriptor
{
public:
    ClassDescriptor(ClassDescriptor& base, const char* name);
    ~ClassDescriptor();

};
ClassDescriptor& baseClassDescriptor();
} }

RBX::Reflection::ClassDescriptor& replicatorClassDescriptor()
{
    static RBX::Reflection::ClassDescriptor desc(RBX::Reflection::baseClassDescriptor(), "NetworkReplicator");
    return desc;
}
