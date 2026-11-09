// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast

struct String
{
    char storage[20];
    unsigned int length;
    unsigned int capacity;
};

__declspec(dllimport) bool __cdecl equalString(const String&, const char*);
extern const double* infinityValue;
extern const double* nanValue;
extern double __cdecl parseFloat(const String&);

bool __cdecl stringToFloat(const String& text, double& result)
{
    unsigned n = text.length;
    if (!n)
        return false;

    if (equalString(text, "INF"))
    {
        result = *infinityValue;
        return true;
    }

    if (equalString(text, "-INF"))
    {
        result = -*infinityValue;
        return true;
    }

    if (equalString(text, "NAN"))
    {
        result = *nanValue;
        return true;
    }

    try
    {
        result = parseFloat(text);
        return true;
    }
    catch (...)
    {
        return false;
    }
}