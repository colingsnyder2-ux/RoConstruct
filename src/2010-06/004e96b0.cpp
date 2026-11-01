// from server: 100% by atomic.potato
struct VRayHolder
{
    float Method();
};

extern "C" void __cdecl Function4E1200(int other, float value);

void Function4E96B0(VRayHolder* holder, int other)
{
    Function4E1200(other, holder->Method());
}
