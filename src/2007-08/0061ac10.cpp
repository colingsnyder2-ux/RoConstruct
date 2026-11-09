// from server: 100% by colin
struct ToolMouseCommand {
    char pad[0xf4];
    short field_f4;
    int getValue();
};

void helper_601390();

int ToolMouseCommand::getValue()
{
    helper_601390();
    return this->field_f4;
}
