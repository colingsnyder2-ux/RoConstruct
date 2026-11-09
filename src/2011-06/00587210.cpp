// from server: 32% by atomic.potato
struct CRenderSettings
{
    int padding[128];
    int index;
    int GetValue();
};

int CRenderSettings::GetValue()
{
    return *reinterpret_cast<int *>(0x00cba474 + index * 0x30 + 0x0c);
}
