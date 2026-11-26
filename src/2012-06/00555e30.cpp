// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct AbuseReporter {
    char data[12];
    AbuseReporter(std::string url);
    ~AbuseReporter();
};
struct ScopedPtr {
    AbuseReporter* ptr;
    void reset(AbuseReporter* p = 0)
    {
        AbuseReporter* old = ptr;
        ptr = p;
        delete old;
    }
};
struct Players {
    char pad[0x18c];
    ScopedPtr abuseReporter;
    void setAbuseReportUrl(std::string url);
};
void Players::setAbuseReportUrl(std::string url)
{
    if (url.empty())
        abuseReporter.reset();
    else
        abuseReporter.reset(new AbuseReporter(url));
}