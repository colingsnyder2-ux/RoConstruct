// from server: 100% by colin
struct EventHandler {
    int setFlag(int unused, int* out);
};

int EventHandler::setFlag(int unused, int* out) {
    *out = 0;
    return 0;
}
