// from server: 99% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.40.0 roc_espclaude_0a801ed1f22300a9.cpp

// Candidate translation unit (score above; library headers required).
#define BOOST_CB_DISABLE_DEBUG
#define NDEBUG
#include <boost/circular_buffer.hpp>
void* operator new(size_t);
namespace RBX {
class Time {
public:
    class Interval {
        double sec;
    public:
        inline Interval() : sec(0) {}
        inline explicit Interval(double s) : sec(s) {}
        inline double seconds() const { return sec; }
    };
    inline Time() : sec(0) {}
    typedef enum { Fast, Benchmark, Precise, Multimedia } SampleMethod;
    template<SampleMethod sampleMethod> static Time now();
private:
    double sec;
};
template<Time::SampleMethod sampleMethod>
class Timer {
    Time start;
public:
    Timer() : start(Time::now<sampleMethod>()) {}
};
template<typename ValueType = double, typename AverageType = double>
class WindowAverage {
protected:
    boost::circular_buffer<ValueType> buffer;
public:
    WindowAverage(size_t maxSamples) : buffer(maxSamples) {}
};
template<Time::SampleMethod sampleMethod = Time::Benchmark>
class WindowAverageTimeInterval {
public:
    WindowAverageTimeInterval(Time::Interval maxWindow) : maxWindow(maxWindow), average(16) {}
private:
    Time::Interval currentWindow;
    Time::Interval maxWindow;
    WindowAverage<> average;
    Timer<sampleMethod> timer;
    bool firstTime;
};
template<Time::SampleMethod sampleMethod = Time::Benchmark>
class WindowAverageDutyCycle {
public:
    WindowAverageDutyCycle(Time::Interval maxWindow) : time(16), interval(maxWindow) {}
private:
    WindowAverage<double> time;
    WindowAverageTimeInterval<sampleMethod> interval;
};
template class WindowAverageDutyCycle<Time::Precise>;
}
