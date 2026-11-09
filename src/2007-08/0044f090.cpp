// from server: 45% by Intel
struct CameraTiltUpCommand {
    int* field_0;
    int field_4;

    int f();
};

extern "C" int __stdcall pubsync(void*);

int CameraTiltUpCommand::f() {
    __try {
        int* v0 = field_0;
        int v1 = field_4;
        int v2 = *v0;
        int* v3 = (int*)v2;
        int v4 = *v3;
        if (v1 & 2) {
            pubsync((void*)(v4 + 4));
        }
    }
    __except (0) {
    }
    return 0;
}
