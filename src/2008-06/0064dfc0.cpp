// from server: 100% by tester
struct ToolMouseCommand {
    char pad[0x13a];
    short field_f4;
    int getValue();
};

void helper_601390();

int ToolMouseCommand::getValue()
{
    helper_601390();
    return this->field_f4;
}
