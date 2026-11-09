// from server: 100% by sophus
struct S
{
	char pad0[0x10];
	void (__thiscall* field_10)(void*, int);
	int field_14;
	int field_18;
	char pad1[0x4];
	void* field_20;
	void f(int arg);
};

void S::f(int arg)
{
	int offset = *(int*)(*(char**)((char*)field_20 + 0x94) + field_18) + field_14;
	void (__thiscall* fn)(void*, int) = field_10;
	fn((char*)field_20 + 0x94 + offset, arg);
}
