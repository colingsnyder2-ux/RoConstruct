// from server: 65% by atomic.potato
struct RbxCullableSceneNode
{
    int GetValue();
    char padding_0[0x170];
    int field_170;
    char padding_174[0x3c];
    int field_210;
};

int RbxCullableSceneNode::GetValue()
{
    int value = field_170 + 0x45d0;
    if (value == 0)
        return 0;
    return field_210 <= *(int *)(value + 0x184);
}
