// native-flags: /O2 /GS- /EHsc /MD /fp:fast
// NEEDS-DECL: namespace RBX { class ServiceProvider { ... }; } (no real header provided; stand-in layout below)
// NEEDS-DECL: char padding[0x1c0]; float rate; double first; double second; double third; (offsets 0x1c0, 0x1c8, 0x1d0, 0x1d8)
// NEEDS-DECL: double sub_00575690();
namespace RBX {
class ServiceProvider {
public:
    char padding[0x1c0];
    float rate;
    double first;
    double second;
    double third;

    double sub_00575690();
};
}

inline const double& maximum(const double& a, const double& b)
{
    return a < b ? b : a;
}

double RBX::ServiceProvider::sub_00575690()
{
    return maximum(0.0, 1.0 - (third + second + first) * (1.0 / rate)) * 100.0;
}
