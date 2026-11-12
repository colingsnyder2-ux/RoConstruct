// from server: 96% by EspClaude
// from server: 48% by colin
// roc 2007-08 004370f0  unit: RBX::VStandardOut::?$Listener  size: 689 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004370f0
//
// 004370f0  33c0                 xor eax, eax
// 004370f2  83ec08               sub esp, 8
// 004370f5  3944240c             cmp dword ptr [esp + 0xc], eax
// 004370f9  750a                 jne 0x437105
// 004370fb  6805400080           push 0x80004005
// 00437100  e8fb9efcff           call 0x401000
// 00437105  39442410             cmp dword ptr [esp + 0x10], eax
// 00437109  53                   push ebx
// 0043710a  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0043710e  56                   push esi
// 0043710f  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00437113  89442408             mov dword ptr [esp + 8], eax
// 00437117  8944240c             mov dword ptr [esp + 0xc], eax
// 0043711b  0f8436020000         je 0x437357
// 00437121  55                   push ebp
// 00437122  57                   push edi
// 00437123  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00437127  0fb700               movzx eax, word ptr [eax]
// 0043712a  836c242001           sub dword ptr [esp + 0x20], 1
// 0043712f  0fb7d0               movzx edx, ax
// 00437132  8d4ade               lea ecx, [edx - 0x22]
// 00437135  33ed                 xor ebp, ebp
// 00437137  33ff                 xor edi, edi
// 00437139  83f91c               cmp ecx, 0x1c
// 0043713c  0f87ca000000         ja 0x43720c
// 00437142  0fb68984734300       movzx ecx, byte ptr [ecx + 0x437384]
// 00437149  ff248d74734300       jmp dword ptr [ecx*4 + 0x437374]
// 00437150  85f6                 test esi, esi
// 00437152  7439                 je 0x43718d
// 00437154  83fb03               cmp ebx, 3
// 00437157  7e34                 jle 0x43718d
// 00437159  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0043715d  66c7062600           mov word ptr [esi], 0x26
// 00437162  668b02               mov ax, word ptr [edx]
// 00437165  662d3c00             sub ax, 0x3c
// 00437169  83c602               add esi, 2
// 0043716c  66f7d8               neg ax
// 0043716f  1bc0                 sbb eax, eax
// 00437171  83e0fb               and eax, 0xfffffffb
// 00437174  83c06c               add eax, 0x6c
// 00437177  668906               mov word ptr [esi], ax
// 0043717a  83c602               add esi, 2
// 0043717d  66c7067400           mov word ptr [esi], 0x74
// 00437182  83c602               add esi, 2
// 00437185  66c7063b00           mov word ptr [esi], 0x3b
// 0043718a  83c602               add esi, 2
// 0043718d  bf04000000           mov edi, 4
// 00437192  e966010000           jmp 0x4372fd
// 00437197  85f6                 test esi, esi
// 00437199  7423                 je 0x4371be
// 0043719b  83fb04               cmp ebx, 4
// 0043719e  7e1e                 jle 0x4371be
// 004371a0  6a0a                 push 0xa
// 004371a2  68e4cd7800           push 0x78cde4
// 004371a7  8d0c1b               lea ecx, [ebx + ebx]
// 004371aa  51                   push ecx
// 004371ab  56                   push esi
// 004371ac  ff15d4e67700         call dword ptr [0x77e6d4]
// 004371b2  50                   push eax
// 004371b3  e828a5fcff           call 0x4016e0
// 004371b8  83c414               add esp, 0x14
// 004371bb  83c60a               add esi, 0xa
// 004371be  bf05000000           mov edi, 5
// 004371c3  e935010000           jmp 0x4372fd
// 004371c8  f644242c01           test byte ptr [esp + 0x2c], 1
// 004371cd  743d                 je 0x43720c
// 004371cf  85f6                 test esi, esi
// 004371d1  742f                 je 0x437202
// 004371d3  83fb05               cmp ebx, 5
// 004371d6  7e2a                 jle 0x437202
// 004371d8  663d2700             cmp ax, 0x27
// 004371dc  b8d4cd7800           mov eax, 0x78cdd4
// 004371e1  7405                 je 0x4371e8
// 004371e3  b8c4cd7800           mov eax, 0x78cdc4
// 004371e8  6a0c                 push 0xc
// 004371ea  50                   push eax
// 004371eb  8d141b               lea edx, [ebx + ebx]
// 004371ee  52                   push edx
// 004371ef  56                   push esi
// 004371f0  ff15d4e67700         call dword ptr [0x77e6d4]
// 004371f6  50                   push eax
// 004371f7  e8e4a4fcff           call 0x4016e0
// 004371fc  83c414               add esp, 0x14
// 004371ff  83c60c               add esi, 0xc
// 00437202  bf06000000           mov edi, 6
// 00437207  e9f1000000           jmp 0x4372fd
// 0043720c  663d00d8             cmp ax, 0xd800
// 00437210  723a                 jb 0x43724c
// 00437212  663dffdb             cmp ax, 0xdbff
// 00437216  7734                 ja 0x43724c
// 00437218  8b442414             mov eax, dword ptr [esp + 0x14]
// 0043721c  6685c0               test ax, ax
// 0043721f  741b                 je 0x43723c
// 00437221  85f6                 test esi, esi
// 00437223  7412                 je 0x437237
// 00437225  83fb07               cmp ebx, 7
// 00437228  7e0d                 jle 0x437237
// 0043722a  56                   push esi
// 0043722b  50                   push eax
// 0043722c  e8fffdffff           call 0x437030
// 00437231  83c408               add esp, 8
// 00437234  83c610               add esi, 0x10
// 00437237  bf08000000           mov edi, 8
// 0043723c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00437240  0fb708               movzx ecx, word ptr [eax]
// 00437243  894c2414             mov dword ptr [esp + 0x14], ecx
// 00437247  e9b1000000           jmp 0x4372fd
// 0043724c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00437250  6685c9               test cx, cx
// 00437253  7465                 je 0x4372ba
// 00437255  663d00dc             cmp ax, 0xdc00
// 00437259  7235                 jb 0x437290
// 0043725b  663dffdf             cmp ax, 0xdfff
// 0043725f  772f                 ja 0x437290
// 00437261  85f6                 test esi, esi
// 00437263  741f                 je 0x437284
// 00437265  83fb09               cmp ebx, 9
// 00437268  7e1a                 jle 0x437284
// 0043726a  0fb7c1               movzx eax, cx
// 0043726d  2df7d70000           sub eax, 0xd7f7
// 00437272  c1e00a               shl eax, 0xa
// 00437275  03c2                 add eax, edx
// 00437277  56                   push esi
// 00437278  50                   push eax
// 00437279  e812feffff           call 0x437090
// 0043727e  83c408               add esp, 8
// 00437281  83c614               add esi, 0x14
// 00437284  bf0a000000           mov edi, 0xa
// 00437289  bd01000000           mov ebp, 1
// 0043728e  eb1e                 jmp 0x4372ae
// 00437290  85f6                 test esi, esi
// 00437292  7412                 je 0x4372a6
// 00437294  83fb07               cmp ebx, 7
// 00437297  7e0d                 jle 0x4372a6
// 00437299  56                   push esi
// 0043729a  51                   push ecx
// 0043729b  e890fdffff           call 0x437030
// 004372a0  83c408               add esp, 8
// 004372a3  83c610               add esi, 0x10
// 004372a6  83eb08               sub ebx, 8
// 004372a9  8344241008           add dword ptr [esp + 0x10], 8
// 004372ae  85ed                 test ebp, ebp
// 004372b0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004372b8  7543                 jne 0x4372fd
// 004372ba  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004372be  0fb701               movzx eax, word ptr [ecx]
// 004372c1  663d2000             cmp ax, 0x20
// 004372c5  721b                 jb 0x4372e2
// 004372c7  663d7e00             cmp ax, 0x7e
// 004372cb  7715                 ja 0x4372e2
// 004372cd  85f6                 test esi, esi
// 004372cf  740a                 je 0x4372db
// 004372d1  85db                 test ebx, ebx
// 004372d3  7e06                 jle 0x4372db
// 004372d5  668906               mov word ptr [esi], ax
// 004372d8  83c602               add esi, 2
// 004372db  bf01000000           mov edi, 1
// 004372e0  eb1b                 jmp 0x4372fd
// 004372e2  85f6                 test esi, esi
// 004372e4  7412                 je 0x4372f8
// 004372e6  83fb07               cmp ebx, 7
// 004372e9  7e0d                 jle 0x4372f8
// 004372eb  56                   push esi
// 004372ec  50                   push eax
// 004372ed  e83efdffff           call 0x437030
// 004372f2  83c408               add esp, 8
// 004372f5  83c610               add esi, 0x10
// 004372f8  bf08000000           mov edi, 8
// 004372fd  017c2410             add dword ptr [esp + 0x10], edi
// 00437301  8344241c02           add dword ptr [esp + 0x1c], 2
// 00437306  2bdf                 sub ebx, edi
// 00437308  837c242000           cmp dword ptr [esp + 0x20], 0
// 0043730d  0f8510feffff         jne 0x437123
// 00437313  8b442414             mov eax, dword ptr [esp + 0x14]
// 00437317  6685c0               test ax, ax
// 0043731a  5f                   pop edi
// 0043731b  5d                   pop ebp
// 0043731c  7439                 je 0x437357
// 0043731e  8d50e0               lea edx, [eax - 0x20]
// 00437321  6683fa5e             cmp dx, 0x5e
// 00437325  7715                 ja 0x43733c
// 00437327  85f6                 test esi, esi
// 00437329  7407                 je 0x437332
// 0043732b  85db                 test ebx, ebx
// 0043732d  7e03                 jle 0x437332
// 0043732f  668906               mov word ptr [esi], ax
// 00437332  83eb01               sub ebx, 1
// 00437335  8344240801           add dword ptr [esp + 8], 1
// 0043733a  eb1b                 jmp 0x437357
// 0043733c  85f6                 test esi, esi
// 0043733e  740f                 je 0x43734f
// 00437340  83fb07               cmp ebx, 7
// 00437343  7e0a                 jle 0x43734f
// 00437345  56                   push esi
// 00437346  50                   push eax
// 00437347  e8e4fcffff           call 0x437030
// 0043734c  83c408               add esp, 8
// 0043734f  83eb08               sub ebx, 8
// 00437352  8344240808           add dword ptr [esp + 8], 8
// 00437357  85f6                 test esi, esi
// 00437359  740c                 je 0x437367
// 0043735b  85db                 test ebx, ebx
// 0043735d  7d08                 jge 0x437367
// 0043735f  5e                   pop esi
// 00437360  33c0                 xor eax, eax
// 00437362  5b                   pop ebx
// 00437363  83c408               add esp, 8
// 00437366  c3                   ret 
// 00437367  8b442408             mov eax, dword ptr [esp + 8]
// 0043736b  5e                   pop esi
// 0043736c  5b                   pop ebx
// 0043736d  83c408               add esp, 8
// 00437370  c3                   ret 
// 00437371  8d4900               lea ecx, [ecx]
// 00437374  c8714300             enter 0x4371, 0
// 00437378  97                   xchg edi, eax
// 00437379  7143                 jno 0x4373be
// 0043737b  005071               add byte ptr [eax + 0x71], dl
// 0043737e  43                   inc ebx
// 0043737f  000c72               add byte ptr [edx + esi*2], cl

