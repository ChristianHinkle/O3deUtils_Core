
#include <Source/O3deUtils_CoreSystemComponent.h>

#include <O3deUtils_Core/O3deUtils_CoreTypeIds.h>

#include <AzCore/Serialization/SerializeContext.h>

namespace O3deUtils_Core
{
    AZ_COMPONENT_IMPL(O3deUtils_CoreSystemComponent, "O3deUtils_CoreSystemComponent",
        O3deUtils_CoreSystemComponentTypeId);

    void O3deUtils_CoreSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<O3deUtils_CoreSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void O3deUtils_CoreSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("O3deUtils_CoreService"));
    }

    void O3deUtils_CoreSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("O3deUtils_CoreService"));
    }

    void O3deUtils_CoreSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void O3deUtils_CoreSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    O3deUtils_CoreSystemComponent::O3deUtils_CoreSystemComponent()
    {
        if (O3deUtils_CoreInterface::Get() == nullptr)
        {
            O3deUtils_CoreInterface::Register(this);
        }
    }

    O3deUtils_CoreSystemComponent::~O3deUtils_CoreSystemComponent()
    {
        if (O3deUtils_CoreInterface::Get() == this)
        {
            O3deUtils_CoreInterface::Unregister(this);
        }
    }

    void O3deUtils_CoreSystemComponent::Init()
    {
    }

    void O3deUtils_CoreSystemComponent::Activate()
    {
        O3deUtils_CoreRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void O3deUtils_CoreSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        O3deUtils_CoreRequestBus::Handler::BusDisconnect();
    }

    void O3deUtils_CoreSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }

} // namespace O3deUtils_Core
