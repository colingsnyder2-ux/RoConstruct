// from server: 50% by Intel
struct RBX_GameSettings {
    char pad0[156];
    char m_x;

    char f();
};
char RBX_GameSettings::f()
{
    return m_x;
}
