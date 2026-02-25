
#pragma once

#include <O3deUtils/Core/O3deUtils_CoreConfiguration.h>
#include <AzCore/Component/Component.h>
#include <type_traits>
#include <CppUtils/Core/Concepts.h>
#include <AzCore/std/string/fixed_string.h>
#include <AzCore/Component/EntityId.h>
#include <CppUtils/Misc/String.h>

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

    //! @brief A fixed string type with the necessary capacity to represent any number of the integer type in the decimal number system.
    template <StdReimpl::integral TInteger>
    using IntFixedStringDecimal = AZStd::fixed_string<CppUtils::GetIntegerStringMaxSizeDec<TInteger>()>;

    // @Christian: TODO: [todo] Templatize these to return any specialization of `basic_fixed_string`. Although, that may
    // be tricky due to AZStd's `to_string` available overloads.

    inline IntFixedStringDecimal<AZ::u64> EntityIdToString(AZ::EntityId entityId);

    template <StdReimpl::integral TInteger>
    IntFixedStringDecimal<TInteger> IntegerToString(TInteger num);
} // namespace O3deUtils

#include <O3deUtils/Core/AzCoreUtils.inl>
