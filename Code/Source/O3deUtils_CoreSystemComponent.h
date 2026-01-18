
#pragma once

#include <AzCore/Component/Component.h>
#include <AzCore/Component/TickBus.h>
#include <O3deUtils_Core/O3deUtils_CoreBus.h>
#include <O3deUtils_Core/O3deUtils_CoreConfiguration.h>

namespace O3deUtils_Core
{
    class O3DEUTILS_CORE_API O3deUtils_CoreSystemComponent
        : public AZ::Component
        , protected O3deUtils_CoreRequestBus::Handler
        , public AZ::TickBus::Handler
    {
    public:
        AZ_COMPONENT_DECL_API(O3DEUTILS_CORE_API, O3deUtils_CoreSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        O3deUtils_CoreSystemComponent();
        ~O3deUtils_CoreSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // O3deUtils_CoreRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZTickBus interface implementation
        void OnTick(float deltaTime, AZ::ScriptTimePoint time) override;
        ////////////////////////////////////////////////////////////////////////
    };

} // namespace O3deUtils_Core
