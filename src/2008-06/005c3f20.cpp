// from server: 100% by tester
namespace RBX {
namespace Profiling {
class Bucket
{
    double sampleTimeSpan;
    char gap8[0x8];
    int frames;
public:
    double getActualFPS() const;
};

double Bucket::getActualFPS() const
{
    return sampleTimeSpan > 0.0 ? frames / sampleTimeSpan : 0.0;
}
}
}
