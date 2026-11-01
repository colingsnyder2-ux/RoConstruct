// from server: 100% by tester
namespace RBX {
namespace Profiling {
class Profiler
{
    double lastSampleTime;
    double sampleTimeSpan;
    int frames;
public:
    double getActualFPS() const;
};

double Profiler::getActualFPS() const
{
    return sampleTimeSpan > 0.0 ? frames / sampleTimeSpan : 0.0;
}
}
}
