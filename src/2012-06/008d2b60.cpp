// from server: 58% by atomic.potato
struct RBX_Handles
{
    int GetValue();
};

int RBX_Handles::GetValue()
{
    int v = *(int*)((char*)this + 0x188);
    if (v > 3)
        return 0;
    switch (v)
    {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    default:
        return 0;
    }
}
