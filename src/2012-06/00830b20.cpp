// from server: 40% by atomic.potato
struct S {
    void f(int);
};

extern "C" void* __stdcall sub_b22648(const char*);

void S::f(int a) {
    char buf[28];
    sub_b22648("HUVW");
    ((void(*)(S*,int,const char*))0x830330)(this, 0x5000402, "Sounds/grass.ogg");
    sub_b22648("Sounds/grass2.ogg");
    ((void(*)(S*,int,const char*))0x830330)(this, 0x4000300, "Sounds/grass3.ogg");
    sub_b22648("Sounds/grassstone.ogg");
    ((void(*)(S*,int,const char*))0x830330)(this, 0x4000301, "Sounds/grassstone2.ogg");
    sub_b22648("Sounds/grassstone3.ogg");
    ((void(*)(S*,int,const char*))0x830330)(this, 0x4000302, "Sounds/metalgrass3.ogg");
    sub_b22648("Sounds/metalstone.ogg");
    ((void(*)(S*,int,const char*))0x830330)(this, 0x5000500, "Sounds/metalstone2.ogg");
    sub_b22648("Sounds/metalstone3.ogg");
    ((void(*)(S*,int,const char*))0x830330)(this, 0x5000501, "Sounds/stone.ogg");
    sub_b22648("Sounds/stone.ogg");
    ((void(*)(S*,int,const char*))0x830330)(this, 0x5000502, "Sounds/stone.ogg");
    sub_b22648("Sounds/stone.ogg");
    ((void(*)(S*,int,const char*))0x830330)(this, 0x5000300, "Sounds/stone.ogg");
    sub_b22648("Sounds/stone.ogg");
    ((void(*)(S*,int,const char*))0x830330)(this, 0x5000301, "Sounds/stone.ogg");
    sub_b22648("Sounds/stone.ogg");
    ((void(*)(S*,int,const char*))0x830330)(this, 0x5000302, "Sounds/stone.ogg");
    sub_b22648("Sounds/stone.ogg");
    ((void(*)(S*,int,const char*))0x830330)(this, 0x3000300, "Sounds/stone.ogg");
    sub_b22648("Sounds/stone.ogg");
    ((void(*)(S*,int,const char*))0x830330)(this, 0x3000301, "Sounds/stone.ogg");
    sub_b22648("Sounds/stone.ogg");
    ((void(*)(S*,int,const char*))0x830330)(this, 0x3000302, "Sounds/stone.ogg");
}
