// from server: 100% by tester
namespace RBX {
class Body
{
    char gap0[0x14];
    Body* parent;
public:
    Body* calcRoot();
};

Body* Body::calcRoot()
{
    return parent ? parent->calcRoot() : this;
}
}
