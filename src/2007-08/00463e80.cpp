// from server: 30% by colin
// roc 2007-08 00463e80  size: 452 bytes
// Reconstructed from disassembly evidence.

extern "C" {
    __declspec(dllimport) unsigned int __stdcall MapVirtualKeyExA(unsigned int uCode, unsigned int uMapType, unsigned int dwhkl);
    __declspec(dllimport) int __stdcall PostMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, int lParam);
}

extern unsigned int dword_8BC0C8;
extern unsigned int dword_77ED68;
extern unsigned int dword_77ECD0;

unsigned int sub_465CE0(unsigned int a);
void* sub_62FF02();

struct Listener {
    char pad_000[0x4c];
    void* field_4c;
    char pad_050[0x4];
    void* field_50;
    unsigned int field_54;
    char pad_058[0x13c];
    unsigned int field_194;
    void evaluate(unsigned int a, unsigned int b);
};

void Listener::evaluate(unsigned int a, unsigned int b)
{
    unsigned int hkl;
    unsigned int vk;
    unsigned int flags;
    unsigned int i;
    unsigned char* entry;
    unsigned char ch;
    unsigned int code;
    unsigned int mapped;

    hkl = dword_8BC0C8;
    vk = MapVirtualKeyExA(a, 1, hkl);
    if (vk == 0) {
        vk = sub_465CE0(a);
    }

    if (vk == 0x2c) {
        PostMessageA(*(void**)((char*)field_4c + 0x20), 0x111, 0x180fc, 0);
    } else if (vk == 0x70 || vk == 0x73) {
        mapped = MapVirtualKeyExA(a, 2, hkl);
        flags = 0;
        if ((b & 0x300) != 0) flags |= 0x10;
        if ((b & 0xc0) != 0) flags |= 8;
        if ((b & 3) != 0) flags |= 4;

        if (field_54 > 0) {
            entry = (unsigned char*)field_50;
            i = 0;
            do {
                ch = entry[0];
                code = *(unsigned short*)(entry + 2);
                if (ch & 1) {
                    if (code == vk) {
                        if ((flags & 0x1c) == (ch & 0x1c)) {
                            goto found;
                        }
                    }
                } else {
                    if (code == (unsigned int)(signed char)mapped) {
                        if ((flags & 0x1c) == (ch & 0x1c)) {
                            goto found;
                        }
                    }
                }
                i++;
                entry += 6;
            } while (i < field_54);
        }
        goto done;

found:
        {
            unsigned int idx = i + i * 2;
            unsigned int val = *(unsigned short*)((char*)field_50 + idx * 2 + 4);
            val |= 0x10000;
            PostMessageA(*(void**)((char*)field_4c + 0x20), 0x111, val, 0);
        }
    } else {
        void* p = sub_62FF02();
        unsigned char* q = *(unsigned char**)((char*)p + 4);
        q = *(unsigned char**)(q + 0x20);
        if (q[0xec] != 0) {
            goto done;
        }
    }

done:
    return;
}
