#ifndef CICADA_CORE_CICADA_APPLICATION_HEADER_GUARD
# define CICADA_CORE_CICADA_APPLICATION_HEADER_GUARD (1)

# include "cicada/core/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "cicada_engine.h"

namespace ccd {
	class cicada_application
	{
	public:
		CICADA_CORE_API virtual ~cicada_application();
		
		CICADA_NODISCARD CICADA_CORE_API bool running() const noexcept;
		CICADA_NODISCARD CICADA_CORE_API void stop() noexcept;

		virtual void start(cicada_engine& p_engine);

		virtual void pre_init(cicada_engine& p_engine) = 0;
		virtual void init(cicada_engine& p_engine) = 0;
		virtual void post_init(cicada_engine& p_engine) = 0;
		
		virtual void update(cicada_engine& p_engine) = 0;

		virtual void cleanup(cicada_engine& p_engine) = 0;
	private:
		bool m_running;
	};
}

#endif