// from server: 98% by tajop

struct String_00555e30 {
    char alval[4];
    char bx[16];
    unsigned size;
    unsigned res;
    String_00555e30(const String_00555e30&);
    ~String_00555e30();
};
extern void (String_00555e30::*g_copy_00555e30)(const String_00555e30&);
extern void (String_00555e30::*g_dtor_00555e30)();
inline String_00555e30::String_00555e30(const String_00555e30& o)
{
    (this->*g_copy_00555e30)(o);
}
inline String_00555e30::~String_00555e30()
{
    (this->*g_dtor_00555e30)();
}
struct AbuseReporter_00555e30 {
    char data[12];
    AbuseReporter_00555e30(String_00555e30 url);
    ~AbuseReporter_00555e30();
};
struct ScopedPtr_00555e30 {
    AbuseReporter_00555e30* ptr;
    void reset(AbuseReporter_00555e30* p = 0)
    {
        AbuseReporter_00555e30* old = ptr;
        ptr = p;
        delete old;
    }
};
struct Players_00555e30 {
    char pad[0x18c];
    ScopedPtr_00555e30 abuseReporter;
    void setAbuseReportUrl(String_00555e30 url);
};
void Players_00555e30::setAbuseReportUrl(String_00555e30 url)
{
    if (url.size == 0)
        abuseReporter.reset();
    else
        abuseReporter.reset(new AbuseReporter_00555e30(url));
}
