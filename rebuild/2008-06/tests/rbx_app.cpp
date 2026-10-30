#include "force_verified.h"
// RBX App rebuild test: instance tree (create, name, parent, find).
#include "v8datamodel/Message.h"
#include <cstdio>

int main()
{
    int failures = 0;
    boost::shared_ptr<RBX::Message> root = RBX::Creatable<RBX::Instance>::create<RBX::Message>();
    boost::shared_ptr<RBX::Message> child = RBX::Creatable<RBX::Instance>::create<RBX::Message>();
    root->setName("Root");
    child->setName("Child");
    child->setParent(root.get());
    if (root->numChildren() != 1 || root->findFirstChildByName("Child") != child.get()) { std::printf("tree\n"); ++failures; }
    if (root->getClassName().empty()) { std::printf("class name\n"); ++failures; }
    child->setParent(NULL);
    if (root->numChildren() != 0) { std::printf("unparent %u\n", root->numChildren()); ++failures; }
    std::printf("failures=%d\n", failures);
    return failures;
}
