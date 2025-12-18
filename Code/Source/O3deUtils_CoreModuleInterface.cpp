
#include <Source/O3deUtils_CoreModuleInterface.h>
#include <AzCore/Memory/Memory.h>

#include <O3deUtils_Core/O3deUtils_CoreTypeIds.h>

#include <Source/O3deUtils_CoreSystemComponent.h>

namespace O3deUtils_Core
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(O3deUtils_CoreModuleInterface,
        "O3deUtils_CoreModuleInterface", O3deUtils_CoreModuleInterfaceTypeId);
    AZ_RTTI_NO_TYPE_INFO_IMPL(O3deUtils_CoreModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(O3deUtils_CoreModuleInterface, AZ::SystemAllocator);

    O3deUtils_CoreModuleInterface::O3deUtils_CoreModuleInterface()
    {
        // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
        // Add ALL components descriptors associated with this gem to m_descriptors.
        // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
        // This happens through the [MyComponent]::Reflect() function.
        m_descriptors.insert(m_descriptors.end(), {
            O3deUtils_CoreSystemComponent::CreateDescriptor(),
            });
    }

    AZ::ComponentTypeList O3deUtils_CoreModuleInterface::GetRequiredSystemComponents() const
    {
        return AZ::ComponentTypeList{
            azrtti_typeid<O3deUtils_CoreSystemComponent>(),
        };
    }
} // namespace O3deUtils_Core
