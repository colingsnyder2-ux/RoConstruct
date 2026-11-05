// from server: 33% by Intel
struct CRenderSettings {
    int GetValue(int, int);
};

int CRenderSettings::GetValue(int a, int b) {
    int v0 = *(int*)this;
    int v1 = a * *(int*)((char*)this + 4) + b;
    return *(int*)((char*)*(int*)((char*)this + 16) + v1 * 8);
}
