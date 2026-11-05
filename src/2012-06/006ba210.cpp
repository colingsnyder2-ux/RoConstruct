// from server: 100% by Intel
struct VStandardOut {
    static void sp_counted_impl_p();
};

void VStandardOut::sp_counted_impl_p() {
    extern char byte_E2E128;
    byte_E2E128 = 0;
}
