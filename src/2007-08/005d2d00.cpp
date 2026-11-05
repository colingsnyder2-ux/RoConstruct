// from server: 100% by colinlaptop
struct RBX_Tool {
    int checkPermission();
};

int RBX_Tool::checkPermission() {
    if (*(int*)((char*)this + 0x16c) >= 5) {
        return 1;
    } else {
        return 0;
    }
}
