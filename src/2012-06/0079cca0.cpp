// from server: 100% by Intel
struct VHumanoid
{
    bool RemoteEventDesc();
};

bool VHumanoid::RemoteEventDesc()
{
    return (*reinterpret_cast<int*>(this + 0x40)) & 1;
}
