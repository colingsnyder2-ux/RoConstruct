// from server: 100% by Intel
// from server: 97% by EspClaude
// roc 2007-08 00420c40  unit: CRobloxTreeCtrl  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00420c40
//
// 00420c40  83ec18               sub esp, 0x18
// 00420c43  53                   push ebx
// 00420c44  56                   push esi
// 00420c45  57                   push edi
// 00420c46  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00420c4a  8b473c               mov eax, dword ptr [edi + 0x3c]
// 00420c4d  50                   push eax
// 00420c4e  8bf1                 mov esi, ecx
// 00420c50  e853f82000           call 0x6304a8
// 00420c55  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00420c5b  8bd8                 mov ebx, eax
// 00420c5d  3bd9                 cmp ebx, ecx
// 00420c5f  740d                 je 0x420c6e
// 00420c61  85c9                 test ecx, ecx
// 00420c63  7409                 je 0x420c6e
// 00420c65  8b11                 mov edx, dword ptr [ecx]
// 00420c67  8b4204               mov eax, dword ptr [edx + 4]
// 00420c6a  6a01                 push 1
// 00420c6c  ffd0                 call eax
// 00420c6e  85db                 test ebx, ebx
// 00420c70  899eec000000         mov dword ptr [esi + 0xec], ebx
// 00420c76  0f84ad000000         je 0x420d29
// 00420c7c  8b573c               mov edx, dword ptr [edi + 0x3c]
// 00420c7f  6a01                 push 1
// 00420c81  8d4c2418             lea ecx, [esp + 0x18]
// 00420c85  51                   push ecx
// 00420c86  52                   push edx
// 00420c87  8bce                 mov ecx, esi
// 00420c89  e8f0f72000           call 0x63047e
// 00420c8e  8b4620               mov eax, dword ptr [esi + 0x20]
// 00420c91  6a00                 push 0
// 00420c93  6a00                 push 0
// 00420c95  6806110000           push 0x1106
// 00420c9a  50                   push eax
// 00420c9b  ff15d8ec7700         call dword ptr [0x77ecd8]
// 00420ca1  8b4f60               mov ecx, dword ptr [edi + 0x60]
// 00420ca4  8b5764               mov edx, dword ptr [edi + 0x64]
// 00420ca7  894c240c             mov dword ptr [esp + 0xc], ecx
// 00420cab  2b4c2414             sub ecx, dword ptr [esp + 0x14]
// 00420caf  89542410             mov dword ptr [esp + 0x10], edx
// 00420cb3  2b542418             sub edx, dword ptr [esp + 0x18]
// 00420cb7  03c1                 add eax, ecx
// 00420cb9  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00420cbf  8b4904               mov ecx, dword ptr [ecx + 4]
// 00420cc2  52                   push edx
// 00420cc3  50                   push eax
// 00420cc4  6a00                 push 0
// 00420cc6  51                   push ecx
// 00420cc7  e836f22000           call 0x62ff02
// 00420ccc  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 00420cd2  8b0a                 mov ecx, dword ptr [edx]
// 00420cd4  e8f7e2ffff           call 0x41efd0
// 00420cd9  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00420cdc  8d44240c             lea eax, [esp + 0xc]
// 00420ce0  50                   push eax
// 00420ce1  51                   push ecx
// 00420ce2  ff15f0ed7700         call dword ptr [0x77edf0]
// 00420ce8  8b542410             mov edx, dword ptr [esp + 0x10]
// 00420cec  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00420cf0  52                   push edx
// 00420cf1  50                   push eax
// 00420cf2  6a00                 push 0
// 00420cf4  e809f22000           call 0x62ff02
// 00420cf9  8b8894000000         mov ecx, dword ptr [eax + 0x94]
// 00420cff  8b09                 mov ecx, dword ptr [ecx]
// 00420d01  e8eae4ffff           call 0x41f1f0
// 00420d06  8b5620               mov edx, dword ptr [esi + 0x20]
// 00420d09  52                   push edx
// 00420d0a  ff1548ec7700         call dword ptr [0x77ec48]
// 00420d10  50                   push eax
// 00420d11  e8aaf42000           call 0x6301c0
// 00420d16  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00420d1a  5f                   pop edi
// 00420d1b  5e                   pop esi
// 00420d1c  c70000000000         mov dword ptr [eax], 0
// 00420d22  5b                   pop ebx
// 00420d23  83c418               add esp, 0x18
// 00420d26  c20800               ret 8
// 00420d29  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00420d2d  5f                   pop edi
// 00420d2e  5e                   pop esi
// 00420d2f  c70100000000         mov dword ptr [ecx], 0
// 00420d35  5b                   pop ebx
// 00420d36  83c418               add esp, 0x18
// 00420d39  c20800               ret 8

