// from server: 100% by tester
struct CRenderSettings {
    char padding[0x1ac];
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
