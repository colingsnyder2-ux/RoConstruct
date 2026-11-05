// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_08c83e960fcbf70c.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <string>
std::string describeTime(double);
std::string formatText(const char*, ...);
struct Sample {
    char padding[0x48];
    double time;
};
struct LaserTool {
    char padding[0x130];
    double time;
    std::string text;
    void update(const Sample&);
};
void LaserTool::update(const Sample& sample)
{
    time = sample.time;
    double t = sample.time;
    if (t > 0) {
        std::string description = describeTime(sample.time);
        double interval = sample.time;
        text = formatText("%s (%.3gfps)", description.c_str(), 1.0 / interval);
    } else {
        text = describeTime(sample.time);
    }
}
