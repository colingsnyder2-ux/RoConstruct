// from server: 100% by atomic.potato
struct Ball
{
    char padding0[4];
    Ball* field4;
    char padding8[0x28];
    struct Node* field30;
    struct Node2* field34;

    void f();
};

struct Node
{
    char padding0[4];
    char field4;
};

struct Node2
{
    char padding0[8];
    char field8;
};

void Ball::f()
{
    if (this->field30 != 0 && this->field30->field4 != 0)
        return;

    if (this->field4 != 0)
    {
        this->field4->f();
    }
    else if (this->field34 != 0)
    {
        this->field34->field8 = 1;
    }

    if (this->field30 != 0)
        this->field30->field4 = 1;
}
