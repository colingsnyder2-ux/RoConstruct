// from server: 100% by tester
struct UserInputBase {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
    void getSteerThrottle(float* out, const float* in, int steerMode, int throttleMode);
};

void UserInputBase::getSteerThrottle(float* out, const float* in, int steerMode, int throttleMode)
{
    out[0] = 0.0f;
    out[1] = 0.0f;

    switch (steerMode) {
    case 2:
        out[0] = in[0] + this->unk0;
        break;
    case 3:
        out[0] = this->unk8 - in[0];
        break;
    }

    switch (throttleMode) {
    case 0:
        out[1] = in[1] + this->unk4;
        break;
    case 1:
        out[1] = this->unkC - in[1];
        break;
    }
}
