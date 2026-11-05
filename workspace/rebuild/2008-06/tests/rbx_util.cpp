// RBX util rebuild test: Name dictionary, Math helpers.
#include "util/Name.h"
#include "util/Math.h"
#include <cstdio>

int main()
{
    int failures = 0;
    const RBX::Name& d = RBX::Name::declare("Workspace", -1);
    const RBX::Name& a = RBX::Name::lookup("Workspace");
    const RBX::Name& b = RBX::Name::lookup(std::string("Workspace"));
    if (&a != &d || &a != &b || a.empty() || !RBX::Name::lookup("NotDeclared").empty()) { std::printf("name lookup\n"); ++failures; }
    if (!RBX::Name::getNullName().empty()) { std::printf("null name\n"); ++failures; }
    if (RBX::Math::sign(-2.0f) != -1.0f || RBX::Math::taxiCabMagnitude(G3D::Vector3(1, -2, 3)) != 6.0f) { std::printf("math\n"); ++failures; }
    G3D::Vector3 g = RBX::Math::toGrid(G3D::Vector3(1.2f, 2.6f, -0.4f), 1.0f);
    if (g.x != 1.0f || g.y != 3.0f || g.z != 0.0f) { std::printf("toGrid %g %g %g\n", g.x, g.y, g.z); ++failures; }
    std::printf("failures=%d\n", failures);
    return failures;
}
