// from server: 78% by atomic.potato
struct GuiLayerCollector
{
};

extern "C" GuiLayerCollector *__cdecl sub_66c780(int);

unsigned char __cdecl f(int value)
{
    GuiLayerCollector *p = sub_66c780(value);
    return !*(unsigned char *)((char *)p + 0x180);
}
