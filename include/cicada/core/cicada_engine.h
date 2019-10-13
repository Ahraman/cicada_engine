#ifndef CICADA_CORE_CICADA_ENGINE_HEADER_GUARD
# define CICADA_CORE_CICADA_ENGINE_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

#include "cicada_application.h"

namespace ccd {
	namespace detail {
		struct cicada_engine_lock
		{
		protected:
			struct lock {};
		};
	}

	class cicada_engine
		: public detail::cicada_engine_lock
	{
	public:
		CICADA_API cicada_engine(cicada_application&& p_application, lock);
	private:
		cicada_application& m_application;
	};
}

#endif