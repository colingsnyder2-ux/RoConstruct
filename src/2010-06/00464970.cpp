// from server: 89% by atomic.potato
struct ToggleIDEModeVerb
{
    int f();
};

struct ToggleIDEModeVerbRoot
{
    int pad;
    ToggleIDEModeVerb* value;
};

extern "C" ToggleIDEModeVerbRoot* __cdecl GetToggleIDEModeVerb();

int ToggleIDEModeVerb::f()
{
    return ((unsigned char*)GetToggleIDEModeVerb()->value + 0x20)[0x108 - 0x20] == 0;
}
