
#pragma once

#include <AzCore/PlatformDef.h>

#if defined(AZ_MONOLITHIC_BUILD)
#   define O3DEUTILS_CORE_API
#else
#   if defined(O3DEUTILS_CORE_EXPORTS)
#       define O3DEUTILS_CORE_API AZ_DLL_EXPORT
#   else
#       define O3DEUTILS_CORE_API AZ_DLL_IMPORT
#   endif
#endif
