#pragma once

#include "NetMsg.h"
#include "Vector.h"
#ifdef AFTR_CONFIG_USE_BOOST

namespace Aftr {
	class NetMsgMngr : public NetMsg {
	public:
		NetMsgMacroDeclaration(NetMsgMngr);

		NetMsgMngr();
		virtual ~NetMsgMngr();
		virtual bool toStream(NetMessengerStreamBuffer& os) const;
		virtual bool fromStream(NetMessengerStreamBuffer& is);
		virtual void onMsgRecieved();
		virtual std::string toString() const;

	protected:
		unsigned int id;
		Aftr::Vector pos;

	};
}

#endif