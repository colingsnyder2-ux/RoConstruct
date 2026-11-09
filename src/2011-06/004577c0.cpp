// from server: 50% by colin
struct CRenderSettingsItem {
    char pad[0x105];
    bool field105;
    bool field106;
    void notifyChange();
    void setDebugDisableInterpolation(bool value);
};

void CRenderSettingsItem::setDebugDisableInterpolation(bool value) {
    bool oldCombined = field105 || field106;
    field106 = value;
    bool newCombined = field105 || value;
    if (oldCombined != newCombined) {
        notifyChange();
    }
}
