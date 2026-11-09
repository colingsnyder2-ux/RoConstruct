// from server: 100% by colin
struct CIDEDocManager {
    char pad[8];
    int* begin;
    int* end;
};

extern "C" int __stdcall sub_4483B0(int, int, int);

int __stdcall sub_448510(CIDEDocManager* mgr, int a, int b) {
    if (mgr == 0) {
        return 0x80070057;
    }
    int* p = mgr->begin;
    int result = 1;
    if (p < mgr->end) {
        do {
            if (result < 0) break;
            int v = *p;
            if (v != 0) {
                result = sub_4483B0(v, a, b);
            }
            p++;
        } while (p < mgr->end);
    }
    return result;
}
