// from server: 100% by colin
void helper_601390();

namespace RBX {
    struct ToolMouseCommand {
        char pad[0xf0];
        short field_f0;
        int getValue();
    };
}

int RBX::ToolMouseCommand::getValue()
{
    helper_601390();
    return this->field_f0;
}
