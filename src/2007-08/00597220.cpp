// from server: 100% by EspClaude
// roc 2007-08 00597220  ProfilingItem::update (rbxgs v8datamodel/Stats.cpp), self-contained
// roc-flags: /O2 /GS- /EHsc /MD
#include <stdio.h>
#include <string>

namespace RBX {
namespace Log { std::string formatTime(double time); }
namespace Profiling {
class Bucket {
public:
    double sampleTimeSpan;
    double totalTime;
    double frameTime;
    int frames;
    double getTotalTime() const;
    double getFrameTime() const;
    double getNominalFPS() const;
};
class Profiler {
public:
    Bucket getData(double window) const;
};
}
}

class ProfilingItem {
    char padding[0xe8];
    double val;
    std::string sValue;
    unsigned int reserved;
    const RBX::Profiling::Profiler& p;
public:
    void update();
};

void ProfilingItem::update()
{
    RBX::Profiling::Bucket b = p.getData(5.0);

    if (b.sampleTimeSpan > 0.0)
    {
        val = b.getTotalTime() / b.sampleTimeSpan;

        __declspec(align(64)) char buffer[256];
        if (b.frames > 0)
        {
            std::string t = RBX::Log::formatTime(b.getFrameTime());
            sprintf(buffer, "%s, %.3gfps (%.3g%%)", t.c_str(), b.getNominalFPS(), val * 100.0);
        }
        else
        {
            sprintf(buffer, "%.3g%%", val * 100.0);
        }

        sValue = buffer;
    }
    else
    {
        val = 0.0;
        sValue = "?";
    }
}
