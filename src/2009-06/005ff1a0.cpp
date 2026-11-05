// from server: 28% by tester
struct RunTransition {
    int oldState;
    int newState;
    RunTransition(int oldState, int newState);
};

extern "C" int __cdecl sub_5D2E80();
extern "C" int __cdecl sub_4CF510();

int g_counter;

RunTransition::RunTransition(int oldState, int newState)
{
    sub_5D2E80();
    *(int*)((char*)this + 0x00) = 0x8d72ec;
    *(int*)((char*)this + 0x14) = 0x8d72dc;
    *(int*)((char*)this + 0x18) = 0x8d72d4;
    *(int*)((char*)this + 0x20) = 0x8d72cc;
    *(int*)((char*)this + 0x1c) = sub_4CF510();
    g_counter++;
}
