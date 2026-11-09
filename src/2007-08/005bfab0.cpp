// from server: 72% by colin
struct LuaArguments {
    char pad0[4];
    int* begin;
    int* end;
    int find(const char* key, int* out) const;
};

extern "C" int __stdcall compare_string(const char*, const char*);
extern "C" void __stdcall invalid_parameter_noinfo();

int LuaArguments::find(const char* key, int* out) const {
    int lo = 0;
    int hi;
    if (begin != 0) {
        hi = (int)(end - begin);
        if (hi != 0) {
            const char* k = key + 4;
            while (lo < hi) {
                int mid = (unsigned)(lo + hi) >> 1;
                if (begin == 0 || mid >= (int)(end - begin))
                    invalid_parameter_noinfo();
                int* elem = begin + mid;
                int* s = (int*)elem[0];
                const char* p = (const char*)(s[1] + 4);
                int r = compare_string(k, p);
                if (r < 0)
                    hi = mid;
                else if (r > 0)
                    lo = mid + 1;
                else {
                    int* b = begin;
                    if (b > end)
                        invalid_parameter_noinfo();
                    int* it = b + mid;
                    if (it > end || it < begin)
                        invalid_parameter_noinfo();
                    out[0] = (int)this;
                    out[1] = (int)it;
                    return (int)out;
                }
            }
        }
    }
    int* e = end;
    out[0] = 0;
    if (begin > e)
        invalid_parameter_noinfo();
    out[0] = (int)this;
    out[1] = (int)e;
    return (int)out;
}
