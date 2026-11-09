// from server: 30% by colin
struct DxUserInput {
    char pad[0x34];
    int field34;
    char pad2[0x30];
    char field68;
    int getCursorPosInternal(int* out);
    int getGameCursorPositionInternal(int* out);
    int getCursorPosition(int* out);
};

extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" int __cdecl sub_0041D870(int, int);

int DxUserInput::getCursorPosition(int* out)
{
    int local8;
    char localC;
    int local10;
    int local18;
    int local28;

    local8 = (int)&field34;
    localC = 0;
    sub_0041D870((int)&local8, 0);
    local28 = 0;

    int* result;
    if (field68) {
        getCursorPosInternal(&local10);
        result = &local10;
    } else {
        getGameCursorPositionInternal(&local18);
        result = &local18;
    }

    if (localC) {
        LeaveCriticalSection((void*)local8);
    }

    out[0] = result[0];
    out[1] = result[1];
    return (int)out;
}
