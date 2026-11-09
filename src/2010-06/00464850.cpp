// from server: 63% by atomic.potato
struct InsertModelFromRobloxVerb
{
    char pad[0x10];
    void* value;
    double time;
    bool ShouldShow();
};

extern "C" void __cdecl UpdateShader();

double g_TimeLimit;

bool InsertModelFromRobloxVerb::ShouldShow()
{
    UpdateShader();
    if (this->time + g_TimeLimit <= 0.0)
        return false;
    return true;
}
