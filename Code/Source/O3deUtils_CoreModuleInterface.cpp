
#include <Source/O3deUtils_CoreModuleInterface.h>

#include <AzCore/Memory/Memory.h>

#include <O3deUtils_CoreTypeIds.h>

#include <Source/O3deUtils_CoreSystemComponent.h>

namespace O3deUtils
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(O3deUtils_CoreModuleInterface, "O3deUtils_CoreModuleInterface", O3deUtils_CoreModuleInterfaceTypeId);
    AZ_RTTI_NO_TYPE_INFO_IMPL(O3deUtils_CoreModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(O3deUtils_CoreModuleInterface, AZ::SystemAllocator);

    O3deUtils_CoreModuleInterface::O3deUtils_CoreModuleInterface()
    {
        // Append all items used by both editor and non-editor targets.
        m_descriptors.insert(m_descriptors.end(), {
            O3deUtils_CoreSystemComponent::CreateDescriptor(),
            }
        );
    }

    AZ::ComponentTypeList O3deUtils_CoreModuleInterface::GetRequiredSystemComponents() const
    {
        // Append all items used by both editor and non-editor targets.
        return AZ::ComponentTypeList{
        };
    }
}