// from server: 100% by user
// roc 2008-06 004233d0  unit: CRobloxTreeCtrl  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004233d0
//
// 004233d0  83ec18               sub esp, 0x18
// 004233d3  53                   push ebx
// 004233d4  56                   push esi
// 004233d5  57                   push edi
// 004233d6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004233da  8b473c               mov eax, dword ptr [edi + 0x3c]
// 004233dd  50                   push eax
// 004233de  8bf1                 mov esi, ecx
// 004233e0  e86bdb2700           call 0x6a0f50
// 004233e5  8b8e2c010000         mov ecx, dword ptr [esi + 0x12c]
// 004233eb  8bd8                 mov ebx, eax
// 004233ed  3bd9                 cmp ebx, ecx
// 004233ef  740d                 je 0x4233fe
// 004233f1  85c9                 test ecx, ecx
// 004233f3  7409                 je 0x4233fe
// 004233f5  8b11                 mov edx, dword ptr [ecx]
// 004233f7  8b4204               mov eax, dword ptr [edx + 4]
// 004233fa  6a01                 push 1
// 004233fc  ffd0                 call eax
// 004233fe  899e2c010000         mov dword ptr [esi + 0x12c], ebx
// 00423404  85db                 test ebx, ebx
// 00423406  0f84ad000000         je 0x4234b9
// 0042340c  8b573c               mov edx, dword ptr [edi + 0x3c]
// 0042340f  6a01                 push 1
// 00423411  8d4c2418             lea ecx, [esp + 0x18]
// 00423415  51                   push ecx
// 00423416  52                   push edx
// 00423417  8bce                 mov ecx, esi
// 00423419  e814db2700           call 0x6a0f32
// 0042341e  8b4620               mov eax, dword ptr [esi + 0x20]
// 00423421  6a00                 push 0
// 00423423  6a00                 push 0
// 00423425  6806110000           push 0x1106
// 0042342a  50                   push eax
// 0042342b  ff15142e8000         call dword ptr [0x802e14]
// 00423431  8b4f60               mov ecx, dword ptr [edi + 0x60]
// 00423434  8b5764               mov edx, dword ptr [edi + 0x64]
// 00423437  894c240c             mov dword ptr [esp + 0xc], ecx
// 0042343b  2b4c2414             sub ecx, dword ptr [esp + 0x14]
// 0042343f  89542410             mov dword ptr [esp + 0x10], edx
// 00423443  2b542418             sub edx, dword ptr [esp + 0x18]
// 00423447  03c1                 add eax, ecx
// 00423449  8b8e2c010000         mov ecx, dword ptr [esi + 0x12c]
// 0042344f  8b4904               mov ecx, dword ptr [ecx + 4]
// 00423452  52                   push edx
// 00423453  50                   push eax
// 00423454  6a00                 push 0
// 00423456  51                   push ecx
// 00423457  e8cad42700           call 0x6a0926
// 0042345c  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 00423462  8b0a                 mov ecx, dword ptr [edx]
// 00423464  e897eaffff           call 0x421f00
// 00423469  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0042346c  8d44240c             lea eax, [esp + 0xc]
// 00423470  50                   push eax
// 00423471  51                   push ecx
// 00423472  ff15802d8000         call dword ptr [0x802d80]
// 00423478  8b542410             mov edx, dword ptr [esp + 0x10]
// 0042347c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00423480  52                   push edx
// 00423481  50                   push eax
// 00423482  6a00                 push 0
// 00423484  e89dd42700           call 0x6a0926
// 00423489  8b8894000000         mov ecx, dword ptr [eax + 0x94]
// 0042348f  8b09                 mov ecx, dword ptr [ecx]
// 00423491  e86aecffff           call 0x422100
// 00423496  8b5620               mov edx, dword ptr [esi + 0x20]
// 00423499  52                   push edx
// 0042349a  ff15a82d8000         call dword ptr [0x802da8]
// 004234a0  50                   push eax
// 004234a1  e838d72700           call 0x6a0bde
// 004234a6  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004234aa  5f                   pop edi
// 004234ab  5e                   pop esi
// 004234ac  c70000000000         mov dword ptr [eax], 0
// 004234b2  5b                   pop ebx
// 004234b3  83c418               add esp, 0x18
// 004234b6  c20800               ret 8
// 004234b9  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004234bd  5f                   pop edi
// 004234be  5e                   pop esi
// 004234bf  c70100000000         mov dword ptr [ecx], 0
// 004234c5  5b                   pop ebx
// 004234c6  83c418               add esp, 0x18
// 004234c9  c20800               ret 8

