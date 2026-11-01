// from server: 100% by colin
struct RakPeer
{
    void setLimit(double value, int a, int b);
};

void RakPeer::setLimit(double value, int a, int b)
{
    *(double*)((char*)this + 0x790) = value;
    *(int*)((char*)this + 0x798) = a;
    *(int*)((char*)this + 0x79c) = b;
}
