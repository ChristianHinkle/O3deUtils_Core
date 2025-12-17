
#pragma once

#include <O3deUtils_Core/AzCoreUtils.h>

#include <AzCore/Interface/Interface.h>
#include <AzCore/Debug/Trace.h>
#include <AzCore/Console/ILogger.h>
#include <AzCore/RTTI/TypeInfo.h>
#include <AzCore/RTTI/TypeInfoSimple.h>
#include <AzCore/std/string/string_view.h>
#include <AzCore/Component/Entity.h>

template <class T>
T& O3deUtils::Core::AzCoreUtils::GetInterfaceAsserted()
{
    T* interface = AZ::Interface<T>::Get();

#if AZ_ENABLE_TRACING
    {
        AZStd::fixed_string<128> assertString;

        assertString += '`';
        assertString += __func__;
        assertString += "`: ";
        assertString += "The interface for `";
        assertString += TryGetTypeName<T>();
        assertString += "` is currently null!";

        AZ_Assert(interface, assertString.data());
    }
#endif // #if AZ_ENABLE_TRACING

    return *interface;
}

template <class T>
const char* O3deUtils::Core::AzCoreUtils::TryGetTypeName()
{
    if constexpr (AZ::Internal::HasAzTypeInfo_v<T>)
    {
        return AZ::AzTypeInfo<T>::Name();
    }
    else
    {
        AZStd::fixed_string<128> logString;

        logString += '`';
        logString += __func__;
        logString += "`: ";
        logString += "No type info defined. I.e., it does not use an `AZ_TYPE_INFO` macro.";

        AZLOG_WARN(logString.data());

        return "(no type info defined)";
    }
}

template <CppUtils::Concepts::PointerToDerivedFrom<AZ::Component> TComponentPtr>
TComponentPtr O3deUtils::Core::AzCoreUtils::FindComponent(const AZ::Entity& entity)
{
    using ComponentType = std::remove_pointer_t<TComponentPtr>;

    return entity.FindComponent<ComponentType>();
}

template <CppUtils::Concepts::ReferenceToDerivedFrom<AZ::Component> TComponentRef>
TComponentRef O3deUtils::Core::AzCoreUtils::FindComponent(const AZ::Entity& entity)
{
    using ComponentType = std::remove_reference_t<TComponentRef>;

    ComponentType* foundComponent = entity.FindComponent<ComponentType>();

#if AZ_ENABLE_TRACING
    {
        AZStd::fixed_string<256> logString;

        logString += "Component not found on entity '";
        logString += entity.GetName();
        logString += "'. Use the pointer type overload of this function if the component is optional to exist on the entity.";

        AZ_Assert(foundComponent, logString.data());
    }
#endif // #if AZ_ENABLE_TRACING

    return *foundComponent;
}
