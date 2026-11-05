#include "gui/Gui.h"
#include "gui/ProfanityFilter.h"
#include "Network/Players.h"

namespace RBX
{
	class ChatLine
	{
	public:
		G3D::Color3 userColor;
		std::string user;
		std::string message;
		float dieTime;
		bool profane;

	public:
		ChatLine(Network::Player*, const std::string&, float);
		ChatLine(const std::string&, const std::string&, float);
	};

	class ChatOutput : public GuiItem,
					   public Listener<Network::Players, Network::ChatMessage>,
					   public Listener<RunService, Heartbeat>
	{
	private:
		RunService* runService;
		Network::Players* players;
		ProfanityFilter filter;
		std::deque<ChatLine*> fifo;
		float time;

	private:
		void removeOldest();
		void frontIsOld();
		bool ParseCommand(Network::ChatMessage);
		virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*);
		virtual void onEvent(const Network::Players*, Network::ChatMessage);
		virtual void onEvent(const RunService*, Heartbeat);
		virtual void render2d(Adorn*);
	public:
		ChatOutput();
		virtual ~ChatOutput();
	};
}
