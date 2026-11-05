// from server: 87% by atomic.potato
extern "C" void sub_00414da0(void*, const char*);

struct Scale9Frame
{
    int pad[124];
    int value;
    virtual void update();
    void setValue(int);
};

void Scale9Frame::setValue(int value)
{
    if (this->value != value)
    {
        this->value = value;
        sub_00414da0(this, "|$0PW");
        this->update();
    }
}
