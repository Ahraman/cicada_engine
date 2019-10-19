#include "cicada/render/d3d12/d3d12_backend.h"

#ifdef CICADA_OS_WINDOWS

# include <stdexcept> // TODO use my own

ccd::d3d12_backend::d3d12_backend()
{
	if (CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**)&this->m_factory) != S_OK)
		throw std::logic_error("CreateDXGIFactory1"); // TODO do it more robust
}

#endif