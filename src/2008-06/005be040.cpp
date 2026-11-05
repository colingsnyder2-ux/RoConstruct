// from server: 100% by king_originala
struct String;

extern float* infinityValue;
extern void (__thiscall *constructString)(String*, const char*);
extern int (__cdecl *formatString)(char*, unsigned int, const char*, ...);

#pragma float_control(precise, off, push)

String* __cdecl formatFloat(String* result, const float& value)
{
    volatile int state = 0;
    char buffer[32];

    if (value == *infinityValue)
    {
        constructString(result, "INF");
        return result;
    }

    if (-*infinityValue == value)
    {
        constructString(result, "-INF");
        return result;
    }

    if (!(value < 0.0f || value >= 0.0f))
    {
        constructString(result, "NAN");
        return result;
    }

    formatString(buffer, 32, "%.9g", value);
    constructString(result, buffer);
    return result;
}

#pragma float_control(pop)
