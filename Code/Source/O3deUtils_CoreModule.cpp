
#include <O3deUtils_Core/O3deUtils_CoreTypeIds.h>
#include <Source/O3deUtils_CoreModuleInterface.h>
#include <Source/O3deUtils_CoreSystemComponent.h>

namespace O3deUtils_Core
{
    class O3deUtils_CoreModule
        : public O3deUtils_CoreModuleInterface
    {
    public:
        AZ_RTTI(O3deUtils_CoreModule, O3deUtils_CoreModuleTypeId, O3deUtils_CoreModuleInterface);
        AZ_CLASS_ALLOCATOR(O3deUtils_CoreModule, AZ::SystemAllocator);
    };
}// namespace O3deUtils_Core

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), O3deUtils_Core::O3deUtils_CoreModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_O3deUtils_Core, O3deUtils_Core::O3deUtils_CoreModule)
#endif