// Codegen analog of ATL 8.0 atlenc.h EscapeXML (wide-char version).
#include <string.h>

typedef unsigned long DWORD;
typedef int BOOL;
typedef long HRESULT;

namespace ATL {

__declspec(noreturn) void __stdcall AtlThrowImpl(HRESULT hr);
errno_t AtlCrtErrorCheck(errno_t nError);
int _AtlCopyNCR(wchar_t wch, wchar_t *wszEsc) throw();
int _AtlCopyNCRPair(DWORD dw, wchar_t *wszEsc) throw();

namespace Checked {
inline void __cdecl memcpy_s(void *_S1, size_t _S1max, const void *_S2, size_t _N)
{
    AtlCrtErrorCheck(::memcpy_s(_S1, _S1max, _S2, _N));
}
}

#define ATL_ESC_FLAG_ATTR 1
#define ATL_HIGH_SURROGATE_START  0xd800
#define ATL_HIGH_SURROGATE_END    0xdbff
#define ATL_LOW_SURROGATE_START   0xdc00
#define ATL_LOW_SURROGATE_END     0xdfff

int EscapeXML(const wchar_t *szIn, int nSrcLen, wchar_t *szEsc, int nDestLen, DWORD dwFlags)
{
	if (!(szIn != 0)) AtlThrowImpl((HRESULT)0x80004005L);

	int nCnt(0);
	int nCurrLen(nDestLen);
	int nInc(0);
	wchar_t wchHighSurrogate = 0;
	BOOL bHandled;

	while (nSrcLen--)
	{
		bHandled = 0;
		nInc = 0;
		switch (*szIn)
		{
		case L'<': case L'>':
			if ((szEsc != 0) && (3 < nCurrLen))
			{
				*szEsc++ = L'&';
				*szEsc++ = (*szIn==L'<' ? L'l' : L'g');
				*szEsc++ = L't';
				*szEsc++ = L';';
			}
			nInc = 4;
			break;

		case L'&':
			if ((szEsc != 0) && (4 < nCurrLen))
			{
				Checked::memcpy_s(szEsc, nCurrLen*sizeof(wchar_t), L"&amp;", 5*sizeof(wchar_t));
				szEsc+= 5;
			}
			nInc = 5;
			break;

		case L'\'': case L'\"':
			if (dwFlags & ATL_ESC_FLAG_ATTR)
			{
				if ((szEsc != 0) && (5 < nCurrLen))
				{
					Checked::memcpy_s(szEsc, nCurrLen*sizeof(wchar_t), (*szIn == L'\'' ? L"&apos;" : L"&quot;"), 6*sizeof(wchar_t));
					szEsc+= 6;
				}
				nInc = 6;
				break;
			}

		default:
			if ((*szIn >= ATL_HIGH_SURROGATE_START) && (*szIn <= ATL_HIGH_SURROGATE_END))
			{
				if (wchHighSurrogate)
				{
					if ((szEsc != 0) && (7 < nCurrLen))
					{
						_AtlCopyNCR(wchHighSurrogate, szEsc);
						szEsc+= 8;
					}
					nInc = 8;
				}
				wchHighSurrogate = *szIn;
				bHandled = 1;
			}
			if ((!bHandled) && (wchHighSurrogate))
			{
				if ((*szIn >= ATL_LOW_SURROGATE_START) && (*szIn <= ATL_LOW_SURROGATE_END))
				{
					DWORD dwSurrogateChar = (((wchHighSurrogate-0xD800) << 10) + (*szIn - 0xDC00) + 0x10000);
					if ((szEsc != 0) && (9 < nCurrLen))
					{
						_AtlCopyNCRPair(dwSurrogateChar, szEsc);
						szEsc+= 10;
					}
					nInc = 10;
					bHandled = 1;
				}
				else
				{
					if ((szEsc != 0) && (7 < nCurrLen))
					{
						_AtlCopyNCR(wchHighSurrogate, szEsc);
						szEsc+= 8;
					}
					nCurrLen-= 8;
					nCnt+= 8;
				}
				wchHighSurrogate = 0;
			}
			if (!bHandled)
			{
				if ((*szIn < 0x0020) || (*szIn > 0x007E))
				{
					if ((szEsc != 0) && (7 < nCurrLen))
					{
						_AtlCopyNCR(*szIn, szEsc);
						szEsc+= 8;
					}
					nInc = 8;
				}
				else
				{
					if ((szEsc != 0) && (0 < nCurrLen))
					{
						*szEsc++ = *szIn;
					}
					nInc = 1;
				}
			}
		}

		nCurrLen -= nInc;
		nCnt+= nInc;

		szIn++;
	}

	if (wchHighSurrogate != 0)
	{
		if ((wchHighSurrogate < 0x0020) || (wchHighSurrogate > 0x007E))
		{
			if ((szEsc != 0) && (7 < nCurrLen))
			{
				_AtlCopyNCR(wchHighSurrogate, szEsc);
			}
			nCurrLen -= 8;
			nCnt+= 8;
		}
		else
		{
			if ((szEsc != 0) && (0 < nCurrLen))
			{
				*szEsc = wchHighSurrogate;
			}
			nCurrLen--;
			nCnt++;
		}
	}

	if ((szEsc != 0) && (nCurrLen < 0))
	{
		return 0;
	}

	return nCnt;
}

}
