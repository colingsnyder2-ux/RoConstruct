// from server: 100% by Intel
// from server: 95% by EspClaude
// roc 2007-08 00600470  unit: RBX::BlockBlockContact  size: 552 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00600470
//
// 00600470  83ec10               sub esp, 0x10
// 00600473  53                   push ebx
// 00600474  55                   push ebp
// 00600475  56                   push esi
// 00600476  57                   push edi
// 00600477  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0060047b  8b4708               mov eax, dword ptr [edi + 8]
// 0060047e  8bf1                 mov esi, ecx
// 00600480  50                   push eax
// 00600481  8d4c2414             lea ecx, [esp + 0x14]
// 00600485  51                   push ecx
// 00600486  8bce                 mov ecx, esi
// 00600488  e82351f5ff           call 0x5555b0
// 0060048d  8bc8                 mov ecx, eax
// 0060048f  e83c4ff5ff           call 0x5553d0
// 00600494  8ad8                 mov bl, al
// 00600496  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 0060049c  83f803               cmp eax, 3
// 0060049f  0f87c6010000         ja 0x60066b
// 006004a5  ff248588066000       jmp dword ptr [eax*4 + 0x600688]
// 006004ac  84db                 test bl, bl
// 006004ae  0f8490000000         je 0x600544
// 006004b4  8b16                 mov edx, dword ptr [esi]
// 006004b6  8b427c               mov eax, dword ptr [edx + 0x7c]
// 006004b9  8bce                 mov ecx, esi
// 006004bb  ffd0                 call eax
// 006004bd  84c0                 test al, al
// 006004bf  751f                 jne 0x6004e0
// 006004c1  8b442424             mov eax, dword ptr [esp + 0x24]
// 006004c5  33c9                 xor ecx, ecx
// 006004c7  5f                   pop edi
// 006004c8  898efc000000         mov dword ptr [esi + 0xfc], ecx
// 006004ce  5e                   pop esi
// 006004cf  5d                   pop ebp
// 006004d0  c70001000000         mov dword ptr [eax], 1
// 006004d6  894804               mov dword ptr [eax + 4], ecx
// 006004d9  5b                   pop ebx
// 006004da  83c410               add esp, 0x10
// 006004dd  c20800               ret 8
// 006004e0  8b07                 mov eax, dword ptr [edi]
// 006004e2  83e803               sub eax, 3
// 006004e5  742e                 je 0x600515
// 006004e7  83e802               sub eax, 2
// 006004ea  8b442424             mov eax, dword ptr [esp + 0x24]
// 006004ee  c70001000000         mov dword ptr [eax], 1
// 006004f4  c7400400000000       mov dword ptr [eax + 4], 0
// 006004fb  0f857b010000         jne 0x60067c
// 00600501  5f                   pop edi
// 00600502  c786fc00000001000000 mov dword ptr [esi + 0xfc], 1
// 0060050c  5e                   pop esi
// 0060050d  5d                   pop ebp
// 0060050e  5b                   pop ebx
// 0060050f  83c410               add esp, 0x10
// 00600512  c20800               ret 8
// 00600515  8b16                 mov edx, dword ptr [esi]
// 00600517  8b4270               mov eax, dword ptr [edx + 0x70]
// 0060051a  57                   push edi
// 0060051b  8bce                 mov ecx, esi
// 0060051d  c786fc00000002000000 mov dword ptr [esi + 0xfc], 2
// 00600527  ffd0                 call eax
// 00600529  8b442424             mov eax, dword ptr [esp + 0x24]
// 0060052d  5f                   pop edi
// 0060052e  5e                   pop esi
// 0060052f  5d                   pop ebp
// 00600530  c70001000000         mov dword ptr [eax], 1
// 00600536  c7400400000000       mov dword ptr [eax + 4], 0
// 0060053d  5b                   pop ebx
// 0060053e  83c410               add esp, 0x10
// 00600541  c20800               ret 8
// 00600544  8b442424             mov eax, dword ptr [esp + 0x24]
// 00600548  33c9                 xor ecx, ecx
// 0060054a  5f                   pop edi
// 0060054b  898efc000000         mov dword ptr [esi + 0xfc], ecx
// 00600551  5e                   pop esi
// 00600552  5d                   pop ebp
// 00600553  8908                 mov dword ptr [eax], ecx
// 00600555  894804               mov dword ptr [eax + 4], ecx
// 00600558  5b                   pop ebx
// 00600559  83c410               add esp, 0x10
// 0060055c  c20800               ret 8
// 0060055f  8b07                 mov eax, dword ptr [edi]
// 00600561  83e803               sub eax, 3
// 00600564  74c3                 je 0x600529
// 00600566  83e801               sub eax, 1
// 00600569  7442                 je 0x6005ad
// 0060056b  83e801               sub eax, 1
// 0060056e  0f85f7000000         jne 0x60066b
// 00600574  84db                 test bl, bl
// 00600576  751a                 jne 0x600592
// 00600578  8b16                 mov edx, dword ptr [esi]
// 0060057a  8b426c               mov eax, dword ptr [edx + 0x6c]
// 0060057d  57                   push edi
// 0060057e  8bce                 mov ecx, esi
// 00600580  ffd0                 call eax
// 00600582  f6d8                 neg al
// 00600584  1bc0                 sbb eax, eax
// 00600586  83e0fd               and eax, 0xfffffffd
// 00600589  83c003               add eax, 3
// 0060058c  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 00600592  8b442424             mov eax, dword ptr [esp + 0x24]
// 00600596  5f                   pop edi
// 00600597  5e                   pop esi
// 00600598  5d                   pop ebp
// 00600599  c70001000000         mov dword ptr [eax], 1
// 0060059f  c7400400000000       mov dword ptr [eax + 4], 0
// 006005a6  5b                   pop ebx
// 006005a7  83c410               add esp, 0x10
// 006005aa  c20800               ret 8
// 006005ad  8b16                 mov edx, dword ptr [esi]
// 006005af  8b4274               mov eax, dword ptr [edx + 0x74]
// 006005b2  33ed                 xor ebp, ebp
// 006005b4  57                   push edi
// 006005b5  8bce                 mov ecx, esi
// 006005b7  89aefc000000         mov dword ptr [esi + 0xfc], ebp
// 006005bd  ffd0                 call eax
// 006005bf  84db                 test bl, bl
// 006005c1  7421                 je 0x6005e4
// 006005c3  8b16                 mov edx, dword ptr [esi]
// 006005c5  8b4268               mov eax, dword ptr [edx + 0x68]
// 006005c8  57                   push edi
// 006005c9  8bce                 mov ecx, esi
// 006005cb  ffd0                 call eax
// 006005cd  8b442424             mov eax, dword ptr [esp + 0x24]
// 006005d1  5f                   pop edi
// 006005d2  5e                   pop esi
// 006005d3  896804               mov dword ptr [eax + 4], ebp
// 006005d6  5d                   pop ebp
// 006005d7  c70002000000         mov dword ptr [eax], 2
// 006005dd  5b                   pop ebx
// 006005de  83c410               add esp, 0x10
// 006005e1  c20800               ret 8
// 006005e4  8b442424             mov eax, dword ptr [esp + 0x24]
// 006005e8  5f                   pop edi
// 006005e9  5e                   pop esi
// 006005ea  8928                 mov dword ptr [eax], ebp
// 006005ec  896804               mov dword ptr [eax + 4], ebp
// 006005ef  5d                   pop ebp
// 006005f0  5b                   pop ebx
// 006005f1  83c410               add esp, 0x10
// 006005f4  c20800               ret 8
// 006005f7  8b07                 mov eax, dword ptr [edi]
// 006005f9  83e803               sub eax, 3
// 006005fc  0f8427ffffff         je 0x600529
// 00600602  83e801               sub eax, 1
// 00600605  742d                 je 0x600634
// 00600607  83e801               sub eax, 1
// 0060060a  755f                 jne 0x60066b
// 0060060c  8b442424             mov eax, dword ptr [esp + 0x24]
// 00600610  f6db                 neg bl
// 00600612  5f                   pop edi
// 00600613  c70001000000         mov dword ptr [eax], 1
// 00600619  c7400400000000       mov dword ptr [eax + 4], 0
// 00600620  1bdb                 sbb ebx, ebx
// 00600622  83c303               add ebx, 3
// 00600625  899efc000000         mov dword ptr [esi + 0xfc], ebx
// 0060062b  5e                   pop esi
// 0060062c  5d                   pop ebp
// 0060062d  5b                   pop ebx
// 0060062e  83c410               add esp, 0x10
// 00600631  c20800               ret 8
// 00600634  8b16                 mov edx, dword ptr [esi]
// 00600636  8b4274               mov eax, dword ptr [edx + 0x74]
// 00600639  33ed                 xor ebp, ebp
// 0060063b  57                   push edi
// 0060063c  8bce                 mov ecx, esi
// 0060063e  89aefc000000         mov dword ptr [esi + 0xfc], ebp
// 00600644  ffd0                 call eax
// 00600646  84db                 test bl, bl
// 00600648  749a                 je 0x6005e4
// 0060064a  8b16                 mov edx, dword ptr [esi]
// 0060064c  8b4268               mov eax, dword ptr [edx + 0x68]
// 0060064f  57                   push edi
// 00600650  8bce                 mov ecx, esi
// 00600652  ffd0                 call eax
// 00600654  8b442424             mov eax, dword ptr [esp + 0x24]
// 00600658  5f                   pop edi
// 00600659  5e                   pop esi
// 0060065a  896804               mov dword ptr [eax + 4], ebp
// 0060065d  5d                   pop ebp
// 0060065e  c70001000000         mov dword ptr [eax], 1
// 00600664  5b                   pop ebx
// 00600665  83c410               add esp, 0x10
// 00600668  c20800               ret 8
// 0060066b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0060066f  c70000000000         mov dword ptr [eax], 0
// 00600675  c7400400000000       mov dword ptr [eax + 4], 0
// 0060067c  5f                   pop edi
// 0060067d  5e                   pop esi
// 0060067e  5d                   pop ebp
// 0060067f  5b                   pop ebx
// 00600680  83c410               add esp, 0x10
// 00600683  c20800               ret 8
// 00600686  8bff                 mov edi, edi
// 00600688  ac                   lodsb al, byte ptr [esi]
// 00600689  0460                 add al, 0x60
// 0060068b  00ac0460005f05       add byte ptr [esp + eax + 0x55f0060], ch
// 00600692  60                   pushal 
// 00600693  00f7                 add bh, dh

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
namespace G3D { class Vector2int16 { public: short x, y; }; }
namespace RBX {
class GuiTarget;
class Rect {
public:
	float lx, ly, hx, hy;
	bool pointInRect(G3D::Vector2int16 point);
};
class UIEvent {
public:
	enum EventType { NO_EVENT, MOUSE_RIGHT_BUTTON_DOWN, MOUSE_RIGHT_BUTTON_UP, MOUSE_LEFT_BUTTON_DOWN, MOUSE_LEFT_BUTTON_UP, MOUSE_MOVE };
	EventType eventType;
	void* userInput;
	G3D::Vector2int16 mousePosition;
	G3D::Vector2int16 mouseDelta;
	G3D::Vector2int16 windowSize;
};
class GuiEvent : public UIEvent { public: void* iDataState; };
class GuiResponse {
	enum ResponseType { NOT_USED, USED, USED_AND_FINISHED };
	ResponseType response;
	GuiTarget* target;
	GuiResponse(ResponseType response) : response(response), target(0) {}
public:
	static GuiResponse notUsed() { return GuiResponse(NOT_USED); }
	static GuiResponse used() { return GuiResponse(USED); }
	static GuiResponse finished() { return GuiResponse(USED_AND_FINISHED); }
};
class Widget {
public:
	enum WidgetState { NOTHING, HOVER, DOWN_OVER, DOWN_AWAY };
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
	virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25();
	virtual void onClick(const GuiEvent& event);
	virtual bool onDrag(const GuiEvent& event);
	virtual void onDown(const UIEvent& event);
	virtual void onUp(const UIEvent& event);
	virtual void v29();
	virtual bool isEnabled();
	char pad[0xfc - 4];
	WidgetState widgetState;
	Rect getMyRect() const;
	GuiResponse processMouse(const GuiEvent& event);
};

