// from server: 100% by colin
struct DataModelInner {
    char pad0[0xb0];
    float value;
};

struct DataModel {
    char pad0[0x1e0];
    DataModelInner* inner;
    float getValue();
};

float DataModel::getValue()
{
    return inner->value;
}
