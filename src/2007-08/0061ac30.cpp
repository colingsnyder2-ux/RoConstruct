// from server: 100% by colin
struct RBX_ToolMouseCommand {
    char pad[0xf6];
    short field_f6;
    int getField();
};

extern int G_func_00601390();

int RBX_ToolMouseCommand::getField()
{
    G_func_00601390();
    return field_f6;
}
