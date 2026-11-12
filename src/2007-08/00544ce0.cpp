// from server: 100% by EspClaude
// from server: 52% by colin
// roc 2007-08 00544ce0  unit: RBX::VDebugSettings::?$GlobalSettingsItem  size: 198 bytes
// roc-flags: /O2 /GS- /EHsc /MD
// target (objdump of clients/2007-08/Roblox.exe):
//   544ce0:	6a ff                	push   0xffffffff
//   544ce2:	68 71 18 75 00       	push   0x751871
//   544ce7:	64 a1 00 00 00 00    	mov    eax,fs:0x0
//   544ced:	50                   	push   eax
//   544cee:	64 89 25 00 00 00 00 	mov    DWORD PTR fs:0x0,esp
//   544cf5:	83 ec 20             	sub    esp,0x20
//   544cf8:	56                   	push   esi
//   544cf9:	8b f1                	mov    esi,ecx
//   544cfb:	89 74 24 04          	mov    DWORD PTR [esp+0x4],esi
//   544cff:	e8 cc fe ff ff       	call   0x544bd0
//   544d04:	68 dc d0 79 00       	push   0x79d0dc
//   544d09:	8d 4c 24 0c          	lea    ecx,[esp+0xc]
//   544d0d:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
//   544d14:	00 
//   544d15:	c7 06 14 6d 7a 00    	mov    DWORD PTR [esi],0x7a6d14
//   544d1b:	c7 46 04 0c 6d 7a 00 	mov    DWORD PTR [esi+0x4],0x7a6d0c
//   544d22:	c7 46 10 04 6d 7a 00 	mov    DWORD PTR [esi+0x10],0x7a6d04
//   544d29:	c7 46 14 f4 6c 7a 00 	mov    DWORD PTR [esi+0x14],0x7a6cf4
//   544d30:	c7 46 2c e4 6c 7a 00 	mov    DWORD PTR [esi+0x2c],0x7a6ce4
//   544d37:	c7 46 44 d4 6c 7a 00 	mov    DWORD PTR [esi+0x44],0x7a6cd4
//   544d3e:	c7 46 5c c4 6c 7a 00 	mov    DWORD PTR [esi+0x5c],0x7a6cc4
//   544d45:	c7 46 74 b4 6c 7a 00 	mov    DWORD PTR [esi+0x74],0x7a6cb4
//   544d4c:	c7 86 8c 00 00 00 a4 	mov    DWORD PTR [esi+0x8c],0x7a6ca4
//   544d53:	6c 7a 00 
//   544d56:	c6 86 e8 00 00 00 01 	mov    BYTE PTR [esi+0xe8],0x1
//   544d5d:	c6 86 e9 00 00 00 00 	mov    BYTE PTR [esi+0xe9],0x0
//   544d64:	c7 86 ec 00 00 00 01 	mov    DWORD PTR [esi+0xec],0x1
//   544d6b:	00 00 00 
//   544d6e:	ff 15 98 e6 77 00    	call   DWORD PTR ds:0x77e698
//   544d74:	8d 44 24 08          	lea    eax,[esp+0x8]
//   544d78:	50                   	push   eax
//   544d79:	8b ce                	mov    ecx,esi
//   544d7b:	c6 44 24 30 01       	mov    BYTE PTR [esp+0x30],0x1
//   544d80:	e8 6b ce ff ff       	call   0x541bf0
//   544d85:	8d 4c 24 08          	lea    ecx,[esp+0x8]
//   544d89:	c6 44 24 2c 00       	mov    BYTE PTR [esp+0x2c],0x0
//   544d8e:	ff 15 ac e6 77 00    	call   DWORD PTR ds:0x77e6ac
//   544d94:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
//   544d98:	8b c6                	mov    eax,esi
//   544d9a:	5e                   	pop    esi
//   544d9b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
//   544da2:	83 c4 2c             	add    esp,0x2c
//   544da5:	c3                   	ret
#include <string>

// Polymorphic subobjects of the base: vptr stores at +0, +4, +0x10, +0x14,
// +0x2c, +0x44, +0x5c, +0x74, +0x8c; derived members start at +0xe8.
struct I0 { virtual void f0(); };                 // +0x00
struct I1 { virtual void f1(); int pad[2]; };     // +0x04
struct I2 { virtual void f2(); };                 // +0x10
struct I3 { virtual void f3(); int pad[5]; };     // +0x14
struct I4 { virtual void f4(); int pad[5]; };     // +0x2c
struct I5 { virtual void f5(); int pad[5]; };     // +0x44
struct I6 { virtual void f6(); int pad[5]; };     // +0x5c
struct I7 { virtual void f7(); int pad[5]; };     // +0x74
struct I8 { virtual void f8(); int pad[5]; };     // +0x8c

class GlobalSettings : public I0, public I1, public I2, public I3, public I4,
                       public I5, public I6, public I7, public I8
{
    int pad[(0xe8 - 0xa4) / 4];
public:
    GlobalSettings();                         // 0x544bd0
    virtual ~GlobalSettings();
    void setName(const std::string& name);    // 0x541bf0
};

class GlobalSettingsItem : public GlobalSettings
{
    bool flag0;     // +0xe8 = 1
    bool flag1;     // +0xe9 = 0
    int value;      // +0xec = 1
public:
    GlobalSettingsItem();
};

GlobalSettingsItem::GlobalSettingsItem()
    : flag0(true), flag1(false), value(1)
{
    setName("Diagnostics");
}
