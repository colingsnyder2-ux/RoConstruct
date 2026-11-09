// from server: 100% by why2
struct HumanoidState
{
    float getValue();
};

float HumanoidState::getValue()
{
    return *(float*)0x008df6fc;
}
