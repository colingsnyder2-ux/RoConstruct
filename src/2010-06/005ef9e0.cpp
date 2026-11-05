// from server: 100% by tester
extern int g_9494d8;
extern int g_9494dc;
extern int g_9493e0;
extern int g_949444;
extern int g_949448;
extern int g_9494ac;
extern int g_9494b0;
extern int g_9494d4;

struct ChangeHistoryService {
    int getIndex(int value);
};

int ChangeHistoryService::getIndex(int value)
{
    if (g_9494d8 == value)
        return 0x3e;
    if (g_9494dc == value)
        return 0x3f;
    if (g_9493e0 <= value && g_949444 >= value)
        return value - g_9493e0;
    if (g_949448 <= value && g_9494ac >= value)
        return value - g_949448 + 0x1a;
    if (g_9494b0 <= value && g_9494d4 >= value)
        return value - g_9494b0 + 0x34;
    return (value == 0x3d) ? -1 : -2;
}
