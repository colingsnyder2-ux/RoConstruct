// from server: 91% by Intel
extern "C" int __stdcall WaitForSingleObject(int handle, int milliseconds);

struct CSourceStream {
    int field_4;
    int field_C;
    int Wait(int milliseconds);
};

int CSourceStream::Wait(int milliseconds) {
    int handle = this->field_4;
    int result = WaitForSingleObject(handle, 0);
    if (result != 0) {
        return 0;
    }
    if (milliseconds != 0) {
        *reinterpret_cast<int*>(milliseconds) = this->field_C;
    }
    return 1;
}
