// from server: 100% by Intel
struct CXTPRichRender_XTextHost {
    bool IsValid();
};

bool CXTPRichRender_XTextHost::IsValid() {
    return *(int *)((char *)this + 8) != 0;
}
