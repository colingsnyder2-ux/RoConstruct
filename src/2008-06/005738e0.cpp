// from server: 100% by king_originala
struct Vector2 {
    float x, y;

    Vector2() {}
    Vector2(float a, float b) : x(a), y(b) {}
};

extern float scaleX;
extern float scaleY;

const Vector2& __cdecl zeroVector();
Vector2 __cdecl transformVector(const Vector2&);

struct UserInputBase {
    float unk0;
    float unk4;
    float unk8;
    float unkC;

    void getSteerThrottle(float* out, const float* in,
                          int steerMode, int throttleMode);
};

struct PercentPanel {
    char padding[0x15c];
    int steerMode;
    int throttleMode;
    Vector2 value;

    Vector2 getInput();
};

Vector2 PercentPanel::getInput()
{
    Vector2 scale(scaleX, scaleY);
    const Vector2& zero = zeroVector();
    UserInputBase input = { zero.x, zero.y, scale.x, scale.y };
    Vector2 transformed = transformVector(value);
    Vector2 result;
    input.getSteerThrottle(&result.x, &transformed.x,
                          steerMode, throttleMode);
    return result;
}
