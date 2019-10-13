#include "cicada/core/cicada_engine.h"

using namespace ccd;

cicada_engine::cicada_engine(cicada_application&& p_application, lock)
	: m_application(p_application)
{}