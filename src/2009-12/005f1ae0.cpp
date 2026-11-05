// from server: 31% by atomic.potato
extern "C" int f_005f1c2f();

extern "C" int (*const f_005f1c80[8])() =
{
    f_005f1c2f,
    f_005f1c2f,
    f_005f1c2f,
    f_005f1c2f,
    f_005f1c2f,
    f_005f1c2f,
    f_005f1c2f,
    f_005f1c2f
};

int f_005f1ae0(unsigned int value)
{
    if (value > 7)
        return f_005f1c2f();
    return f_005f1c80[value]();
}
