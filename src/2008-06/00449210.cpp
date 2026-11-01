// from server: 100% by king_originala
struct CRenderSettings {
    char padding[0x138];
    int value;
    void setValue(int);
    void notify(void*);
};

void CRenderSettings::setValue(int v)
{
    if (v != value) {
        value = v;
        notify(reinterpret_cast<void*>(0x96d3ec));
    }
}
