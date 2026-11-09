// from server: 52% by colin
struct Lighting {
    char pad0[0xc];
    void* field_c;
    void* field_10;
    void* field_14;
    void* field_18;
    void* field_1c;
    void* field_20;
    void* field_24;
    void* field_28;
    void* field_2c;
    char pad30[0x18];
    void* field_48;
    char pad4c[0x1c];
    void* field_68;
    char pad6c[0x14];
    void* field_80;
    void* field_84;
    char pad88[0x10];
    void* field_98;
    char pad9c[0x8];
    void* field_a4;
    void* field_a8;
    void* field_ac;
    char padb0[0x23c];
    void* field_2ec;

    void destructor();
};

extern "C" {
    int __stdcall InterlockedDecrement(int*);
    void __cdecl operator_delete(void*);
    void __cdecl sub_4ff810(void*);
    void __cdecl sub_4f4d30(void*);
    void __cdecl sub_4f8b40(void*);
    void __cdecl sub_457dd0(void*);
}

void Lighting::destructor()
{
    if (field_2ec) {
        if (InterlockedDecrement((int*)((char*)field_2ec + 4)) == 0) {
            sub_457dd0(field_2ec);
            if (field_2ec) {
                (*(void(__thiscall**)(void*, int))*(void**)field_2ec)(field_2ec, 1);
            }
        }
        field_2ec = 0;
    }

    sub_4ff810(field_a4);
    field_a4 = 0;
    field_a8 = 0;
    field_ac = 0;

    sub_4f4d30((char*)this + 0x98);

    if (field_84) {
        if (InterlockedDecrement((int*)((char*)field_84 + 4)) == 0) {
            sub_457dd0(field_84);
            if (field_84) {
                (*(void(__thiscall**)(void*, int))*(void**)field_84)(field_84, 1);
            }
        }
        field_84 = 0;
    }

    if (field_80) {
        if (InterlockedDecrement((int*)((char*)field_80 + 4)) == 0) {
            sub_457dd0(field_80);
            if (field_80) {
                (*(void(__thiscall**)(void*, int))*(void**)field_80)(field_80, 1);
            }
        }
        field_80 = 0;
    }

    if (field_68) {
        if (InterlockedDecrement((int*)((char*)field_68 + 4)) == 0) {
            sub_457dd0(field_68);
            if (field_68) {
                (*(void(__thiscall**)(void*, int))*(void**)field_68)(field_68, 1);
            }
        }
        field_68 = 0;
    }

    if (field_48) {
        if (InterlockedDecrement((int*)((char*)field_48 + 4)) == 0) {
            sub_457dd0(field_48);
            if (field_48) {
                (*(void(__thiscall**)(void*, int))*(void**)field_48)(field_48, 1);
            }
        }
        field_48 = 0;
    }

    sub_4f4d30((char*)this + 0x3c);
    sub_4f8b40((char*)this + 0x30);

    sub_4ff810(field_24);
    field_24 = 0;
    field_28 = 0;
    field_2c = 0;

    sub_4ff810(field_18);
    field_18 = 0;
    field_1c = 0;
    field_20 = 0;

    sub_4ff810(field_c);
    field_c = 0;
    field_10 = 0;
    field_14 = 0;

    sub_4f8b40(this);
}
