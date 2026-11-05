// from server: 65% by colin
struct VCWorkspace_CComObject {
    int field0;
    int field4;
    int field8;
    int Remove(int index);
};

int VCWorkspace_CComObject::Remove(int index) {
    int* arr;
    int count;
    int elem;
    int result;

    if (index == 0 || index > this->field8) {
        elem = 0;
    } else {
        int i = index - 1;
        if (i >= 0 && i < this->field8) {
            arr = (int*)this->field4;
            elem = arr[i];
        } else {
            elem = 0;
        }
    }

    int i = index - 1;
    if (i < (unsigned)index && i < (unsigned)this->field8) {
        arr = (int*)this->field4;
        if (arr[i] != 0) {
            arr[i] = 0;
            result = 1;
        } else {
            result = 0;
        }
    } else {
        result = 0;
    }

    int hr = (result == 0) ? (int)0x80040200 : (int)0x00040200;

    if (hr == 0 && elem != 0) {
        void** vtbl = *(void***)elem;
        void (__stdcall *fn)(int) = (void (__stdcall *)(int))vtbl[2];
        fn(elem);
    }

    return hr;
}
