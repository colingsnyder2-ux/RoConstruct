// from server: 100% by colin
struct RBX_DataModel {
    char pad_0[0x74];
    bool field_74;
    void setFlag(bool value);
};

void RBX_DataModel::setFlag(bool value)
{
    field_74 = value;
}
