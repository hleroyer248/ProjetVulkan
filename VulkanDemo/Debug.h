#pragma once
class Debug
{
public:

#ifdef NDEBUG
	static constexpr bool enableDebug = false;
#else
	static constexpr bool enableDebug = true;
#endif
};

