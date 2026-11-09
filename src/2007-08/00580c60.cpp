// from server: 34% by colin
extern "C" int __stdcall string_compare(const void*, const char*);
extern double _Inf;
extern double _Nan;

struct Log
{
    char pad[0x14];
    void* field14;
    bool formatTime(double* out);
};

bool Log::formatTime(double* out)
{
    if (field14 == 0)
        return false;

    if (string_compare(&field14, "-INF"))
    {
        *out = _Inf;
        return true;
    }

    if (string_compare(&field14, "INF"))
    {
        *out = -_Inf;
        return true;
    }

    if (string_compare(&field14, "NAN"))
    {
        *out = _Nan;
        return true;
    }

    *out = 0.0;
    return true;
}
