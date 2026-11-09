// from server: 36% by Viper
extern "C" unsigned long __stdcall FormatMessageA(unsigned long, const void*, unsigned long, unsigned long, char*, unsigned long, void*);
extern "C" unsigned long __stdcall GetLastError();

struct string_impl
{
    void* data[4];
    void dtor();
    const char* c_str() const;
    unsigned int size() const;
};

extern "C" int __cdecl sub_5017C0(char*, const char*, ...);

struct CRenderSettings
{
    char* __cdecl formatError(char* out, unsigned long errorCode);
};

char* CRenderSettings::formatError(char* out, unsigned long errorCode)
{
    char buffer[264];
    string_impl msg;
    unsigned long result;
    unsigned long lastError;

    result = FormatMessageA(0x1000, 0, errorCode, 0x800, buffer, 0x100, 0);
    if (result == 0)
    {
        lastError = GetLastError();
        if (lastError > 0)
        {
            sub_5017C0(out, "%s - HRESULT=%d", "Error", errorCode);
        }
        else
        {
            sub_5017C0(out, "Error - %s", "Error");
        }
    }
    else
    {
        lastError = GetLastError();
        if (lastError > 0)
        {
            sub_5017C0(out, "%s - HRESULT=%d", buffer, errorCode);
        }
        else
        {
            sub_5017C0(out, "%s - %s", buffer, "Error");
        }
    }

    msg.dtor();
    return out;
}