// from server: 98% by colin
// roc 2008-06 004233d0  unit: CRobloxTreeCtrl  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004233d0
//
// 004233d0  83ec18               sub esp, 0x18
// 004233d3  53                   push ebx
// 004233d4  56                   push esi
// 004233d5  57                   push edi
// 004233d6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004233da  8b473c               mov eax, dword ptr [edi + 0x3c]
// 004233dd  50                   push eax
// 004233de  8bf1                 mov esi, ecx
// 004233e0  e86bdb2700           call 0x6a0f50
// 004233e5  8b8e2c010000         mov ecx, dword ptr [esi + 0x12c]
// 004233eb  8bd8                 mov ebx, eax
// 004233ed  3bd9                 cmp ebx, ecx
// 004233ef  740d                 je 0x4233fe
// 004233f1  85c9                 test ecx, ecx
// 004233f3  7409                 je 0x4233fe
// 004233f5  8b11                 mov edx, dword ptr [ecx]
// 004233f7  8b4204               mov eax, dword ptr [edx + 4]
// 004233fa  6a01                 push 1
// 004233fc  ffd0                 call eax
// 004233fe  899e2c010000         mov dword ptr [esi + 0x12c], ebx
// 00423404  85db                 test ebx, ebx
// 00423406  0f84ad000000         je 0x4234b9
// 0042340c  8b573c               mov edx, dword ptr [edi + 0x3c]
// 0042340f  6a01                 push 1
// 00423411  8d4c2418             lea ecx, [esp + 0x18]
// 00423415  51                   push ecx
// 00423416  52                   push edx
// 00423417  8bce                 mov ecx, esi
// 00423419  e814db2700           call 0x6a0f32
// 0042341e  8b4620               mov eax, dword ptr [esi + 0x20]
// 00423421  6a00                 push 0
// 00423423  6a00                 push 0
// 00423425  6806110000           push 0x1106
// 0042342a  50                   push eax
// 0042342b  ff15142e8000         call dword ptr [0x802e14]
// 00423431  8b4f60               mov ecx, dword ptr [edi + 0x60]
// 00423434  8b5764               mov edx, dword ptr [edi + 0x64]
// 00423437  894c240c             mov dword ptr [esp + 0xc], ecx
// 0042343b  2b4c2414             sub ecx, dword ptr [esp + 0x14]
// 0042343f  89542410             mov dword ptr [esp + 0x10], edx
// 00423443  2b542418             sub edx, dword ptr [esp + 0x18]
// 00423447  03c1                 add eax, ecx
// 00423449  8b8e2c010000         mov ecx, dword ptr [esi + 0x12c]
// 0042344f  8b4904               mov ecx, dword ptr [ecx + 4]
// 00423452  52                   push edx
// 00423453  50                   push eax
// 00423454  6a00                 push 0
// 00423456  51                   push ecx
// 00423457  e8cad42700           call 0x6a0926
// 0042345c  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 00423462  8b0a                 mov ecx, dword ptr [edx]
// 00423464  e897eaffff           call 0x421f00
// 00423469  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0042346c  8d44240c             lea eax, [esp + 0xc]
// 00423470  50                   push eax
// 00423471  51                   push ecx
// 00423472  ff15802d8000         call dword ptr [0x802d80]
// 00423478  8b542410             mov edx, dword ptr [esp + 0x10]
// 0042347c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00423480  52                   push edx
// 00423481  50                   push eax
// 00423482  6a00                 push 0
// 00423484  e89dd42700           call 0x6a0926
// 00423489  8b8894000000         mov ecx, dword ptr [eax + 0x94]
// 0042348f  8b09                 mov ecx, dword ptr [ecx]
// 00423491  e86aecffff           call 0x422100
// 00423496  8b5620               mov edx, dword ptr [esi + 0x20]
// 00423499  52                   push edx
// 0042349a  ff15a82d8000         call dword ptr [0x802da8]
// 004234a0  50                   push eax
// 004234a1  e838d72700           call 0x6a0bde
// 004234a6  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004234aa  5f                   pop edi
// 004234ab  5e                   pop esi
// 004234ac  c70000000000         mov dword ptr [eax], 0
// 004234b2  5b                   pop ebx
// 004234b3  83c418               add esp, 0x18
// 004234b6  c20800               ret 8
// 004234b9  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004234bd  5f                   pop edi
// 004234be  5e                   pop esi
// 004234bf  c70100000000         mov dword ptr [ecx], 0
// 004234c5  5b                   pop ebx
// 004234c6  83c418               add esp, 0x18
// 004234c9  c20800               ret 8

