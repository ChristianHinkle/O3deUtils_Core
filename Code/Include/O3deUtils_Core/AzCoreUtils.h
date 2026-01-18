
#pragma once

#include <AzCore/Component/Component.h>
#include <type_traits>
#include <CppUtils_Core/Concepts.h>

namespace AZ
{
    template <typename T>
    class Interface;

    class Entity;
}

namespace O3deUtils::Core::AzCoreUtils
{
    template <class T>
    T& GetInterfaceAsserted();

    template <class T>
    const char* TryGetTypeName();

    template <CppUtils::Core::Concepts::PointerToDerivedFrom<AZ::Component> TComponentPtr>
    TComponentPtr FindComponent(const AZ::Entity& entity);

    template <CppUtils::Core::Concepts::ReferenceToDerivedFrom<AZ::Component> TComponentRef>
    TComponentRef FindComponent(const AZ::Entity& entity);
} // namespace O3deUtils::Core::AzCoreUtils

#include <O3deUtils_Core/AzCoreUtils.inl>
