
#include <Source/O3deUtils_CoreModuleInterface.h>
#include <O3deUtils_CoreTypeIds.h>
#include <Source/Tools/O3deUtils_CoreEditorSystemComponent.h>

namespace O3deUtils
{
    class O3deUtils_CoreEditorModule : public O3deUtils_CoreModuleInterface
    {
    public:
        AZ_RTTI(O3deUtils_CoreEditorModule, O3deUtils_CoreEditorModuleTypeId, O3deUtils_CoreModuleInterface);
        AZ_CLASS_ALLOCATOR(O3deUtils_CoreEditorModule, AZ::SystemAllocator);

        O3deUtils_CoreEditorModule()
        {
            // Append editor-only items.
            m_descriptors.insert(m_descriptors.end(), {
                O3deUtils_CoreEditorSystemComponent::CreateDescriptor(),
                }
            );
        }

        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            AZ::ComponentTypeList list = O3deUtils_CoreModuleInterface::GetRequiredSystemComponents();

            // Append editor-only items.
            list.insert(list.end(), {
                azrtti_typeid<O3deUtils_CoreEditorSystemComponent>(),
                }
            );

            return list;
        }
    };
}

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME, _Editor), O3deUtils::O3deUtils_CoreEditorModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_O3deUtils_Core_Editor, O3deUtils::O3deUtils_CoreEditorModule)
#endif
