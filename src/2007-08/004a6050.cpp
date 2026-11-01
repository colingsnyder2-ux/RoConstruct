// from server: 100% by colin
extern "C" int __cdecl sub_00630D36(int, int, int, int, int);

struct RBX_JointsService
{
    bool method_004a6050(int arg);
};

bool RBX_JointsService::method_004a6050(int arg)
{
    int result = sub_00630D36(arg, 0, 0x881f4c, 0x891534, 0);
    return result != 0;
}
