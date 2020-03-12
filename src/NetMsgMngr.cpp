#include "NetMsgCreateWO.h"
#ifdef AFTR_CONFIG_USE_BOOST

#include <iostream>
#include <sstream>
#include <string>
#include "AftrManagers.h"
#include "Vector.h"
#include "WO.h"
#include "GLView.h"
#include "WorldContainer.h"
#include "NetMsgMngr.h"
#include "GLViewModule4.h"

using namespace Aftr;

NetMsgMacroDefinition(NetMsgMngr);

NetMsgMngr::NetMsgMngr() {

}

NetMsgMngr::~NetMsgMngr() {

}

bool NetMsgMngr::toStream(NetMessengerStreamBuffer& os) const
{
	os << this->id;
	os << this->pos.x;
	os << this->pos.y;
	os << this->pos.z;
	return true;
}

bool NetMsgMngr::fromStream(NetMessengerStreamBuffer& is) {
	is << this->id;
	is << this->pos.x;
	is << this->pos.y;
	is << this->pos.z;
	return true;
}

void onMsgRecieved() {
	GLViewModule4* glView = ((GLViewModule4*)ManagerGLView::getGLView());
	WorldContainer* wc = glView->getWorldContainer();
	glView->GLViewModule4::get_model();
}

std::string NetMsgMngr::toString() const{
	std::stringstream ss;

	ss << NetMsg::toString();
	ss << "Payload: ID = " << this->id << '\n';
	ss << "Payload: Position = {" << this->pos.x << "," << this->pos.z << "}\n";
	return ss.str();
}

#endif