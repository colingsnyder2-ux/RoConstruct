// from server: 100% by king_originala
struct S;
void* __cdecl func_005d7670(S* object);

struct Model
{
    int func_00643d40();
};

struct HumanoidState
{
    char padding[8];
    S* object;

    int func_00643eb0();
};

int HumanoidState::func_00643eb0()
{
    return static_cast<Model*>(func_005d7670(object))->func_00643d40() != 0;
}
