// from server: 65% by atomic.potato
struct Scale9Frame
{
    int method(float);
    struct Receiver
    {
        int method(float);
    };
    Receiver *field90;
};

int Scale9Frame::method(float value)
{
    return field90->method(value);
}
