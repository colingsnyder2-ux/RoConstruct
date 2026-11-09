// from server: 100% by atomic.potato
struct SceneManager {
    void setShadowUseInfiniteFarPlane(bool value);
};

extern int g_var;

void SceneManager::setShadowUseInfiniteFarPlane(bool value)
{
    void (__thiscall *fn)(void*, bool, int);
    fn = *(void (__thiscall **)(void*, bool, int))(*(char**)this + 0x33c);
    fn(this, value, g_var);
}
