// from server: 56% by colin
extern double _Inf;
extern double _Nan;
extern double _Snan;

extern "C" int __cdecl _snprintf(char*, unsigned int, const char*, ...);

struct StdString {
    char buf[0x1c];
    StdString(const char*);
};

extern double* g_77e564;
extern double* g_77e544;
extern double* g_77e4a8;

struct Log {
    StdString* formatTime(double time);
};

StdString* Log::formatTime(double time)
{
    double* p;
    char buf[0x20];

    p = g_77e564;
    if (*p == time) {
        StdString temp("INF");
        *(StdString*)this = temp;
        return (StdString*)this;
    }
    if (-*p == time) {
        StdString temp("-INF");
        *(StdString*)this = temp;
        return (StdString*)this;
    }
    p = g_77e544;
    if (*p == time) {
        StdString temp("NAN");
        *(StdString*)this = temp;
        return (StdString*)this;
    }
    p = g_77e4a8;
    if (*p == time) {
        StdString temp("NAN");
        *(StdString*)this = temp;
        return (StdString*)this;
    }
    _snprintf(buf, 0x20, "%.9g", time);
    StdString temp(buf);
    *(StdString*)this = temp;
    return (StdString*)this;
}
