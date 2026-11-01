// from server: 100% by king_originala
struct LightInfo
{
    unsigned char data[24];
};

typedef bool (__thiscall *CompareLightInfo)(const LightInfo *, const LightInfo &);
extern CompareLightInfo compareLightInfo;

bool __cdecl equalLightInfo(const LightInfo *first, const LightInfo *last,
                           const LightInfo *other)
{
    for (; first != last; ++first, ++other)
    {
        if (!compareLightInfo(first, *other))
            return false;
    }
    return true;
}
