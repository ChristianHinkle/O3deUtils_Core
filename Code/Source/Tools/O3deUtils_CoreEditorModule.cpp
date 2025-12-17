
#include <O3deUtils_Core/O3deUtils_CoreTypeIds.h>
#include <O3deUtils_CoreModuleInterface.h>
#include "O3deUtils_CoreEditorSystemComponent.h"

namespace O3deUtils_Core
{
    class O3deUtils_CoreEditorModule
        : public O3deUtils_CoreModuleInterface
    {
    public:
        AZ_RTTI(O3deUtils_CoreEditorModule, O3deUtils_CoreEditorModuleTypeId, O3deUtils_CoreModuleInterface);
        AZ_CLASS_ALLOCATOR(O3deUtils_CoreEditorModule, AZ::SystemAllocator);

        O3deUtils_CoreEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                O3deUtils_CoreEditorSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<O3deUtils_CoreEditorSystemComponent>(),
            };
        }
    };
}// namespace O3deUtils_Core

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME, _Editor), O3deUtils_Core::O3deUtils_CoreEditorModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_O3deUtils_Core_Editor, O3deUtils_Core::O3deUtils_CoreEditorModule)
#endif
