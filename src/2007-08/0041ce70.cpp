// from server: 100% by colin
struct InsertDecal {
    bool sub_563C60();
    int sub_41CB60();
    int check();
};

int InsertDecal::check() {
    if (sub_563C60()) {
        if (sub_41CB60() != 0) {
            return 1;
        }
    }
    return 0;
}
