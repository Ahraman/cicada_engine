#ifndef CICADA_CORE_CICADA_STARTUP_HEADER_GUARD
# define CICADA_CORE_CICADA_STARTUP_HEADER_GUARD (1)

# include "cicada/core/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "cicada_application.h"

namespace ccd {
	// TODO use concepts
	template<typename Application>
	struct cicada_startup
		: detail::cicada_engine_lock
	{
		using application_type = Application;

		template<typename... Params>
		constexpr cicada_engine operator()(Params... p_params) const
		{
			cicada_engine _engine(application_type(p_params...), {});
			return _engine;
		}
	};
}

#endif