// from server: 100% by king_originala
extern "C" void (__stdcall *EnterCriticalSection)(void *);
extern "C" void (__stdcall *LeaveCriticalSection)(void *);

struct Vec2 {
    float x;
    float y;
};

struct DxUserInput {
    char padding0[0x34];
    char criticalSection[0x18];
    char padding1[0x146];
    unsigned char active;

    Vec2 *getActive(Vec2 *);
    Vec2 *getInactive(Vec2 *);
    Vec2 *getPosition(Vec2 *);
};

Vec2 *DxUserInput::getPosition(Vec2 *result)
{
    Vec2 activeValue;
    Vec2 inactiveValue;
    Vec2 *value;

    EnterCriticalSection(criticalSection);
    if (active)
        value = getActive(&activeValue);
    else
        value = getInactive(&inactiveValue);

    result->x = value->x;
    result->y = value->y;
    LeaveCriticalSection(criticalSection);
    return result;
}
