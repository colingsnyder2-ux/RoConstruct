// from server: 100% by king_originala
struct seg_00720000;
struct S;

extern "C" int __stdcall func_007a6cc0(void*);
extern "C" int __stdcall func_007a7bb0(void*);
extern "C" int __stdcall func_0072d180(seg_00720000*);
extern "C" int __stdcall sub_72e9b0(S*);

struct StreamOwner {
    void* stream;
    int finish(bool reset, bool compress);
};

int StreamOwner::finish(bool reset, bool compress)
{
    void* p = stream;
    if (compress) {
        if (reset)
            return func_007a7bb0(p);
        return func_0072d180(static_cast<seg_00720000*>(p));
    }

    if (reset)
        return func_007a6cc0(p);
    return sub_72e9b0(static_cast<S*>(p));
}
