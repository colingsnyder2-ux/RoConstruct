// from server: 60% by Intel
struct Result {
    unsigned int first;
    unsigned int second;
};

struct Source {
    void copy(Result* output);
};

struct CRobloxReportView {
    unsigned char padding[0x54];
    Source* source;
    Result* __cdecl func(Result* output);
};

extern "C" void __stdcall sub_630298(CRobloxReportView*);

Result* CRobloxReportView::func(Result* output) {
    sub_630298(this);
    Source* src = source;
    if (src) {
        src->copy(output);
    } else {
        output->first = 0;
        output->second = 0;
    }
    return output;
}
