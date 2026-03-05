
#pragma once

#include <AzCore/Module/Module.h>
#include <AzCore/Memory/Memory_fwd.h>
#include <AzCore/RTTI/RTTIMacros.h>
#include <AzCore/RTTI/TypeInfoSimple.h>
#include <O3deUtils_CoreConfiguration.h>

namespace O3deUtils
{
    class O3DEUTILS_CORE_API O3deUtils_CoreModuleInterface : public AZ::Module
    {
    public:
        AZ_TYPE_INFO_WITH_NAME_DECL_API(O3DEUTILS_CORE_API, O3deUtils_CoreModuleInterface);
        AZ_RTTI_NO_TYPE_INFO_DECL();
        AZ_CLASS_ALLOCATOR_DECL;

        O3deUtils_CoreModuleInterface();

        AZ::ComponentTypeList GetRequiredSystemComponents() const override;
    };
}
