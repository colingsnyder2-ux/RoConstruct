// from server: 100% by why2
struct HumanoidState
{
    float getValue();
};

float HumanoidState::getValue()
{
    extern float g_value;
    return g_value;
}
