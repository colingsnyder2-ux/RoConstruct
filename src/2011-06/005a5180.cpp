// from server: 66% by atomic.potato
struct SoundJob
{
    int value;
    int Run();
};

extern "C" int __stdcall sub_5a4ab0(int);

int SoundJob::Run()
{
    sub_5a4ab0(value);
    return 1;
}
