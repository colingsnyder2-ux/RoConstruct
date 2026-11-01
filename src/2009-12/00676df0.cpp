// from server: 73% by atomic.potato
extern "C" char * std_string_assign(char *, const char *);

struct GlobalSettings
{
    int state;
    int mode;
    char *value;
    bool f(const char *source);
};

bool GlobalSettings::f(const char *source)
{
    if (mode == 2)
    {
        std_string_assign(value, source);
        return true;
    }
    return false;
}
