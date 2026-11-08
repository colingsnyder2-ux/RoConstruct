// Layout probes for the inactive native gui/ScoreHud.h and gui/ChatOutput.h; tests/record_native_hud.py checks each
// function body is `mov eax, imm32; ret` with the value from the binary (allocation sizes passed to new, constructor
// field stores).
#include <stddef.h>
#include "gui/ScoreHud.h"
#include "gui/ChatOutput.h"

struct NativeHudLayout
{
	static size_t scoreHudRunService() { return offsetof(RBX::ScoreHud, runService); }       // 0x14c (006525ce)
	static size_t scoreHudPlayers() { return offsetof(RBX::ScoreHud, players); }             // 0x150 (006525e7)
	static size_t scoreHudSize() { return sizeof(RBX::ScoreHud); }                           // 0x154 (0060236f)
	static size_t chatOutputRunService() { return offsetof(RBX::ChatOutput, runService); }   // 0x14c (0064fbfc)
	static size_t chatOutputPlayers() { return offsetof(RBX::ChatOutput, players); }         // 0x150 (0064fc02)
	static size_t chatOutputFilter() { return offsetof(RBX::ChatOutput, filter); }           // 0x154 (0064fb86)
	static size_t chatOutputFifo() { return offsetof(RBX::ChatOutput, fifo); }               // 0x174 (0064fc14)
	static size_t chatOutputTime() { return offsetof(RBX::ChatOutput, time); }               // 0x194 (0064fc40)
	static size_t chatOutputSize() { return sizeof(RBX::ChatOutput); }                       // 0x198 (006020bf)
	static size_t chatLineUser() { return offsetof(RBX::ChatLine, user); }                   // 0x0c (0065057e)
	static size_t chatLineMessage() { return offsetof(RBX::ChatLine, message); }             // 0x28 (00650592)
	static size_t chatLineDieTime() { return offsetof(RBX::ChatLine, dieTime); }             // 0x44 (006505ab)
	static size_t chatLineProfane() { return offsetof(RBX::ChatLine, profane); }             // 0x48 (006505bc)
	static size_t chatLineSize() { return sizeof(RBX::ChatLine); }                           // 0x4c (00650d98)
};

size_t nativeScoreHudRunService() { return NativeHudLayout::scoreHudRunService(); }
size_t nativeScoreHudPlayers() { return NativeHudLayout::scoreHudPlayers(); }
size_t nativeScoreHudSize() { return NativeHudLayout::scoreHudSize(); }
size_t nativeChatOutputRunService() { return NativeHudLayout::chatOutputRunService(); }
size_t nativeChatOutputPlayers() { return NativeHudLayout::chatOutputPlayers(); }
size_t nativeChatOutputFilter() { return NativeHudLayout::chatOutputFilter(); }
size_t nativeChatOutputFifo() { return NativeHudLayout::chatOutputFifo(); }
size_t nativeChatOutputTime() { return NativeHudLayout::chatOutputTime(); }
size_t nativeChatOutputSize() { return NativeHudLayout::chatOutputSize(); }
size_t nativeChatLineUser() { return NativeHudLayout::chatLineUser(); }
size_t nativeChatLineMessage() { return NativeHudLayout::chatLineMessage(); }
size_t nativeChatLineDieTime() { return NativeHudLayout::chatLineDieTime(); }
size_t nativeChatLineProfane() { return NativeHudLayout::chatLineProfane(); }
size_t nativeChatLineSize() { return NativeHudLayout::chatLineSize(); }
