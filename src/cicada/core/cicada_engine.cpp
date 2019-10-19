#include "cicada/core/cicada_engine.h"

#include "cicada/core/cicada_application.h"

#include <thread> // TODO role out my own library

#include <future> // TODO role out my own library

ccd::cicada_engine::cicada_engine(cicada_application&& p_application, lock)
	: m_application(p_application)
{}

void ccd::cicada_engine::operator()()
{
	this->m_application.start(*this);

	this->m_application.pre_init(*this);
	std::future _ftr = std::async(std::launch::async, [=, &_application = this->m_application]{
		_application.init(*this);
	});

	
}
