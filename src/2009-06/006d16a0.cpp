// from server: 100% by why2
struct HumanoidState
{
    float getHeartbeat() const;
};

extern float g_heartbeat;

float HumanoidState::getHeartbeat() const
{
    return g_heartbeat;
}
