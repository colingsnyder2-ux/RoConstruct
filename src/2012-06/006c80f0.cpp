// from server: 64% by Intel
struct GlobalAdvancedSettings {
    int func(GlobalAdvancedSettings* arg);
};

int GlobalAdvancedSettings::func(GlobalAdvancedSettings* arg) {
    int result = 0;
    if (this != arg) {
        result = 1;
    }
    return result;
}
