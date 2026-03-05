
#include <Source/O3deUtils_CoreModuleInterface.h>
#include <O3deUtils_CoreTypeIds.h>
#include <Source/O3deUtils_CoreSystemComponent.h>

namespace O3deUtils
{
    class O3deUtils_CoreModule : public O3deUtils_CoreModuleInterface
    {
    public:
        AZ_RTTI(O3deUtils_CoreModule, O3deUtils_CoreModuleTypeId, O3deUtils_CoreModuleInterface);
        AZ_CLASS_ALLOCATOR(O3deUtils_CoreModule, AZ::SystemAllocator);

        O3deUtils_CoreModule()
        {
            // Append non-editor items.
            m_descriptors.insert(m_descriptors.end(), {
                }
            );
        }

        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            AZ::ComponentTypeList list = O3deUtils_CoreModuleInterface::GetRequiredSystemComponents();

            // Append non-editor items.
            list.insert(list.end(), {
                azrtti_typeid<O3deUtils_CoreSystemComponent>(),
                }
            );

            return list;
        }
    };
}

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), O3deUtils::O3deUtils_CoreModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_O3deUtils_Core, O3deUtils::O3deUtils_CoreModule)
#endif
