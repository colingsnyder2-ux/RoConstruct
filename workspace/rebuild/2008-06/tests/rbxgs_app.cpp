#include "force_verified.h"
// rbxgs App rebuild test: instance tree (create, name, parent, find).
#include "v8datamodel/Message.h"
#include <cstdio>
#include <cstdlib>

// An invalid CRT parameter (0xC0000417) ends the process without an exception; fault instead so a
// debugger sees the caller. init_seg(lib) installs this before the rebuilt code's global constructors.
#pragma warning(disable: 4073)
#pragma init_seg(lib)
static void invalidParameter(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, uintptr_t)
{
    std::fprintf(stderr, "invalid CRT parameter\n");
    *(volatile int*)0 = 0;
}
static struct InvalidParameterTrap { InvalidParameterTrap() { _set_invalid_parameter_handler(invalidParameter); } } invalidParameterTrap;

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
