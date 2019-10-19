#include "cicada/core/cicada_engine.h"

#include "cicada/core/cicada_application.h"

# include "cicada/util/iterators/reverse_iterator.hpp"

ccd::cicada_engine::cicada_engine(cicada_application&& p_application, lock)
	: m_application(p_application)
{}

void ccd::cicada_engine::operator()()
{
	this->m_application.startup(*this);

	while (this->m_application.running())
	{
		this->m_application.update(*this);
	}

	auto _it = reverse_iterator<int*>();

	this->m_application.finish(*this);
}
