// from server: 100% by tester
struct RBX_ToolMouseCommand {
    char pad[0x138];
    short field_f2;
    int getField();
};

extern int G_func_00601390();

int RBX_ToolMouseCommand::getField()
{
    G_func_00601390();
    return field_f2;
}
