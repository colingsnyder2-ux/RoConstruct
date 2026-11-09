// from server: 57% by atomic.potato
extern "C" void f00409390(void *, int);

struct S
{
    int value;
    int pad[9];
    int statusCode;
    S(int);
};

S::S(int code)
{
    f00409390(this, code);
    value = 0x9cc72c;
    statusCode = code;
}