	GuiResponse Widget::processMouse(const GuiEvent& event)
	{
		bool inWidget = getMyRect().pointInRect(event.mousePosition);

		switch (widgetState)
		{
		case NOTHING:
		case HOVER:
			if (inWidget)
			{
				if (!isEnabled())
				{
					widgetState = NOTHING;
					return GuiResponse::used();
				}

				switch (event.eventType)
				{
				case GuiEvent::MOUSE_LEFT_BUTTON_DOWN:
					widgetState = DOWN_OVER;
					onDown(event);
					return GuiResponse::used();

				case GuiEvent::MOUSE_MOVE:
					widgetState = HOVER;
					return GuiResponse::used();
					
				default:
					return GuiResponse::used();
				}
			}
			else
			{
				widgetState = NOTHING;
				return GuiResponse::notUsed();
			}

		case DOWN_OVER:
			switch (event.eventType)
			{
			case GuiEvent::MOUSE_LEFT_BUTTON_DOWN:
				return GuiResponse::used();

			case GuiEvent::MOUSE_LEFT_BUTTON_UP:
				widgetState = NOTHING;
				onUp(event);

				if (inWidget)
				{
					onClick(event);
					return GuiResponse::finished();
				}
				else
				{
					return GuiResponse::notUsed();
				}

			case GuiEvent::MOUSE_MOVE:
				if (!inWidget)
					widgetState = onDrag(event) ? NOTHING : DOWN_AWAY;

				return GuiResponse::used();
			}
			break;

		case DOWN_AWAY:
			switch (event.eventType)
			{
			case GuiEvent::MOUSE_LEFT_BUTTON_DOWN:
				return GuiResponse::used();

			case GuiEvent::MOUSE_LEFT_BUTTON_UP:
				widgetState = NOTHING;
				onUp(event);

				if (inWidget)
				{
					onClick(event);
					return GuiResponse::used();
				}
				else
				{
					return GuiResponse::notUsed();
				}

			case GuiEvent::MOUSE_MOVE:
				widgetState = inWidget ? DOWN_OVER : DOWN_AWAY;
				return GuiResponse::used();
			}

		}
		return GuiResponse::notUsed();
	}
}
