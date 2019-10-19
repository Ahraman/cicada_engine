#include "cicada/core/cicada_application.h"

using namespace ccd;

cicada_application::~cicada_application()
{}

bool ccd::cicada_application::running() const noexcept
{
	return this->m_running;
}

void ccd::cicada_application::stop() noexcept
{
	this->m_running = false;
}

void ccd::cicada_application::startup(cicada_engine& p_engine)
{
	this->m_running = true;
	
	this->pre_init(p_engine);

	this->init(p_engine);

	this->post_init(p_engine);
}

void ccd::cicada_application::loop(cicada_engine& p_engine)
{
	this->update(p_engine);
}

void ccd::cicada_application::finish(cicada_engine& p_engine)
{
	this->pre_cleanup(p_engine);

	this->cleanup(p_engine);

	this->post_cleanup(p_engine);
}