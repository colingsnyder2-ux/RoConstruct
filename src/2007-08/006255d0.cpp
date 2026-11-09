// from server: 39% by colin
struct UnlockedPartByLocalCharacter {
    bool filterResult(int* outIndex, float* outPos, int* outIndex2, float* outPos2) const;
};

extern "C" int __stdcall sub_7377A0(int, int, int, int, int);

bool UnlockedPartByLocalCharacter::filterResult(int* outIndex, float* outPos, int* outIndex2, float* outPos2) const {
    int i;
    for (i = 0; i < 6; ++i) {
        float pos[3];
        int idx;
        int result = sub_7377A0((int)this, (int)&idx, (int)pos, (int)outIndex, (int)outPos);
        if (result != 0) {
            *outIndex2 = i;
            outPos2[0] = pos[0];
            outPos2[1] = pos[1];
            outPos2[2] = pos[2];
            return true;
        }
    }
    return false;
}
