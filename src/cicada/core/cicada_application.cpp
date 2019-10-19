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

void ccd::cicada_application::start(cicada_engine& p_engine)
{
	this->m_running = true;
}