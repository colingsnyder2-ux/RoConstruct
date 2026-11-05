// from server: 100% by colin
struct JointInstance {
    char pad[0x100];
    JointInstance* construct(void*);
};

JointInstance* JointInstance::construct(void* a)
{
    JointInstance* self = this;
    self->construct(a);
    *(int*)((char*)self + 0x00) = 0x7b6c64;
    *(int*)((char*)self + 0x04) = 0x7b6c5c;
    *(int*)((char*)self + 0x10) = 0x7b6c54;
    *(int*)((char*)self + 0x14) = 0x7b6c44;
    *(int*)((char*)self + 0x2c) = 0x7b6c34;
    *(int*)((char*)self + 0x44) = 0x7b6c24;
    *(int*)((char*)self + 0x5c) = 0x7b6c14;
    *(int*)((char*)self + 0x74) = 0x7b6c04;
    *(int*)((char*)self + 0x8c) = 0x7b6bf4;
    *(int*)((char*)self + 0xe8) = 0x7b6bdc;
    return self;
}
