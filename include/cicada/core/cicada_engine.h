#ifndef CICADA_CORE_CICADA_ENGINE_HEADER_GUARD
# define CICADA_CORE_CICADA_ENGINE_HEADER_GUARD (1)

# include "cicada/core/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

namespace ccd {
	class cicada_application;

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
		CICADA_CORE_API cicada_engine(cicada_application&& p_application, lock);

		CICADA_CORE_API void operator()();
	private:
		cicada_application& m_application;
	};
}

#endif