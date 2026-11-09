// from server: 53% by atomic.potato
struct LuaArguments {
    bool getNumber(int index, double* out);
};

bool LuaArguments::getNumber(int index, double* out) {
    double value;
    if (!this->getNumber(index, &value))
        return false;
    *out = (double)(int)value;
    return true;
}
