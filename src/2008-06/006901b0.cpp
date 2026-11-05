// from server: 100% by king_originala
struct LightInfo {
    char data[24];
};

extern LightInfo& (__thiscall *assignLightInfo)(LightInfo*, const LightInfo&);

void __cdecl fillLightInfo(LightInfo* first, LightInfo* last, const LightInfo& value)
{
    for (; first != last; ++first)
        assignLightInfo(first, value);
}
