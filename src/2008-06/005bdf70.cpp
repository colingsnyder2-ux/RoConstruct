// from server: 100% by king_originala
struct String;

extern const double* infinity;
extern String* (__thiscall *constructString)(String*, const char*);
extern int (__cdecl *formatString)(char*, unsigned int, const char*, ...);

extern const char positiveInfinityText[];
extern const char negativeInfinityText[];
extern const char nanText[];
extern const char numberFormat[];

String* __cdecl convertNumber(String* result, const double& value)
{
    char buffer[64];
    volatile int state = 0;

    if (value == *infinity)
    {
        constructString(result, positiveInfinityText);
        return result;
    }

    if (value == -*infinity)
    {
        constructString(result, negativeInfinityText);
        return result;
    }

    if (!(value < 0.0 || value >= 0.0))
    {
        constructString(result, nanText);
        return result;
    }

    formatString(buffer, 64, numberFormat, value);
    constructString(result, buffer);
    return result;
}
