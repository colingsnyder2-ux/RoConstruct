// from server: 100% by colin
struct RBX_ToolMouseCommand {
    char pad[0xe8];
    int field_e8;
    int field_ec;
    int field_f0;
    int field_f4;
    void setData(const int* data);
};

void RBX_ToolMouseCommand::setData(const int* data)
{
    field_e8 = data[0];
    field_ec = data[1];
    field_f0 = data[2];
    field_f4 = data[3];
    field_e8 = 0;
}
