// from server: 100% by TrollStein
struct TimerService {
    char pad[0xe8];
    int field_e8;
};

extern "C" int __fastcall sub_6b8740(int);

int __cdecl sub_675d90(TimerService* self) {
    return sub_6b8740(self->field_e8);
}
