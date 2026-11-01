// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Interval {
    double sec;
    Interval(double s) : sec(s) {}
};
struct Streamer {
    char pad[0x1ec];
    void* peer;
    Interval getInterval(int unused);
};
Interval Streamer::getInterval(int)
{
    return !peer ? Interval(1.7976931348623157e+308) : Interval(0);
}
