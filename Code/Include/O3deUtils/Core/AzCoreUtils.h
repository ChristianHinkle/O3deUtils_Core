
#pragma once

#include <O3deUtils/Core/O3deUtils_CoreConfiguration.h>
#include <AzCore/Component/Component.h>
#include <type_traits>
#include <CppUtils/Core/Concepts.h>
#include <AzCore/std/string/fixed_string.h>
#include <AzCore/Component/EntityId.h>

namespace AZ
{
    template <typename T>
    class Interface;

    class Entity;
}

namespace O3deUtils
{
    template <class T>
    T& GetInterfaceAsserted();

    template <class T>
    const char* TryGetTypeName();

    template <CppUtils::PointerToDerivedFrom<AZ::Component> TComponentPtr>
    TComponentPtr FindComponent(const AZ::Entity& entity);

    template <CppUtils::ReferenceToDerivedFrom<AZ::Component> TComponentRef>
    TComponentRef FindComponent(const AZ::Entity& entity);

    // @Christian: TODO: [todo] Consider making these inline (instead of dll-exported) and templatize them to return any
    // specialization of `basic_fixed_string`. Although, that may be tricky due to AZStd's `to_string` available overloads.

    O3DEUTILS_CORE_API AZStd::fixed_string<24> EntityIdToString(AZ::EntityId entityId);

    O3DEUTILS_CORE_API AZStd::fixed_string<24> IntegerToString(AZ::u64 num);
    O3DEUTILS_CORE_API AZStd::fixed_string<24> IntegerToString(AZ::s64 num);

    O3DEUTILS_CORE_API AZStd::fixed_string<16> IntegerToString(AZ::u32 num);
    O3DEUTILS_CORE_API AZStd::fixed_string<16> IntegerToString(AZ::s32 num);

    O3DEUTILS_CORE_API AZStd::fixed_string<8> IntegerToString(AZ::u16 num);
    O3DEUTILS_CORE_API AZStd::fixed_string<8> IntegerToString(AZ::s16 num);

    O3DEUTILS_CORE_API AZStd::fixed_string<4> IntegerToString(AZ::u8 num);
    O3DEUTILS_CORE_API AZStd::fixed_string<4> IntegerToString(AZ::s8 num);
} // namespace O3deUtils

#include <O3deUtils/Core/AzCoreUtils.inl>
