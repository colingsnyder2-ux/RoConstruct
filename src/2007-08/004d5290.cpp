// from server: 36% by colin
struct Part {
    static int getOrCreate(int);
};

extern "C" int __cdecl sub_500060(int, int);
extern "C" int __cdecl sub_500580(int, int, int);
extern "C" int __cdecl sub_62fef6(int);
extern "C" int __cdecl sub_630af7(int, int, int, int);
extern "C" int __cdecl sub_630bdc(int, int, int, int, int);
extern "C" int __cdecl sub_4d4300(int, int*, int*);
extern "C" int __cdecl sub_4d20e0(int);
extern "C" int __cdecl sub_4d0030(int, int);
extern "C" int __cdecl sub_4d00a0(int, int);
extern "C" int __cdecl sub_4d1ef0(int, int, int);
extern "C" int __cdecl sub_474f70(int, int);
extern "C" int __cdecl sub_4ea700(int, int, int);

extern int dword_896C30;
extern int dword_896C2C;
extern int dword_896C24;

int Part::getOrCreate(int id) {
    int hash = id % dword_896C30;
    int node = *(int*)(dword_896C2C + hash * 4);
    while (node != 0) {
        if (*(int*)node == id && *(int*)(node + 4) == id)
            goto found;
        node = *(int*)(node + 0x18);
    }

    {
        int buf[5];
        buf[0] = 0x79f058;
        buf[1] = 0;
        buf[2] = 0xa;
        buf[3] = 0;
        buf[4] = 0;
        int p = sub_500060(0x28, 0x10);
        sub_500580(p, 0, 0x28);
        buf[3] = p;
        sub_4d4300(0x896c24, &buf[4], &buf[0]);
        buf[0] = 0x79f058;
        sub_4d20e0((int)&buf[0]);
    }

found:
    {
        int hash2 = id % dword_896C30;
        int node2 = *(int*)(dword_896C2C + hash2 * 4);
        while (node2 != 0) {
            if (*(int*)node2 == id && *(int*)(node2 + 4) == id)
                break;
            node2 = *(int*)(node2 + 0x18);
        }
        int* slot = (int*)(node2 + 8);
        int arg = *(int*)((char*)&id + 0x24);
        if (!sub_4d0030((int)slot, arg)) {
            sub_630bdc((int)&id, 4, 1, 0x4cff40, 0x4637f0);
            sub_4d1ef0((int)slot, arg, (int)&id);
            sub_630af7((int)&id, 4, 1, 0x4637f0);
        }
        int* result = (int*)sub_4d00a0((int)slot, arg);
        if (*result == 0) {
            int obj = sub_62fef6(0x50);
            int created;
            if (obj != 0) {
                created = sub_4ea700(obj, arg, id);
            } else {
                created = 0;
            }
            sub_474f70((int)result, created);
            return created;
        }
        return *result;
    }
}
