// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 73% by tajop
// roc 2007-08 00563ca0  unit: RBX::GroupSelectionVerb  size: 229 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00563ca0
//
// 00563ca0  64a100000000         mov eax, dword ptr fs:[0]
// 00563ca6  6aff                 push -1
// 00563ca8  68a83f7500           push 0x753fa8
// 00563cad  50                   push eax
// 00563cae  64892500000000       mov dword ptr fs:[0], esp
// 00563cb5  83ec10               sub esp, 0x10
// 00563cb8  56                   push esi
// 00563cb9  8bf1                 mov esi, ecx
// 00563cbb  6a01                 push 1
// 00563cbd  8d4e14               lea ecx, [esi + 0x14]
// 00563cc0  e83be6ffff           call 0x562300
// 00563cc5  8b8004010000         mov eax, dword ptr [eax + 0x104]
// 00563ccb  8b4804               mov ecx, dword ptr [eax + 4]
// 00563cce  85c9                 test ecx, ecx
// 00563cd0  740a                 je 0x563cdc
// 00563cd2  8b4008               mov eax, dword ptr [eax + 8]
// 00563cd5  2bc1                 sub eax, ecx
// 00563cd7  c1f803               sar eax, 3
// 00563cda  7512                 jne 0x563cee
// 00563cdc  32c0                 xor al, al
// 00563cde  5e                   pop esi
// 00563cdf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00563ce3  64890d00000000       mov dword ptr fs:[0], ecx
// 00563cea  83c41c               add esp, 0x1c
// 00563ced  c3                   ret 
// 00563cee  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00563cf1  894c2408             mov dword ptr [esp + 8], ecx
// 00563cf5  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00563cfd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00563d05  6a01                 push 1
// 00563d07  8d4c240c             lea ecx, [esp + 0xc]
// 00563d0b  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00563d13  e8e8e5ffff           call 0x562300
// 00563d18  8b8004010000         mov eax, dword ptr [eax + 0x104]
// 00563d1e  8b4804               mov ecx, dword ptr [eax + 4]
// 00563d21  85c9                 test ecx, ecx
// 00563d23  7504                 jne 0x563d29
// 00563d25  33c0                 xor eax, eax
// 00563d27  eb08                 jmp 0x563d31
// 00563d29  8b4008               mov eax, dword ptr [eax + 8]
// 00563d2c  2bc1                 sub eax, ecx
// 00563d2e  c1f803               sar eax, 3
// 00563d31  8b742410             mov esi, dword ptr [esp + 0x10]
// 00563d35  83f801               cmp eax, 1
// 00563d38  53                   push ebx
// 00563d39  0f97c3               seta bl
// 00563d3c  85f6                 test esi, esi
// 00563d3e  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00563d46  742a                 je 0x563d72
// 00563d48  8d5604               lea edx, [esi + 4]
// 00563d4b  83c8ff               or eax, 0xffffffff
// 00563d4e  f00fc102             lock xadd dword ptr [edx], eax
// 00563d52  751e                 jne 0x563d72
// 00563d54  8b16                 mov edx, dword ptr [esi]
// 00563d56  8b4204               mov eax, dword ptr [edx + 4]
// 00563d59  8bce                 mov ecx, esi
// 00563d5b  ffd0                 call eax
// 00563d5d  8d4e08               lea ecx, [esi + 8]
// 00563d60  83caff               or edx, 0xffffffff
// 00563d63  f00fc111             lock xadd dword ptr [ecx], edx
// 00563d67  7509                 jne 0x563d72
// 00563d69  8b06                 mov eax, dword ptr [esi]
// 00563d6b  8b5008               mov edx, dword ptr [eax + 8]
// 00563d6e  8bce                 mov ecx, esi
// 00563d70  ffd2                 call edx
// 00563d72  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00563d76  8ac3                 mov al, bl
// 00563d78  5b                   pop ebx
// 00563d79  5e                   pop esi
// 00563d7a  64890d00000000       mov dword ptr fs:[0], ecx
// 00563d81  83c41c               add esp, 0x1c
// 00563d84  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct CountedBase
{
	virtual ~CountedBase();
	virtual void dispose();
	virtual void destroy();
	long use_count;
	long weak_count;

	void weak_release()
	{
		if (_InterlockedDecrement(&weak_count) == 0)
			destroy();
	}
	void release()
	{
		if (_InterlockedDecrement(&use_count) == 0)
		{
			dispose();
			weak_release();
		}
	}
};

struct SharedCount
{
	CountedBase* pi;
	SharedCount() : pi(0) {}
	~SharedCount()
	{
		CountedBase* p = *(CountedBase* volatile*)&pi;
		if (p != 0)
			p->release();
	}
};

struct Elem
{
	int a;
	int b;
};

struct Vec
{
	int alval;
	Elem* first;
	Elem* last;
	Elem* end;

	unsigned int size() const
	{
		return first == 0 ? 0 : (unsigned int)(last - first);
	}
};

struct Holder
{
	char pad[0x104];
	Vec* vec;
};

struct Getter
{
	void* dm;
	void* px;
	SharedCount pn;

	Getter(void* d) : dm(d), px(0) {}
	Holder* get(bool create);
};

struct GroupSelectionVerb
{
	char pad[0x14];
	mutable Getter getter;
	void* dataModel;

	bool isEnabled() const;
};

bool GroupSelectionVerb::isEnabled() const
{
	if (getter.get(true)->vec->size() == 0)
		return false;

	Getter local(dataModel);
	return local.get(true)->vec->size() > 1;
}
