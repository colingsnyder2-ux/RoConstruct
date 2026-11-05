// from server: 68% by atomic.potato
struct HumanoidState
{
    int field8;
    int f();
};

extern "C" int __cdecl G1_func_0067e0c0(int);
extern "C" int G1_func_0079bd40(int);

int HumanoidState::f()
{
    return G1_func_0079bd40(G1_func_0067e0c0(field8)) != 0;
}
