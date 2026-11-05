// from server: 43% by atomic.potato
typedef char StringObject;

extern "C" void std_string_copy(StringObject *, const StringObject *);

struct Frame
{
    int pad;
    StringObject value;
    int fields[7];
    Frame *f(StringObject *);
};

Frame *Frame::f(StringObject *source)
{
    std_string_copy(&value, source);
    return (Frame *)source;
}