// from server: 72% by king_originala
// roc 2008-06 004233d0  unit: CRobloxTreeCtrl  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004233d0
//
// 004233d0  83ec18               sub esp, 0x18
// 004233d3  53                   push ebx
// 004233d4  56                   push esi
// 004233d5  57                   push edi
// 004233d6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004233da  8b473c               mov eax, dword ptr [edi + 0x3c]
// 004233dd  50                   push eax
// 004233de  8bf1                 mov esi, ecx
// 004233e0  e86bdb2700           call 0x6a0f50
// 004233e5  8b8e2c010000         mov ecx, dword ptr [esi + 0x12c]
// 004233eb  8bd8                 mov ebx, eax
// 004233ed  3bd9                 cmp ebx, ecx
// 004233ef  740d                 je 0x4233fe
// 004233f1  85c9                 test ecx, ecx
// 004233f3  7409                 je 0x4233fe
// 004233f5  8b11                 mov edx, dword ptr [ecx]
// 004233f7  8b4204               mov eax, dword ptr [edx + 4]
// 004233fa  6a01                 push 1
// 004233fc  ffd0                 call eax
// 004233fe  899e2c010000         mov dword ptr [esi + 0x12c], ebx
// 00423404  85db                 test ebx, ebx
// 00423406  0f84ad000000         je 0x4234b9
// 0042340c  8b573c               mov edx, dword ptr [edi + 0x3c]
// 0042340f  6a01                 push 1
// 00423411  8d4c2418             lea ecx, [esp + 0x18]
// 00423415  51                   push ecx
// 00423416  52                   push edx
// 00423417  8bce                 mov ecx, esi
// 00423419  e814db2700           call 0x6a0f32
// 0042341e  8b4620               mov eax, dword ptr [esi + 0x20]
// 00423421  6a00                 push 0
// 00423423  6a00                 push 0
// 00423425  6806110000           push 0x1106
// 0042342a  50                   push eax
// 0042342b  ff15142e8000         call dword ptr [0x802e14]
// 00423431  8b4f60               mov ecx, dword ptr [edi + 0x60]
// 00423434  8b5764               mov edx, dword ptr [edi + 0x64]
// 00423437  894c240c             mov dword ptr [esp + 0xc], ecx
// 0042343b  2b4c2414             sub ecx, dword ptr [esp + 0x14]
// 0042343f  89542410             mov dword ptr [esp + 0x10], edx
// 00423443  2b542418             sub edx, dword ptr [esp + 0x18]
// 00423447  03c1                 add eax, ecx
// 00423449  8b8e2c010000         mov ecx, dword ptr [esi + 0x12c]
// 0042344f  8b4904               mov ecx, dword ptr [ecx + 4]
// 00423452  52                   push edx
// 00423453  50                   push eax
// 00423454  6a00                 push 0
// 00423456  51                   push ecx
// 00423457  e8cad42700           call 0x6a0926
// 0042345c  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 00423462  8b0a                 mov ecx, dword ptr [edx]
// 00423464  e897eaffff           call 0x421f00
// 00423469  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0042346c  8d44240c             lea eax, [esp + 0xc]
// 00423470  50                   push eax
// 00423471  51                   push ecx
// 00423472  ff15802d8000         call dword ptr [0x802d80]
// 00423478  8b542410             mov edx, dword ptr [esp + 0x10]
// 0042347c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00423480  52                   push edx
// 00423481  50                   push eax
// 00423482  6a00                 push 0
// 00423484  e89dd42700           call 0x6a0926
// 00423489  8b8894000000         mov ecx, dword ptr [eax + 0x94]
// 0042348f  8b09                 mov ecx, dword ptr [ecx]
// 00423491  e86aecffff           call 0x422100
// 00423496  8b5620               mov edx, dword ptr [esi + 0x20]
// 00423499  52                   push edx
// 0042349a  ff15a82d8000         call dword ptr [0x802da8]
// 004234a0  50                   push eax
// 004234a1  e838d72700           call 0x6a0bde
// 004234a6  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004234aa  5f                   pop edi
// 004234ab  5e                   pop esi
// 004234ac  c70000000000         mov dword ptr [eax], 0
// 004234b2  5b                   pop ebx
// 004234b3  83c418               add esp, 0x18
// 004234b6  c20800               ret 8
// 004234b9  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004234bd  5f                   pop edi
// 004234be  5e                   pop esi
// 004234bf  c70100000000         mov dword ptr [ecx], 0
// 004234c5  5b                   pop ebx
// 004234c6  83c418               add esp, 0x18
// 004234c9  c20800               ret 8

