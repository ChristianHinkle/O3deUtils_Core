
#include <AzCore/Serialization/SerializeContext.h>
#include "O3deUtils_CoreEditorSystemComponent.h"

#include <O3deUtils_Core/O3deUtils_CoreTypeIds.h>

namespace O3deUtils_Core
{
    AZ_COMPONENT_IMPL(O3deUtils_CoreEditorSystemComponent, "O3deUtils_CoreEditorSystemComponent",
        O3deUtils_CoreEditorSystemComponentTypeId, BaseSystemComponent);

    void O3deUtils_CoreEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<O3deUtils_CoreEditorSystemComponent, O3deUtils_CoreSystemComponent>()
                ->Version(0);
        }
    }

    O3deUtils_CoreEditorSystemComponent::O3deUtils_CoreEditorSystemComponent() = default;

    O3deUtils_CoreEditorSystemComponent::~O3deUtils_CoreEditorSystemComponent() = default;

    void O3deUtils_CoreEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("O3deUtils_CoreEditorService"));
    }

    void O3deUtils_CoreEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("O3deUtils_CoreEditorService"));
    }

    void O3deUtils_CoreEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void O3deUtils_CoreEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void O3deUtils_CoreEditorSystemComponent::Activate()
    {
        O3deUtils_CoreSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void O3deUtils_CoreEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        O3deUtils_CoreSystemComponent::Deactivate();
    }

} // namespace O3deUtils_Core
