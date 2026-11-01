// from server: 66% by colin
struct RBX_DataModel {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xc;
    int field_0x10;
    int getValue();
};

int RBX_DataModel::getValue()
{
    int a = field_0xc;
    if (a == 0) {
        int c = 10;
        return (c > a) ? 1 : 0;
    }
    int b = field_0x10 - a;
    int q = b / 72;
    int c = 10;
    return (c > q) ? 1 : 0;
}
