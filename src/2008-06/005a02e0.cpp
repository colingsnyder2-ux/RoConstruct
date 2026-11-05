// from server: 100% by king_originala
extern double sampleInterval;

namespace RBX {
namespace Profiling {

class Bucket
{
    double sampleTimeSpan;
    char gap8[8];
    int frames;
public:
    double getActualFPS() const;
};

class Profiler
{
public:
    Bucket getBucket(double interval);
};

}
}

double getActualFPS(RBX::Profiling::Profiler* profiler)
{
    return profiler->getBucket(sampleInterval).getActualFPS();
}
