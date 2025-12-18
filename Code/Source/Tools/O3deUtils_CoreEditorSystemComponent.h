
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <O3deUtils_CoreSystemComponent.h>

namespace O3deUtils_Core
{
    /// System component for O3deUtils_Core editor
    class O3deUtils_CoreEditorSystemComponent
        : public O3deUtils_CoreSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = O3deUtils_CoreSystemComponent;
    public:
        AZ_COMPONENT_DECL(O3deUtils_CoreEditorSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        O3deUtils_CoreEditorSystemComponent();
        ~O3deUtils_CoreEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace O3deUtils_Core
