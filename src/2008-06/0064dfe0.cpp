// from server: 100% by tester
void helper_601390();

namespace RBX {
    struct ToolMouseCommand {
        char pad[0x140];
        short field_f0;
        int getValue();
    };
}

int RBX::ToolMouseCommand::getValue()
{
    helper_601390();
    return this->field_f0;
}
