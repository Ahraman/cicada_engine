#ifndef CICADA_RENDER_D3D12_RENDER_BACKEND_HEADER_GUARD
# define CICADA_RENDER_D3D12_RENDER_BACKEND_HEADER_GUARD (1)

# include "cicada/render/d3d12/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# ifdef CICADA_OS_WINDOWS

#  include <dxgi1_6.h>

namespace ccd {
	class d3d12_backend
	{
	public:
		d3d12_backend();
	private:
		IDXGIFactory1* m_factory;
	};
}

# endif

#endif