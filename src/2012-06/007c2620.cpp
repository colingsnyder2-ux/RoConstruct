// from server: 84% by tester
struct MegaClusterInstance
{
    char pad[0x31e];
    int field_31e;
    short field_322;
    void getRegion(int* out);
};

void MegaClusterInstance::getRegion(int* out)
{
    out[0] = field_31e;
    *(short*)((char*)out + 4) = field_322;
}
