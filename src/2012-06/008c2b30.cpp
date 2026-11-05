// from server: 75% by atomic.potato
extern "C" void __cdecl Notify(void*);

struct BillboardGui
{
    void SetEnabled(unsigned char value);
};

void BillboardGui::SetEnabled(unsigned char value)
{
    if (reinterpret_cast<unsigned char*>(this)[0x101] != value)
    {
        reinterpret_cast<unsigned char*>(this)[0x101] = value;
        Notify(reinterpret_cast<void*>(0x00e53238));
    }
}
