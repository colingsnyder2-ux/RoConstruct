#pragma once

namespace RBX
{
	enum InsertMode
	{
		INSERT_RAW,
		INSERT_TO_TREE,
		INSERT_TO_3D_VIEW
	};

	// NOTE: may not be intended for this file
	enum PromptMode
	{
		ALLOW_PROMPTS,
		SUPPRESS_PROMPTS
	};
}
// 2008-06 native header port of rbxgs App/include/util/InsertMode.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
