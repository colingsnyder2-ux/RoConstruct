// from server: 60% by atomic.potato
struct Animator {
    char pad0[4];
    char* begin;
    char* end;
    char* cap;
    void insert(char* pos, int count, const char* val);
};

extern "C" void __stdcall sub_7b2650(char* dst, int count, char* src, int a, int b, int c);
extern "C" void __stdcall sub_8fdeb0(Animator* self, char** out, char* pos, char* val);

void Animator::insert(char* pos, int count, const char* val) {
    char* b = begin;
    int n1;
    if (b == 0) {
        n1 = 0;
    } else {
        n1 = (int)((cap - b) / 36);
    }
    int n2 = (int)((end - b) / 36);
    if (n2 < n1) {
        char tmp = 0;
        sub_7b2650(end, 1, (char*)&tmp, (int)val, (int)val, (int)val);
        end += 36;
    } else {
        sub_8fdeb0(this, &end, end, (char*)val);
    }
}
