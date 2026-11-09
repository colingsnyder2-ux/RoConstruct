// from server: 100% by atomic.potato
struct S
{
    int pad[90];
    int ActionStation();
};

extern "C" int __fastcall TargetActionStation(int);

int S::ActionStation()
{
    if (pad[90])
        return TargetActionStation(pad[90]);
    return 0;
}
