// from server: 25% by atomic.potato
struct CRobloxControlMaterialSelector {
    int SelectMaterial(int, int);
    void UpdateControl(int);
    int material;
};

int CRobloxControlMaterialSelector::SelectMaterial(int a, int b)
{
    int result = 0;
    if (result != -1) {
        material = result;
        UpdateControl(1);
    }
    return result;
}

void CRobloxControlMaterialSelector::UpdateControl(int a)
{
}
