// from server: 100% by tester
struct VCWorkspaceCComObject
{
    char pad[0x2c];
    int field10;
    int field14;
    int field18;
    int field1c;
    void assign(const int* src);
};

void VCWorkspaceCComObject::assign(const int* src)
{
    field10 = src[0];
    field14 = src[1];
    field18 = src[2];
    field1c = src[3];
}
