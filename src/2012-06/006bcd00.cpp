// from server: 32% by Intel
struct VStandardOut_sp_counted_impl_p {
    void release();
};

void VStandardOut_sp_counted_impl_p::release() {
    struct Callback {
        void (__stdcall *func)(int, void*, void*);
    };
    Callback* cb = *reinterpret_cast<Callback**>(reinterpret_cast<char*>(this) + 0x68);
    if (cb && cb->func) {
        cb->func(2, this + 0x70, this + 0x70);
    }
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x68) = 0;
    this->~VStandardOut_sp_counted_impl_p();
}
