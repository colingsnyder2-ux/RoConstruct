// from server: 100% by king_originala
extern "C" {
extern int (__cdecl *sprintf)(char *, const char *, ...);
void * __cdecl __RTDynamicCast(void *, long, void *, void *, int);
}

extern const double sampleInterval;
extern char profilerType;
extern char countProfilerType;

namespace std {
template<class T> struct char_traits;
template<class T> class allocator;
template<class T, class Traits, class Allocator> class basic_string;

template<>
class basic_string<char, char_traits<char>, allocator<char> > {
public:
    unsigned int allocatorState;
    union {
        char buffer[16];
        char *pointer;
    };
    unsigned int length;
    unsigned int capacity;

    ~basic_string();
    basic_string &operator=(const char *);
};
}

typedef std::basic_string<char, std::char_traits<char>,
                          std::allocator<char> > String;

extern void (__thiscall *destroyString)(String *);
extern String &(__thiscall *assignString)(String *, const char *);

__forceinline String::~basic_string()
{
    destroyString(this);
}

__forceinline String &String::operator=(const char *value)
{
    return assignString(this, value);
}

struct Sample {
    double lastSampleTime;
    double sampleTimeSpan;
    int frames;

    double f();
    double getActualFPS() const;
};

struct Profiler {
    Sample getSample(double);
};

extern String __cdecl formatTime(double);

struct ProfilingItem {
    char padding[0x130];
    double rate;
    String text;
    unsigned int reserved;
    Profiler *profiler;

    void update();
};

void ProfilingItem::update()
{
    Sample sample = profiler->getSample(sampleInterval);
    __declspec(align(64)) char buffer[256];

    if (sample.lastSampleTime > 0.0) {
        rate = sample.sampleTimeSpan / sample.lastSampleTime;

        if (__RTDynamicCast(profiler, 0, &profilerType,
                            &countProfilerType, 0)) {
            sprintf(buffer, "%.3g/s", rate);
        } else if (sample.frames > 0) {
            {
                String duration = formatTime(sample.f());
                const char *value = duration.capacity >= 16
                    ? duration.pointer : duration.buffer;
                sprintf(buffer, "%s, %.3gfps (%.3g%%)", value,
                        sample.getActualFPS(), rate * 100.0);
            }
        } else {
            sprintf(buffer, "%.3g%%", rate * 100.0);
        }

        text = buffer;
    } else {
        rate = 0.0;
        text = "?";
    }
}
