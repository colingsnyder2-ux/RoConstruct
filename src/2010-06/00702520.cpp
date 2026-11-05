// from server: 100% by tester
struct VHumanoid
{
    bool RemoteEventDesc();
};

bool VHumanoid::RemoteEventDesc()
{
    return (*reinterpret_cast<int*>(this + 0x3c)) & 1;
}