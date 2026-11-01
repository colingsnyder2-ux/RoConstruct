// from server: 41% by Intel




struct Sphere {
    int __cdecl getFace(int index, int flags, void* outFace);
};

extern "C" int __stdcall sub_652E70(void* thisPtr, int index, int flags);
extern "C" void __stdcall sub_650190(int a1, int a2, void* thisPtr);

int Sphere::getFace(int index, int flags, void* outFace) {
    if (index < 0)
        goto LABEL_ERROR_12;

    if (index >= *(int*)((char*)this + 0x28))
        goto LABEL_ERROR_12;

    int result = sub_652E70(this, index, flags);
    if (!result)
        return -1;

    if (!(flags & 8)) {
        int* array = *(int**)((char*)this + 0x30);
        int offset = index * 20;
        int type = array[offset / 4];

        if (type == 2 || type == 3) {
            int* entry = (int*)((char*)array + offset + 4);
            int func = entry[1];
            int thisPtr = entry[0];

            int ret = ((int(__stdcall*)(int, int, void*, int))func)(3, 0x28, outFace, thisPtr);
            if (ret >= 0) {
                *(int*)outFace = result;
                *(int*)((char*)outFace + 4) = index;
                return 0;
            }

            sub_650190(0, 0xF, (void*)((char*)this + 8));
            return -1;
        }
    }

    int* faceData = *(int**)((char*)this + 0x1C);
    if (!faceData)
        goto LABEL_ERROR_12;

    if (index >= faceData[1])
        goto LABEL_ERROR_12;

    int* base = (int*)*faceData;
    int stride = index * 64;

    *(int*)((char*)outFace + 8) = base[stride / 4 + 4];
    *(int*)((char*)outFace + 0x18) = base[stride / 4 + 6];
    *(int*)((char*)outFace + 0x10) = base[stride / 4 + 2];
    *(int*)((char*)outFace + 0x14) = base[stride / 4 + 3];
    *(int*)((char*)outFace + 0x1C) = base[stride / 4 + 5];

    unsigned short* wordPtr = (unsigned short*)((char*)base + stride + 6);
    *(unsigned short*)((char*)outFace + 0x20) = *wordPtr;

    unsigned char flagsByte = *((unsigned char*)base + stride + 4);
    if (flagsByte & 1) {
        if (flagsByte & 0x40) {
            *(unsigned short*)((char*)outFace + 0x22) = 0xFFFF;
        } else {
            *(unsigned short*)((char*)outFace + 0x22) = 1;
        }
    } else {
        *(unsigned short*)((char*)outFace + 0x22) = 0;
    }

    *(int*)((char*)outFace + 4) = index;
    *(int*)outFace = result;
    return 0;

LABEL_ERROR_12:
    sub_650190(0, 0x12, (void*)((char*)this + 8));
    return -1;
}
