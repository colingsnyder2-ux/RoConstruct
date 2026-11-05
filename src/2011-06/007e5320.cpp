// from server: 87% by atomic.potato
struct AdvMoveToolBase {
    int f(int);
};

extern "C" int __cdecl helper(AdvMoveToolBase *, int);

int AdvMoveToolBase::f(int value)
{
    int result;
    result = value;
    result = helper(this, result);
    result = ((int (__thiscall *)(AdvMoveToolBase *, int))(*(int **)this)[2])(this, value);
    return result;
}