struct Point {
    int x, y;
};

struct Rect {
    int left, top, right, bottom;
};

struct Item {
    virtual void unused();
    virtual void release(int);
    void* handle;
};

struct Handler {
    void begin();
    void position();
};

struct Result {
    char padding[0x94];
    Handler** handler;
};

struct Notification {
    char padding0[0x3c];
    void* item;
    char padding1[0x20];
    Point point;
};

extern "C" {
    extern int (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, int);
    extern int (__stdcall *ClientToScreen)(void*, Point*);
    extern void* (__stdcall *SetCapture)(void*);
    Result* __stdcall locateWithHandle(void*, int, int, int);
    Result* __stdcall locate(int, int, int);
    void __stdcall capture(void*);
}

struct CRobloxTreeCtrl {
    char padding0[0x20];
    void* window;
    char padding1[0xC8];
    Item* current;

    Item* findItem(void*);
    int getItemRect(void*, Rect*, int);
    void notify(Notification*, int*);
};

void CRobloxTreeCtrl::notify(Notification* notification, int* result)
{
    Item* item = findItem(notification->item);
    if (item != current && current)
        current->release(1);
    current = item;

    if (item) {
        Rect rectangle;
        getItemRect(notification->item, &rectangle, 1);

        void* windowCopy = window;
        int scroll = SendMessageA(windowCopy, 0x1106, 0, 0);
        Point point = notification->point;

        scroll += point.x - rectangle.left;
        void* handle = current->handle;
        Result* first = locateWithHandle(
            handle, 0,
            scroll,
            point.y - rectangle.top);
        (*first->handler)->begin();

        ClientToScreen(window, &point);
        Result* second = locate(0, point.x, point.y);
        (*second->handler)->position();

        capture(SetCapture(window));
        *result = 0;
    } else {
        *result = 0;
    }
}
