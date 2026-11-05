// from server: 44% by atomic.potato
extern "C" int sub_5e0c40(void *);
extern "C" int sub_5e4990(void *, int);
extern "C" int sub_59e320(int, int);

struct StopCommand
{
    int field_0c;
    int field_10;
    int stop();
};

int StopCommand::stop()
{
    int value = field_0c;
    sub_5e0c40(this);
    int result = sub_5e4990(&field_10, 1);
    return sub_59e320(result, 2);
}
